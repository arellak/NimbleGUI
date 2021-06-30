#include "Button.h"

Button::Button(Vector2 size, Vector2 pos, Color color) : BaseElement(size, pos, color) {
    this->action = [](Button *button) {}; // default action so the program doesn't crash when there is no user defined action
}

void Button::render() {
    BaseElement::render();
}

bool Button::inArea(Vector2 mousePos) {
    return BaseElement::inArea(mousePos);
}

bool Button::isClicked(Vector2 mousePos, bool isMouseDown) {
    if(isMouseDown && inArea(mousePos)) {
        if(action != nullptr) {
            action(this);
            return true;
        }
    }

    return false;
}

void Button::addAction(Button::myAction action) {
    this->action = action;
}
