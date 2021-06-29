//
// Created by rocketman on 27/06/2021.
//

#ifndef NIMBLEGUI_ELEMENTMANAGER_H
#define NIMBLEGUI_ELEMENTMANAGER_H

#include "Button.h"
#include <vector>

namespace ElementManager {

    std::vector<BaseElement> elements;
    std::vector<Button> buttons;

    void addButton(Button &element) {
        buttons.push_back(element);
    }

    void addElement(BaseElement &element) {
        elements.push_back(element);
    }

    void renderButtons() {
        for(auto &button : buttons) {
            button.render();
        }
    }

    void renderElements() {
        for(auto &element : elements) {
            element.render();
        }
    }

    void renderAll() {
        renderElements();
        renderButtons();
    }

    void createButton(Vector2 size, Vector2 pos, Color color, ClickEvent &event) {
        Button tempButton(size, pos, color, event);
        addButton(tempButton);
    }

    void triggerClickEvents(Vector2 mousePos, bool mouseIsDown) {
        for(auto &button : buttons) {
            button.isClicked(mousePos, mouseIsDown);
        }
    }

}

#endif //NIMBLEGUI_ELEMENTMANAGER_H
