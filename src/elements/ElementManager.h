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

    void render() {
        renderElements();
        renderButtons();
    }

    Button &createButton(Vector2 size, Vector2 pos, Color color) {
        Button tempButton(size, pos, color);
        addButton(tempButton);
        return buttons.at(buttons.size()-1);
    }

    void triggerClickEvents(Vector2 mousePos, bool mouseIsPressed, bool mouseIsRealeased) {
        for (auto &button : buttons) {
            button.isClicked(mousePos, mouseIsPressed, mouseIsRealeased);
        }
    }

}

#endif //NIMBLEGUI_ELEMENTMANAGER_H
