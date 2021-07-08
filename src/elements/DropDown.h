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
    typedef void (*actionOnUnfold)(DropDown*);

    actionOnUnfold unfoldAction;

    std::vector<Button*> elements;
    Button *activeElement;
    bool unfolded;

    DropDown(Vector2 size, Vector2 pos, Color color, std::string fontName);

    void init() override;
    void render() override;
    void isClicked(Vector2 mousePos, bool mouseIsPressed) override;

    void addAction(actionOnUnfold onUnfoldAction);
    void addElement(std::string value);

    void clean() override;
};


#endif //NIMBLEGUI_DROPDOWN_H
