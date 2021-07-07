//
// Created by rocketman on 07/07/2021.
//

#include "DropDown.h"

DropDown::DropDown(Vector2 size, Vector2 pos, Color color)
        : Button(size, pos, color) {
    // this->activeElement = Button({}, {}, BLACK);
    unfoldAction = [](DropDown* dropDown) {
        if(dropDown->unfolded) {
            for(auto &element : dropDown->elements) {
                element.visible = true;
            }
        } else {
            for(auto &element : dropDown->elements) {
                element.visible = false;
            }
            dropDown->activeElement->visible = true;
        }
        dropDown->unfolded = !dropDown->unfolded;
    };
}

DropDown::DropDown(Vector2 size, Vector2 pos, Color color, std::string fontName)
        : Button(size, pos, color, fontName) {
    // this->activeElement = Button(this->size, this->pos, this->color);
}

void DropDown::init() {

}

void DropDown::render() {
    if(unfolded) {
        for(auto &element : elements) {
            element.render();
        }
    } else {
        activeElement->render();
    }
}

void DropDown::addElement(std::string value) {
    Button tempButton(this->size, this->pos, this->color);
    if(this->fontSize > 0) {
        tempButton.setText(value, this->fontSize);
    } else {
        tempButton.setText(value, 20);
    }

    this->elements.push_back(tempButton);
}

void DropDown::addAction(DropDown::actionOnClick onClickAction, DropDown::actionOnRelease onReleaseAction) {
    clickAction = onClickAction;
    releaseAction = onReleaseAction;
}

void DropDown::addOnClickAction(DropDown::actionOnClick onClickAction) {
    clickAction = onClickAction;
}

void DropDown::addOnReleaseAction(DropDown::actionOnRelease onReleaseAction) {
    releaseAction = onReleaseAction;
}

void DropDown::addUnfoldAction(DropDown::actionOnUnfold onUnfoldAction) {
    unfoldAction = onUnfoldAction;
}
