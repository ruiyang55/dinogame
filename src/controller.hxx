#pragma once

#include "model.hxx"
#include "view.hxx"
#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;
    void on_frame(double dt) override;
    void on_key(ge211::Key) override;
    void on_mouse_down(ge211::events::Mouse_button button);
    void on_mouse_up(ge211::Mouse_button btn);

private:
    Model model_;
    View view_;
};
