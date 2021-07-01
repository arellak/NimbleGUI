#include "Button.h"

Button::Button(Vector2 size, Vector2 pos, Color color) : BaseElement(size, pos, color) {
    this->clickAction = [](Button *button) {}; // default action so the program doesn't crash when there is no user defined action
    this->releaseAction = [](Button *button) {};
    this->font = LoadFont("resources/Monoid.ttf");
    this->text = "";
    this->fontSize = 20;
}

void Button::render() {
    BaseElement::render();
    DrawTextEx(this->font, this->text.c_str(), this->pos, this->fontSize, 1, BLACK);
}

bool Button::inArea(Vector2 mousePos) {
    return BaseElement::inArea(mousePos);
}


void Button::isClicked(Vector2 mousePos, bool mouseIsPressed, bool mouseIsReleased) {
    if(mouseIsPressed && inArea(mousePos) && clickAction != nullptr) {
        clickAction(this);
    } else if(mouseIsReleased && inArea(mousePos)) {
        releaseAction(this);
    }
}

void Button::addAction(Button::actionOnClick clickAction = [](Button *button){}, Button::actionOnRelease releaseAction = [](Button *button){}) {
    this->clickAction = clickAction;
    this->releaseAction = releaseAction;
}

void Button::addOnClickAction(Button::actionOnClick onClickAction) {
    this->clickAction = clickAction;
}

void Button::addOnReleaseAction(Button::actionOnRelease onReleaseAction) {
    this->releaseAction = releaseAction;
}

bool Button::checkColor(Color newColor) {
    char oldA = this->color.a;
    char oldR = this->color.r;
    char oldG = this->color.g;
    char oldB = this->color.b;

    char newA = newColor.a;
    char newR = newColor.r;
    char newG = newColor.g;
    char newB = newColor.b;

    return (oldA == newA) && (oldR == newR) && (oldG == newG) && (oldB == newB);
}

Vector2 Button::TextWidth() {
    if(text.empty() || fontSize == 0) {
        return {};
    }
    Vector2 measureText = MeasureTextEx(this->font, this->text.c_str(), this->fontSize, 1);
    return measureText;
}

void Button::setText(std::string text, int fontSize) {
    this->text = text;
    this->fontSize = fontSize;
}
