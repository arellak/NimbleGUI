#include "Input.h"

std::vector<Rectangle*> Input::ui_collision;
std::vector<Gui::Window*> Input::windows;
Gui::ElementBase* Input::focused;
Rectangle* Input::focusedRect;

bool Input::dragging = false;

Vector2 offset{};

// in this method the actual dragging is happening
void Input::dragElement(Vector2 mousePos) {
    // should the current element be dragged?(dragging=true) and is the focused element even visible?
    if(dragging && focused->visible) {
        // save the mousePosition
        Vector2 mouse{mousePos.x - offset.x, mousePos.y - offset.y};

        // set the position of the focused element to the newly calculated mouse position
        focused->pos = mouse;

        // check if there is focusedRectangle
        if(focusedRect != nullptr) {
            // if there is, update its position
            focusedRect->x = mouse.x;
            focusedRect->y = mouse.y;
        }

        // cast the focused element to a panel
        auto* panel = dynamic_cast<Gui::Panel*>(focused);

        // check if the cast succeeded
        if(panel != nullptr) {
            // update the position of the titlebar to the newly calculated mousePos
            panel->titleBar->pos = panel->pos;

            // go over each child of the panel
            for(auto &child : panel->elements) {
                // cast the child to a button
                auto *button = dynamic_cast<Gui::Button*>(child);

                // check if the cast succeeded
                if(button != nullptr) {
                    // update the buttons position relative to its parent panel
                    button->pos = Vector2{
                        (panel->pos.x + button->offset.x),
                        (panel->pos.y + button->offset.y)
                    };

                    // also update the position of the label of the button
                    // button->text.pos = button->pos;
                    button->text.pos.x = button->pos.x + (button->text.dimension.x/5);
                    button->text.pos.y = button->pos.y + (button->text.dimension.y/5);
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
        // iterate over each rectangle in the ui_collision vector
        for(auto &element : ui_collision) {
            // save the position of the current element in a 2D Vector
            Vector2 elementPos{element->x, element->y};

            // get the current element by its position and save in a temporary variable
            auto* tmp = Gui::getElementByPos(elementPos);
            // cast the temporary variable to a panel pointer
            auto* panel = dynamic_cast<Gui::Panel*>(tmp);

            // check if the cast to the panel was successfull
            if(panel != nullptr) {
                // two bools that check if the mouseclick hits the titlebar
                bool inX = (mousePos.x <= panel->titleBar->pos.x + panel->titleBar->dimension.x) && (mousePos.x >= panel->titleBar->pos.x);
                bool inY = (mousePos.y <= panel->titleBar->pos.y) && (mousePos.y >= panel->titleBar->pos.y - panel->titleBar->dimension.y);

                // check if inX and inY are true
                if(inX && inY) {
                    // set the focused ElementBase* to the temporary object because that is our currently focused object
                    focused = tmp;
                    // also get the focusedRect by its position
                    focusedRect = getRectangleByPos(elementPos);

                    // set the dragging variable to true, so we can drag the object to another position
                    dragging = true;

                    // set the offset so the panel doesnt jump to your mousePosition when you click the titlebar
                    offset = {mousePos.x - focused->pos.x, mousePos.y - focused->pos.y};
                }

                // go over each child of the panel
                for(auto &child : panel->elements) {
                    // cast the child to a button pointer
                    auto* button = dynamic_cast<Gui::Button*>(child);

                    // check if the child actually have been casted to a button pointer
                    if(button != nullptr) {
                        // two bools that hold values, if the mouseClick was in the area of a button
                        bool inButtonX = (mousePos.x <= button->pos.x + button->dimension.x) && (mousePos.x > button->pos.x);
                        bool inButtonY = (mousePos.y <= button->pos.y + button->dimension.y) && (mousePos.y > button->pos.y);

                        // check if the click was in the area of a button
                        if(inButtonX && inButtonY) {
                            // call the action method of the button, the parameter is the button itself
                            button->action(button);
                            // change the focused element to the button
                            focused = button;
                            // there is no dragging involved, so the the dragging variable should be false
                            dragging = false;
                        }
                    }
                }

            } else {
                // the clicked element was no panel? set the dragging variable to false
                dragging = false;
            }

        }
    } else {
        // if you click/release and there is focused element, it should be set to nullptr/reset itself
        // and the dragging variable is also set to false, because there is no dragging if there is no focused element
        focused = nullptr;
        dragging = false;
    }
}