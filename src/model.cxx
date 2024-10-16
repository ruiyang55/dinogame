#include "model.hxx"
#include "character.hxx"

Model::Model()
    : characters_(),
      score_()
{
    std::vector<std::string> eevee_files;
    for (int i=0; i<8; i++) {
        std::string filename = "eeveeAnimatedTransparent-";
        filename += std::to_string(i);
        filename += ".png";
        eevee_files.push_back(filename);
        //std::cout << filename << "\n";
    }

    Character eevee(eevee_files, {50, 300},ge211::Transform().set_scale(1.0));

    characters_.push_back(eevee);

    std::vector<std::string> pokeball_files;
    pokeball_files.push_back("teamrocket1.png");
    Character pokeball(pokeball_files,{1000,284},ge211::Transform().set_scale
    (0.5));
    characters_.push_back(pokeball);


    std::vector<std::string> snorlaxfiles;
    snorlaxfiles.push_back("snorlax.png");
    Character snorlax(snorlaxfiles,{700,154},ge211::Transform().set_scale(1));
    characters_.push_back(snorlax);

}


void Model::on_frame(double dt)
{


    if (live_ == true) {
        score_ +=1;
        daycounter_+=1;
        if (daycounter_==600){
            day_++;
            daycounter_=0;
        }
        characters_[1].is_cactus();
        characters_[2].is_cactus();
        for (Character& character : characters_) {
            character.update(dt);
            if (score_%100 == 1){
                character.speedup(score_);
            }
        }
        characters_[1] = characters_[1].cactusnext(dt);
        characters_[0] = characters_[0].next(dt);
        if(score_>500){
            characters_[2] = characters_[2].cactusnext(dt);
        }
        if (characters_[0].get_jump() == true){
            //characters_[0] = characters_[0].next(dt);
            if (characters_[0].next(dt).get_position().y < 50) {
                characters_[0].dinosaur_jump_down();
                characters_[0] = characters_[0].next(dt);
            }
            if (characters_[0].get_position().y > 300) {
                characters_[0].dinosaur_jump_recover();
                characters_[0]= characters_[0].next(dt);
            }
        }
        if(characters_[1].get_position().x<0){
            characters_[1].cactus_reset();
        }

        if (characters_[0].collision(characters_[1])){
            live_=false;
            gameover_=true;
        }
        if (characters_[0].scollision(characters_[2])&&duck_==false){
            live_=false;
            gameover_=true;
        }
        else if (characters_[0].scollision(characters_[2])&&duck_==true){
            characters_[2].snorlax_reset();
        }

    }
}
void Model::soft_reset()
{
    gameover_=false;
    live_=true;
    characters_[1].cactus_reset();
    characters_[2].snorlax_reset();
}
void Model::duck()
{
    duck_=true;
}

void Model::jump()
{
    duck_=false;
    characters_[0].jump();
    characters_[0].dinosaur_jump_up();

}
void Model::start()
{
    live_ = true;
    gameover_= true;
}
