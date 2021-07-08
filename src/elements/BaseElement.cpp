#include "BaseElement.h"

BaseElement::BaseElement(Vector2 size, Vector2 pos, Color color) {
    this->size = size;
    this->pos = pos;
    this->color = color;
}

void BaseElement::init() {

}

void BaseElement::render() {
    Rectangle rec{pos.x, pos.y, size.x, size.y};
    DrawRectangleRec(rec, color);
}

void BaseElement::update(Vector2 pos) {
    this->pos.x += pos.x;
    this->pos.y += pos.y;
}

void BaseElement::update(Vector2 pos, Vector2 size) {
    update(pos);
    this->size.x += size.x;
    this->size.y += size.y;
}


bool BaseElement::inArea(Vector2 mousePos) {
    float mouseX = mousePos.x;
    float mouseY = mousePos.y;

    bool isInX = mouseX > pos.x && mouseX < pos.x + size.x;
    bool isInY = mouseY > pos.y && mouseY < pos.y + size.y;

    return isInX && isInY;
}
void Gui::renderElements() {

}
