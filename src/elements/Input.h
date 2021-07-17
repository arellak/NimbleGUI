#ifndef NIMBLEGUI_INPUT_H
#define NIMBLEGUI_INPUT_H

#include <vector>
#include "BaseElement.h"

namespace Input {
    extern std::vector<Rectangle*> ui_collision;
    extern std::vector<Gui::Window*> windows;
    extern Gui::ElementBase* focused;
    extern Rectangle* focusedRect;
    extern bool dragging;

    Rectangle* getRectangleByPos(Vector2 &pos);

    void registerContainer(Gui::Window* window);
    void registr(Gui::ElementBase &element);
    void handle(void);
    void dragElement(Vector2 mousePos);
    void checkCollisions(Vector2 mousePos);
}


#endif //NIMBLEGUI_INPUT_H
