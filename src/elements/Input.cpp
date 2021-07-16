#include "Input.h"

std::vector<Rectangle*> Input::ui_collision;
std::vector<Gui::Window*> Input::windows;
Gui::ElementBase* Input::focused;
Rectangle* Input::focusedRect;

bool Input::dragging = false;

float offsetX = 0;
float offsetY = 0;

void Input::dragElement(Vector2 mousePos) {
    if(dragging) {
        float mouseX = mousePos.x - offsetX;
        float mouseY = mousePos.y - offsetY;

        focused->pos = Vector2{mouseX, mouseY};

        if(focusedRect != nullptr) {
            focusedRect->x = mouseX;
            focusedRect->y = mouseY;
        }

        auto* panel = dynamic_cast<Gui::Panel*>(focused);
        if(panel != nullptr) {
            panel->titleBar->pos = Vector2{mouseX, mouseY};

            for(auto &element : panel->elements) {
                auto *button = dynamic_cast<Gui::Button*>(element);

                if(button != nullptr) {
                    button->pos = Vector2{
                        (panel->pos.x + button->offset.x),
                        (panel->pos.y + button->offset.y)
                    };

                    button->text.pos = Vector2{button->pos.x, button->pos.y};
                }
            }
        }
    }
}

Rectangle* Input::getRectangleByPos(Vector2 &pos) {
    for(auto &rect : ui_collision) {
        bool inX = (pos.x <= rect->x + rect->width) && (pos.x >= rect->x);
        bool inY = (pos.y <= rect->y + rect->height) && (pos.y >= rect->y);

        if(inX && inY) {
            return rect;
        }
    }
    return nullptr;
}

void Input::registerContainer(Gui::Window *window) {
    windows.push_back(window);
}

void Input::handle(){
    Vector2 mousePos = GetMousePosition();
    if(IsMouseButtonPressed(0)){
        checkCollisions(mousePos);
    }
    if(IsMouseButtonDown(0)) {
        /** Could be combined inside checkCollisions, but can stand on its own; Since, in order to being able to drag
         * the element needs to be in focus anyway it doesn't require any Parameters, since focussed Widget is already saved
         */
        dragElement(mousePos);
    } else if(IsMouseButtonReleased(0)) {
        focused = nullptr;
        dragging = false;
    }
}

void Input::registr(Gui::ElementBase &element) {
    auto* rect = new Rectangle();
    rect->x = element.pos.x;
    rect->y = element.pos.y;
    rect->width = element.dimension.x;
    rect->height = element.dimension.y;

    ui_collision.push_back(rect);
}

void Input::checkCollisions(Vector2 mousePos){
    /** Check if MouseClick is hitting a UI Element or Window and if so focus it / throw their or in general Events **/

    if(focused == nullptr) {
        for(auto &element : ui_collision) {
            Vector2 elementPos{element->x, element->y};

            auto* tmp = Gui::getElementByPos(elementPos);
            auto* panel = dynamic_cast<Gui::Panel*>(tmp);

            if(panel != nullptr) {
                bool inX = (mousePos.x <= panel->titleBar->pos.x + panel->titleBar->dimension.x) && (mousePos.x >= panel->titleBar->pos.x);
                bool inY = (mousePos.y <= panel->titleBar->pos.y) && (mousePos.y >= panel->titleBar->pos.y - panel->titleBar->dimension.y);

                if(inX && inY) {
                    focused = tmp;
                    focusedRect = getRectangleByPos(elementPos);

                    dragging = true;
                    offsetX = mousePos.x - focused->pos.x;
                    offsetY = mousePos.y - focused->pos.y;
                }
            } else {
                dragging = false;
            }
        }
    } else {
        focused = nullptr;
        dragging = false;
    }
}