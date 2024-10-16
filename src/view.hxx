#pragma once

#include "model.hxx"
#include <ge211.hxx>
#include <string>

using Color = ge211::Color;
static ge211::Color const day_color {255, 255, 255};



class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);



private:
    Model const& model_;
    ge211::Text_sprite scoretitle_;
    ge211::Text_sprite gameover_;
    ge211::Font sans28_{"sans.ttf", 18};
    ge211::Rectangle_sprite const background_day_sprite;
    ge211::Rectangle_sprite const background_night_sprite;
    ge211::Image_sprite const duck_sprite;
    ge211::Image_sprite const moon_sprite;
    ge211::Image_sprite const sun_sprite;
    ge211::Image_sprite const cloud_sprite;
    ge211::Image_sprite const cloud_sprite1;

};
