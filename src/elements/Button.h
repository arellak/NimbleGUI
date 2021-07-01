#ifndef NIMBLEGUI_BUTTON_H
#define NIMBLEGUI_BUTTON_H

#include <string>
#include "BaseElement.h"

class Button : public BaseElement {
public:
    typedef void (*actionOnClick)(Button*);
    typedef void (*actionOnRelease)(Button*);
    actionOnClick clickAction;
    actionOnRelease releaseAction;

    Font font;
    std::string text;
    int fontSize;


    Button(Vector2 size, Vector2 pos, Color color);

    void render() override;
    bool inArea(Vector2 mousePos) override;
    void isClicked(Vector2 mousePos, bool mouseIsPressed, bool mouseIsReleased);
    void addAction(actionOnClick onClickAction, actionOnRelease releaseAction);
    void addOnClickAction(actionOnClick onClickAction);
    void addOnReleaseAction(actionOnRelease onReleaseAction);

    void setText(std::string text, int fontSize);
    Vector2 TextWidth();

    bool checkColor(Color newColor);
};


#endif //NIMBLEGUI_BUTTON_H
