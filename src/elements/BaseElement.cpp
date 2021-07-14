#include "BaseElement.h"
#include "Input.h"

Font Gui::textFont;
std::vector<Gui::ElementBase*> Gui::elements;

Gui::ElementBase::ElementBase(void) {
    dimension = Vector2{50, 50};
    pos = Vector2{0, 0};

    color = BLACK;
    visible = true;
    type = ElementType::BASE;
}

Gui::Panel::Panel(float x, float y) : ElementBase(){
    pos = Vector2{x, y};
    hasBorders = false;
    borderColor = WHITE;
    type = ElementType::PANEL;
}

Gui::Panel::Panel(Vector2 pos) : Panel(pos.x, pos.y){

}

void Gui::Panel::update(void) {

}

Gui::Label::Label(const char* text) : Label(0, 0, text){
}

Gui::Label::Label(float x, float y, const char *text) : ElementBase() {
    pos = Vector2{x, y};
    text = "Label";
    textSize = 20;
    type = ElementType::LABEL;
    this->text = text;
}

Gui::Label::Label(Vector2 pos, const char* text) : Label(pos.x, pos.y, text){

}

void Gui::Label::update(void) {
    DrawTextEx(textFont, text, pos, (float) textSize, 1, color);
}

Gui::Button::Button(Vector2 pos, Vector2 dimension) : ElementBase() {
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

void Gui::Button::update(void) {

}

Gui::DropDown::DropDown(Vector2 pos, Vector2 dimension) : Button(pos, dimension) {
    unfolded = false;
    type = ElementType::DROP_DOWN;
}

Gui::DropDown::~DropDown(void) {
    for(auto &element : elements) {
        free(element);
    }
}

void Gui::DropDown::addElement(const char* value) {
    Button tempButton(Vector2{}, Vector2{});
    tempButton.text.text = value;
    elements.push_back(&tempButton);
}

void Gui::DropDown::update(void) {

}

Gui::Window::Window(float width, float height, const char* title) {
    dimension = Vector2{width, height};
    pos = Vector2{0, 0};
    type = ElementType::WINDOW;
    this->title = title;
    hasBorders = false;
    borderColor = BLACK;
    color = DARKGRAY;

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

void Gui::Window::updateElements(void) {
    for(auto &element : elements) {
        element->update();
    }
}

void Gui::Window::update(void) {
    ClearBackground(color);
    updateElements();
}

void Gui::Window::close(void) {
    CloseWindow();
}


/* ------------------------------------------------ */
void Gui::initialise(void) {
    textFont = LoadFont("resources/fonts/Monoid.ttf"); // TODO load font from some kind of config?
}

Gui::Panel* Gui::createPanel(int x, int y, int width, int height) {
    auto* panel = new Panel((float) x, (float) y);
    panel->dimension = Vector2{(float) width, (float) height};
    Input::registr(*panel);
    return panel;
}

Gui::Window* Gui::createWindow(int width, int height, const char* title) {
    // std::shared_ptr<Window> window = std::make_shared<Window>(width, height, title);
    Window* window = new Window((float) width, (float) height, title);
    Input::registerContainer(window);
    return window;
}

void Gui::renderElements(void) {
    /*
    for(auto &element : elements) {

    }
    */
}

void Gui::cleanUp(void) {
    for(auto &element : elements) {
        free(element);
    }
}