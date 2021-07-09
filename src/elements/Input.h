#ifndef NIMBLEGUI_INPUT_H
#define NIMBLEGUI_INPUT_H

#include <vector>
#include "BaseElement.h"

class Input {
public:
    std::vector<Rectangle*> ui_collision;
    Gui::ElementBase* focused;
    bool dragging = false;

    void registerContainer(Gui::Window* window);
    void registr();
    void handle();
    void dragElement();
    void checkCollisions();
};


#endif //NIMBLEGUI_INPUT_H
