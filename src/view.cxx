#include "view.hxx"
#include "character.hxx"
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;
static ge211::Color const background_day_color {255, 255, 255};
static ge211::Color const background_night_color {12, 20, 69};


View::View(Model const& model)
        : model_(model),
          scoretitle_(),
          gameover_(),
          background_day_sprite({800,800}, background_day_color),
          background_night_sprite({800,800},background_night_color),
          duck_sprite(ge211::Image_sprite("rock.png")),
          moon_sprite("moon.png"),
          sun_sprite("sun.png"),
          cloud_sprite("cloud.png"),
          cloud_sprite1("cloud.png")

{ }

void
View::draw(ge211::Sprite_set& set)
{

    if (model_.get_live() == false){
        if(model_.get_state()){
            ge211::Text_sprite::Builder gameover_build(sans28_);
            gameover_build.color(ge211::Color(250, 250, 250));
            gameover_build << "Game Over!!!!! Final Score: "
                            << model_.get_score();
            gameover_.reconfigure(gameover_build);
            set.add_sprite(gameover_, {200, 200},2);
        }

    }
    else{
        for (auto& character: model_.get_characters()) {
            set.add_sprite(character.get_sprite(),
                           character.get_position().into<int>(),
                           2,character.get_transform());
        }
        if (model_.get_duck()){
            set.add_sprite(duck_sprite,{50,300},3,ge211::Transform()
            .set_scale(0.14));
        }
        if(model_.get_day()%2==0){
            set.add_sprite(sun_sprite, {600,50}, 0,ge211::Transform()
                    .set_scale(0.14));
            set.add_sprite(cloud_sprite1, {100,100}, 0);
            set.add_sprite(cloud_sprite, {200,60}, 0);
            set.add_sprite(background_day_sprite, {0,0}, -1);

            ge211::Text_sprite::Builder explain_builder(sans28_);
            explain_builder.color(ge211::Color(0, 0, 0));
            explain_builder << "Score: "
                            << model_.get_score();
            scoretitle_.reconfigure(explain_builder);
            set.add_sprite(scoretitle_, {0, 0},1);

        } else{
            set.add_sprite(background_night_sprite, {0,0}, -1);
            set.add_sprite(moon_sprite, {600,0}, 0);

            ge211::Text_sprite::Builder explain_builder(sans28_);
            explain_builder.color(ge211::Color(255, 255, 255));
            explain_builder << "Score: "
                            << model_.get_score();
            scoretitle_.reconfigure(explain_builder);
            set.add_sprite(scoretitle_, {0, 0},1);
        }
        //fix night time colors.

    }

}

