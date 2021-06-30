#ifndef NIMBLEGUI_BUTTON_H
#define NIMBLEGUI_BUTTON_H

#include "BaseElement.h"
#include <exception>

class Button : public BaseElement {
public:
    typedef void (*myAction)(Button*);
    myAction action;

    Button(Vector2 size, Vector2 pos, Color color);

    void render() override;
    bool inArea(Vector2 mousePos) override;
    bool isClicked(Vector2 mousePos, bool isMouseDown);
    void addAction(myAction action);
};


#endif //NIMBLEGUI_BUTTON_H
