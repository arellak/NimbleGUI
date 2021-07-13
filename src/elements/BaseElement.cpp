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

Gui::Panel::Panel(Vector2 pos) : Panel(pos.x, pos.y){

}

void Gui::Panel::update() {

}

Gui::Label::Label(float x, float y, const char *text) {
    pos = Vector2{x, y};
    text = "Label";
    textSize = 20;
    type = ElementType::LABEL;
    this->text = text;
}

Gui::Label::Label(Vector2 pos, const char* text) : Label(pos.x, pos.y, text){

}

void Gui::Label::update() {

}

Gui::Button::Button(Vector2 pos, Vector2 dimension) {
    type = ElementType::BUTTON;
    text = Label(pos, ""); // TODO do something idk
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

void Gui::Button::update() {

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

Gui::Window::Window(float width, float height, const char* title) {
    dimension = Vector2{width, height};
    pos = Vector2{0, 0};
    type = ElementType::WINDOW;
    this->title = title;
    hasBorders = false;
    borderColor = BLACK;

    InitWindow((int) dimension.x, (int) dimension.y, title);
    SetTargetFPS(25);

}

Gui::Window::Window(Vector2 pos, const char* title) : Window(pos.x, pos.y, title) {

}

void Gui::Window::addElement(ElementBase* element) {
    element->pos.x += pos.x;
    element->pos.y += pos.y;
    elements.push_back(element);
}

void Gui::Window::updateElements() {
    for(auto &element : elements) {
        element->update();
    }
}

void Gui::Window::update() {

    updateElements();
}


/* ------------------------------------------------ */
void Gui::initialise() {
    textFont = LoadFont("resources/fonts/Monoid.ttf"); // TODO load font from some kind of config?
}

Gui::Panel* Gui::createPanel(int x, int y, int width, int height) {
    std::shared_ptr<Panel> panel = std::make_shared<Panel>((float) x, (float) y);
    panel->dimension = Vector2{(float) width, (float) height};
    // Input::registr(panel.get());
    return panel.get();
}

void Gui::renderElements() {
    for(auto &element : elements) {
        // TODO idk? the rendering already happens in the updateElements method
    }
}