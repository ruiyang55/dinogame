#pragma once

#include <ge211.hxx>

#include "character.hxx"

class Model
{
public:
    // Constructor(s)
    Model();

    // Getters/Setters
    // Implemented in place if they're really simple (one liners)
    std::vector<Character> const& get_characters() const { return characters_; }

    // Public interface
    int const& get_score() const {
        return score_;
    }
    int const& get_day() const {
        return day_;
    }
    bool const& get_live() const {
        return live_;
    }
    bool const& get_state() const {
        return gameover_;
    }
    bool const& get_duck() const {
        return duck_;
    }
    void soft_reset();
    void on_frame(double dt);
    void duck();
    void jump();
    void start();


private:
    // Data members
    std::vector<Character> characters_;
    int score_ = 0;
    int daycounter_ = 0;
    int day_=0;
    bool live_ = false;
    bool gameover_= false;
    bool duck_ = false;

};
