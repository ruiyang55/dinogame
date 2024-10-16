#pragma once

#include <ge211.hxx>

#include <string>
#include <queue>

class Character
{
public:
    // Constructor(s)
    Character(std::vector<std::string> const& image_filenames,
              ge211::Posn<float> const& initial_position,
              ge211::Transform const& transform);

    // Getters/Setters
    // Implemented in place if they're really simple (one liners)
    //void set_position(ge211::Posn<float> position) {
    //    position_ = position;
    //}
    ge211::Posn<int> const& get_position() const {
        return position_;
    }
    ge211::Image_sprite const& get_sprite() const {
        return sprite_;
    }
    ge211::Transform const& get_transform() const {
        return transform_;
    }
    // Public interface
    void update(double dt);
    Character next(double dt) const;
    Character cactusnext(double dt) const;
    void jump();
    void dinosaur_jump_up();
    void dinosaur_jump_down();
    void dinosaur_jump_recover();
    void is_cactus();
    void cactus_reset();
    void dinosaur_duck_down();
    void snorlax_reset();
    void dinosaur_duck_recover();
    bool get_jump(){
        return jump_;
    }
    void speedup(int score);
    bool collision(Character target);
    bool scollision(Character snorlax);


private:

    // Private helpers


    
    // Data members
    ge211::Image_sprite sprite_;
    ge211::Posn<int> position_;
    unsigned int image_index_;
    double duration_;
    std::vector<ge211::Image_sprite> images_;
    double dy_;
    double dx_;
    bool jump_;
    ge211::Transform transform_;
    double multiplier_;
    bool duck_;

};
