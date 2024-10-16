#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}

void Controller::on_key(ge211::Key key){
    if (key == ge211::Key::code(' ')||(key == ge211::Key::up())) {
        if(model_.get_live()==false){
            model_.soft_reset();
            model_.start();
        }
        model_.jump();
    }

    else if (key == ge211::Key::down()){
        model_.duck();
    }
}

void Controller::on_mouse_down(ge211::Mouse_button button)
{
    model_.duck();
}

void Controller::on_mouse_up(ge211::Mouse_button btn){
    if(btn != ge211::Mouse_button::left) return;
}
