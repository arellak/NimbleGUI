//
// Created by rocketman on 28/06/2021.
//

#ifndef NIMBLEGUI_BUTTON_H
#define NIMBLEGUI_BUTTON_H

#include "BaseElement.h"
#include "events/ClickEvent.h"

class Button : public BaseElement{
public:
    ClickEvent &clickEvent;

    Button(Vector2 size, Vector2 pos, Color color, ClickEvent &clickEvent);
    void render() override;
    void addClick(ClickEvent &event);
    bool inArea(Vector2 mousePos) override;
    bool isClicked(Vector2 mousePos, bool isMouseDown);
};


#endif //NIMBLEGUI_BUTTON_H
