#ifndef NIMBLEGUI_BASEELEMENT_Hclear
#define NIMBLEGUI_BASEELEMENT_H

#include "raylib.h"
#include <iostream>

class BaseElement {
public:
    int id;
    Vector2 size;
    Vector2 pos;
    Color color;
    bool visible;

    BaseElement(Vector2 size, Vector2 pos, Color color);

    virtual void init();
    virtual void render();
    void update(Vector2 pos);
    void update(Vector2 pos, Vector2 size);
    virtual bool inArea(Vector2 mousePos);
    virtual void clean() = 0;
};

#endif //NIMBLEGUI_BASEELEMENT_H