#ifndef NIMBLEGUI_INPUT_H
#define NIMBLEGUI_INPUT_H

#include <vector>
#include <memory>
#include "BaseElement.h"

namespace Input {
    extern std::vector<Rectangle*> ui_collision;
    extern std::vector<Gui::Window*> windows;
    extern Gui::ElementBase* focused;
    extern bool dragging;

    void registerContainer(Gui::Window* window);
    void registr(Gui::ElementBase &element);
    void handle();
    void dragElement();
    void checkCollisions();
}


#endif //NIMBLEGUI_INPUT_H
