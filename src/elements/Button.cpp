//
// Created by rocketman on 28/06/2021.
//

#include "Button.h"

Button::Button(Vector2 size, Vector2 pos, Color color, ClickEvent &clickEvent) : BaseElement(size, pos, color),
                                                                                 clickEvent(clickEvent) {

}

void Button::render() {
    BaseElement::render();
}

bool Button::inArea(Vector2 mousePos) {
    return BaseElement::inArea(mousePos);
}

void Button::addClick(ClickEvent &event) {
    clickEvent = event;
}

bool Button::isClicked(Vector2 mousePos, bool isMouseDown) {
    if(isMouseDown && inArea(mousePos)) {
        clickEvent.onClick();
        return true;
    }

    return false;
}
