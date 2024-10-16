#include "character.hxx"

#include <string>
#include <cmath>

Character::Character(std::vector<std::string> const& image_filenames,
                     ge211::Posn<float> const& initial_position,
                     ge211::Transform const& transform)
    : sprite_(image_filenames[0]),
      position_(initial_position),
      image_index_(0),
      duration_(0.0),
      images_(),
      dy_(0),
      dx_(0),
      jump_(false),
      transform_(transform),
      multiplier_(1.0),
      duck_(false)


{
    for (std::string filename : image_filenames) {
        images_.push_back(ge211::sprites::Image_sprite(filename));
    }
}

void Character::update(double dt) {
    // Get direction to destination
    // Displacement / magnitude = Unit direction vector

    //if (!stopped) {
    if (duck_==false){
        duration_ += dt*(multiplier_*multiplier_);
        if (duration_ > (1.0/images_.size())) {
            duration_ = 0;

            // move to the next image
            image_index_++;
            if (image_index_ >= images_.size()) {
                image_index_ = 0;
            }
            sprite_ = images_[image_index_];
        }
    }



}


Character Character::next(double dt) const{
    Character result(*this);
    result.position_.y += (dy_) * (dt*2);
    return result;
}

Character Character::cactusnext(double dt) const{
    Character result(*this);
    result.position_.x += (dx_) * (dt);
    return result;
}

void Character::jump(){
    jump_=true;
}
void Character::dinosaur_jump_up()
{

    dy_ = -300;
}

void Character::dinosaur_jump_down()
{
    dy_ = 300;
}

void Character::dinosaur_jump_recover()
{
    dy_ = 0;
    jump_ = false;
}
void Character::is_cactus(){
    dx_= -400;
}
void Character::cactus_reset()
{

    dx_-= 50;
    double random = rand() % 100 + 1000;
    position_.x=random;
}
void Character::dinosaur_duck_down()
{
    duck_ = true;
}

void Character::snorlax_reset()
{
    dx_-= 30;
    double random = rand() % 1000 + 1000;
    position_.x=random;
}

void Character::dinosaur_duck_recover()
{
    dy_ = 0;
}

void Character::speedup(int score)
{
    multiplier_+= 10;
}

bool Character::collision(Character target){

    return (position_.down_by(89).y > target.position_.y && position_
    .right_by(103).x >target.position_.x);

}

bool Character::scollision(Character snorlax)
{
    return(position_.right_by(103).x>snorlax.position_.x);
}