#ifndef NIMBLEGUI_ELEMENTMANAGER_H
#define NIMBLEGUI_ELEMENTMANAGER_H

#include "Button.h"
#include "DropDown.h"
#include <vector>

namespace ElementManager {

    std::vector<BaseElement> elements;
    std::vector<Button> buttons;
    std::vector<DropDown> dropDowns;

    void addButton(Button &element) {
        buttons.push_back(element);
    }

    void addElement(BaseElement &element) {
        elements.push_back(element);
    }

    void addDropDown(DropDown &element) {
        dropDowns.push_back(element);
    }

    void renderDropDowns() {
        for(auto &dropDown : dropDowns) {
            dropDown.render();
        }
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
        renderDropDowns();
    }

    void cleanButtons() {
        for(auto &element : buttons) {
            element.clean();
        }
    }

    void cleanDropDowns() {
        for(auto &element : dropDowns) {
            element.clean();
        }
    }

    void clean() {
        cleanButtons();
        cleanDropDowns();
    }

    Button &createButton(Vector2 size, Vector2 pos, Color color, std::string fontName = "Monoid.ttf") {
        Button tempButton(size, pos, color, fontName);
        addButton(tempButton);
        return buttons.at(buttons.size()-1);
    }

    DropDown &createDropDown(Vector2 size, Vector2 pos, Color color, std::string fontName = "Monoid.ttf") {
        DropDown tempDropDown(size, pos, color, fontName);
        addDropDown(tempDropDown);
        return dropDowns.at(dropDowns.size()-1);
    }

    void triggerClickEvents(Vector2 mousePos, bool mouseIsPressed) {
        for(auto &button : buttons) {
            button.isClicked(mousePos, mouseIsPressed);
        }
        for(auto &dropDown : dropDowns) {
            dropDown.isClicked(mousePos, mouseIsPressed);
        }
    }

}

#endif //NIMBLEGUI_ELEMENTMANAGER_H
