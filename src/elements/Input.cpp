#include "Input.h"

std::vector<Rectangle*> Input::ui_collision;
std::vector<Gui::Window*> Input::windows;
Gui::ElementBase* Input::focused;
bool Input::dragging = false;


void Input::dragElement() {
    if(focused != nullptr) {
        Vector2 mousePos = GetMousePosition();
        focused->pos.x = mousePos.x;
        focused->pos.y = mousePos.y;
    }
}

void Input::registerContainer(Gui::Window *window) {
    windows.push_back(window);
}

void Input::handle(){
    if(IsMouseButtonPressed(0)){
        checkCollisions();
    }
    if(IsMouseButtonPressed(0)) {
        /** Could be combined inside checkCollisions, but can stand on its own; Since, in order to being able to drag
         * the element needs to be in focus anyway it doesn't require any Parameters, since focussed Widget is already saved
         */

    }
    dragElement();
}

void Input::registr(Gui::ElementBase &element) {
    Rectangle* rect = new Rectangle();
    rect->x = element.pos.x;
    rect->y = element.pos.y;
    rect->width = element.dimension.x;
    rect->height = element.dimension.y;

    ui_collision.push_back(rect);
}

void Input::checkCollisions(){
    /** Check if MouseClick is hitting a UI Element or Window and if so focus it / throw their or in general Events **/
    Vector2 mousePos = GetMousePosition();
    for(auto &element : ui_collision) {
        if(((mousePos.x < element->x + element->width) && (mousePos.x > element->x))
            && ((mousePos.y < element->y + element->height) && (mousePos.y > element->y))) {
            Vector2 elementPos{element->x, element->y};
            Gui::ElementBase* newFocus = Gui::getElementByPos(elementPos);
            if(focused == newFocus) {
                focused = nullptr;
            } else {
               focused = newFocus;
            }
        }
    }
}