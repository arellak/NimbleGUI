#ifndef NIMBLEGUI_BUTTON_H
#define NIMBLEGUI_BUTTON_H

#include <string>
#include "BaseElement.h"
#include <any>

class Button : public BaseElement {
public:
    typedef void (*actionOnClick)(Button*);
    actionOnClick clickAction;

    Font font;
    std::string fontName;
    Vector2 textPosition;
    std::string text;
    int fontSize;

    Button(Vector2 size, Vector2 pos, Color color, std::string fontName);

    void init() override;
    void render() override;
    bool inArea(Vector2 mousePos) override;
    virtual void isClicked(Vector2 mousePos, bool mouseIsPressed);
    virtual void addAction(actionOnClick onClickAction);

    void setText(std::string text, int fontSize);
    Vector2 TextSize();
    Vector2 TextSize(std::string &txt);

    bool checkColor(Color newColor);

    bool textInArea();
    bool textInArea(std::string txt);
    void cutText();
    void centerText();
    virtual void clean() override;
};


#endif //NIMBLEGUI_BUTTON_H
