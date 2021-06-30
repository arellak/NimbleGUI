#ifndef NIMBLEGUI_BASEELEMENT_H
#define NIMBLEGUI_BASEELEMENT_H

#include "raylib.h"
#include <iostream>

class BaseElement {
public:
    int id;
    Vector2 size;
    Vector2 pos;
    Color color;

    BaseElement(Vector2 size, Vector2 pos, Color color);

    virtual void render();
    void update(Vector2 pos);
    void update(Vector2 pos, Vector2 size);

    virtual bool inArea(Vector2 mousePos);

};

#endif //NIMBLEGUI_BASEELEMENT_H