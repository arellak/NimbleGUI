#include "Button.h"

Button::Button(Vector2 size, Vector2 pos, Color color) : BaseElement(size, pos, color) {
    this->clickAction = [](Button *button) {}; // default action so the program doesn't crash when there is no user defined action
    this->releaseAction = [](Button *button) {}; // default action so the program doesn't crash when there is no user defined action
    this->font = LoadFont("resources/fonts/Monoid.ttf");
    this->text = "";
    this->fontSize = 20;
}

Button::Button(Vector2 size, Vector2 pos, Color color, std::string fontName) : BaseElement(size, pos, color) {
    std::string fontPath("resources/fonts/");
    fontPath.append(fontName);
    this->font = LoadFont(fontPath.c_str());
}

void Button::init() {
    BaseElement::init();
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
    } else if(mouseIsReleased && inArea(mousePos) && releaseAction != nullptr) {
        releaseAction(this);
    }
}

void Button::addAction(Button::actionOnClick onClickAction = [](Button *button){}, Button::actionOnRelease onReleaseAction = [](Button *button){}) {
    this->clickAction = onClickAction;
    this->releaseAction = onReleaseAction;
}

void Button::addOnClickAction(Button::actionOnClick onClickAction) {
    this->clickAction = onClickAction;
}

void Button::addOnReleaseAction(Button::actionOnRelease onReleaseAction) {
    this->releaseAction = onReleaseAction;
}

/**
 *
 * @param newColor
 * @return Given color is the same as the color of the button
 */
bool Button::checkColor(Color newColor) {
    unsigned char oldA = this->color.a;
    unsigned char oldR = this->color.r;
    unsigned char oldG = this->color.g;
    unsigned char oldB = this->color.b;

    unsigned char newA = newColor.a;
    unsigned char newR = newColor.r;
    unsigned char newG = newColor.g;
    unsigned char newB = newColor.b;

    return (oldA == newA) && (oldR == newR) && (oldG == newG) && (oldB == newB);
}

Vector2 Button::TextSize() {
    if(this->text.empty() || this->fontSize == 0) {
        return {};
    }
    Vector2 measureText = MeasureTextEx(this->font, this->text.c_str(), this->fontSize, 1);
    return measureText;
}

/**
 *
 * @param txt
 * @return Vector2 for the measurements of the given text
 */
Vector2 Button::TextSize(std::string &txt) {
    if(this->text.empty() || this->fontSize == 0) {
        return {};
    }
    Vector2 measureText = MeasureTextEx(this->font, txt.c_str(), this->fontSize, 1);
    return measureText;
}

/**
 * Specifies the text that should be shown and the fontsize
 * @param text Text to be shown
 * @param fontSize Size of the font
 */
void Button::setText(std::string text, int fontSize) {
    this->text = text;
    this->fontSize = fontSize;
    cutText();
}

/**
 * Checks if the given text is in the area of the button
 * @return
 */
bool Button::textInArea() {
    Vector2 textSize = TextSize(this->text);
    return (textSize.x < this->size.x) && (textSize.y < this->size.y);
}

/**
 * Checks if a given string is in the area of the button
 * @param txt
 * @return Text fits in Area
 */
bool Button::textInArea(std::string txt) {
    Vector2 textSize = TextSize(txt);
    return (textSize.x < this->size.x) && (textSize.y < this->size.y);
}

/**
 * Cuts shown text if it is too big for the area
 * @return nothing
 */
void Button::cutText() {
    if(textInArea()) return;

    std::string newText;
    for(auto i = 1; i < this->text.size(); i++) {
        newText = this->text.substr(0, this->text.size()-i);

        if(textInArea(newText)) {
            this->text = newText;
            break;
        }

        if(i == this->text.size()-1) {
            this->text = "...";
            this->fontSize = 20;
        }
    }
}

void Button::centerText() {
    
}