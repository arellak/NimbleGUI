#include "BaseElement.h"

Gui::ElementBase::ElementBase() {
    dimension = Vector2{50, 50};
    pos = Vector2{0, 0};

    color = BLACK;
    visible = true;
    type = ElementType::BASE;
}

Gui::Panel::Panel(float x, float y) {
    pos = Vector2{x, y};
    hasBorders = false;
    borderColor = WHITE;
    type = ElementType::PANEL;
}

Gui::Panel::Panel(Vector2 pos) {
    Panel(pos.x, pos.y);
}

/* TODO write method where borderColor can be updated? */
void Gui::Panel::update(Vector2 pos) {
    this->pos.x += pos.x;
    this->pos.y += pos.y;
}

Gui::Label::Label(const char *text) {
    Label(0, 0);
    this->text = text;
}

Gui::Label::Label(float x, float y) {
    pos = Vector2{x, y};
    text = "Label";
    textSize = 20;
    type = ElementType::LABEL;
}

Gui::Label::Label(float x, float y, const char *text) {
    Label(x, y);
    this->text = text;
}

Gui::Label::Label(Vector2 pos) {
    Label(pos.x, pos.y);
}

void Gui::Label::update(Vector2 pos) {
    this->pos.x += pos.x;
    this->pos.y += pos.y;
}

Gui::Button::Button(Vector2 pos) {
    type = ElementType::BUTTON;
    text = "";
    this->pos = pos;
}

Gui::Button::Button(Vector2 pos, Vector2 dimension) {
    type = ElementType::BUTTON;
    text = "";
    this->pos = pos;
    this->dimension = dimension;
}

bool Gui::Button::checkColor(Color newColor) {
    unsigned char oldR = this->color.r;
    unsigned char oldG = this->color.g;
    unsigned char oldB = this->color.b;

    unsigned char newR = newColor.r;
    unsigned char newG = newColor.g;
    unsigned char newB = newColor.b;

    return (oldR == newR) && (oldG == newG) && (oldB == newB);
}

Gui::DropDown::DropDown(Vector2 pos) : Button(pos) {
    unfolded = false;
    type = ElementType::DROP_DOWN;
}

Gui::DropDown::DropDown(Vector2 pos, Vector2 dimension) : Button(pos, dimension) {
    unfolded = false;
    type = ElementType::DROP_DOWN;
}

void Gui::DropDown::addElement(const char* value) {
    Button tempButton(Vector2{}, Vector2{});
    tempButton.text.text = value;
    elements.push_back(&tempButton);
}

Gui::Window::Window(float x, float y) {
    pos = Vector2{x, y};
    type = ElementType::WINDOW;
}

Gui::Window::Window(Vector2 pos) {
    Window(pos.x, pos.y); 
}

void Gui::Window::addElement(ElementBase* element) {
    // TODO set the the childs position relative to windows position
    element->pos.x += pos.x;
    element->pos.y += pos.y;
    elements.push_back(element);
}

void Gui::Window::updateElements() {
    // TODO Update idk?
    for(auto element : elements) {
        element->update(); // TODO add parameter
    }
}

void Gui::Window::update(Vector2 pos) {
    this->pos = pos;
    updateElements();
}


/* ------------------------------------------------ */
void Gui::initialise() {
    textFont = LoadFont("resources/fonts/Monoid.ttf"); // TODO load font from some kind of config?
}

Gui::Panel* Gui::createPanel(int x, int y, int width, int height) {
    Panel* p = new Panel((float) x, (float) y);
    p->dimension = Vector2{(float) width, (float) height};
    Input::registr(p);
    return p;
}

void Gui::renderElements() {
    for(auto &element : elements) {

    }
}
