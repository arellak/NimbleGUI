//
// Created by rocketman on 07/07/2021.
//

#ifndef NIMBLEGUI_DROPDOWN_H
#define NIMBLEGUI_DROPDOWN_H

#include "Button.h"
#include <string>
#include <vector>

/*
 * each element is an own button
 */

class DropDown : public Button {
public:
    typedef void (*actionOnClick)(DropDown*);
    typedef void (*actionOnRelease)(DropDown*);

    typedef void (*actionOnUnfold)(DropDown*);

    actionOnClick clickAction;
    actionOnRelease releaseAction;
    actionOnUnfold  unfoldAction;

    std::vector<Button> elements;
    Button *activeElement;
    bool unfolded;

    DropDown(Vector2 size, Vector2 pos, Color color);
    DropDown(Vector2 size, Vector2 pos, Color color, std::string fontName);

    void init() override;
    void render() override;

    void addAction(actionOnClick onClickAction, actionOnRelease onReleaseAction);
    void addOnClickAction(actionOnClick onClickAction);
    void addOnReleaseAction(actionOnRelease onReleaseAction);
    void addUnfoldAction(actionOnUnfold onUnfoldAction);

    void addElement(std::string value);
};


#endif //NIMBLEGUI_DROPDOWN_H
