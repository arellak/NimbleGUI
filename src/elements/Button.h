#ifndef NIMBLEGUI_BUTTON_H
#define NIMBLEGUI_BUTTON_H

#include <string>
#include "BaseElement.h"

class Button : public BaseElement {
public:
    typedef void (*actionOnClick)(Button*);
    typedef void (*actionOnRelease)(Button*);
    actionOnClick clickAction;
    actionOnRelease releaseAction; // TODO release Action should always be triggered when clickAction is triggered even when the mouse is outside the area

    Font font;
    Vector2 textPosition;
    std::string text;
    int fontSize;

    Button(Vector2 size, Vector2 pos, Color color);
    Button(Vector2 size, Vector2 pos, Color color, std::string fontName);


    void init() override;
    void render() override;
    bool inArea(Vector2 mousePos) override;
    void isClicked(Vector2 mousePos, bool mouseIsPressed, bool mouseIsReleased);
    void addAction(actionOnClick onClickAction, actionOnRelease onReleaseAction);
    void addOnClickAction(actionOnClick onClickAction);
    void addOnReleaseAction(actionOnRelease onReleaseAction);

    void setText(std::string text, int fontSize);
    Vector2 TextSize();
    Vector2 TextSize(std::string &txt);

    bool checkColor(Color newColor);

    bool textInArea();
    bool textInArea(std::string txt);
    void cutText();
    void centerText();
};


#endif //NIMBLEGUI_BUTTON_H
