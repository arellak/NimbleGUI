#ifndef NIMBLEGUI_BASEELEMENT_H
#define NIMBLEGUI_BASEELEMENT_H

#include <iostream>
#include <vector>
#include <memory>
#include "raylib.h"

namespace Gui {

    enum ElementType{
        WINDOW = 0,
        BUTTON = 1,
        LABEL = 2,
        TITLEBAR = 3,
        PANEL = 4,
        BASE = 5
    };

    class ElementBase {
    public:
        ElementType type;

        Vector2 dimension;
        Vector2 pos;

        Color color;
        bool visible;

        ElementBase(void); /** Initialise every Attribute with fixed default values, which will avoid a lot of potential errors and annoying bug searches  **/
        virtual void update(void) = 0;
    };

    class TitleBar : public ElementBase {
    public:
        int height;
        TitleBar(int x, int y, int width);
        void update() override;
    };

    class Panel: public ElementBase {
    public:
        bool hasBorders;
        Color borderColor;
        std::vector<ElementBase*> elements;
        TitleBar* titleBar;

        Panel(int x, int y, int width, int height);
        Panel(int x, int y);
        explicit Panel(Vector2 pos);

        void addElement(ElementBase* element);
        void update(void) override;
    };

    class Label: public ElementBase{
    public:
        const char* text;
        int textSize;

        explicit Label(const char* text);
        Label(float x, float y, const char* text);
        Label(Vector2 pos, const char* text);

        void update(void) override;
    };

    /*
     * Ignore any Button/or similar Events specific to some Interactions, until these Systems work on its own how they are intended to
     * Afterwards it'll be easier
     */
    class Button : public ElementBase {
    public:
        Label text = Label(Vector2{}, "");

        Button(Vector2 pos, Vector2 dimension);

        void update(void) override;
    };

    class Window: public ElementBase{
    public:
        bool hasBorders;
        Color borderColor;
        const char* title;

        Window(float width, float height, const char* title); /** On each Constructor of Widgets/Elements make sure to also set its proper ElementType  **/
        Window(Vector2 dimension, const char* title);


        void addElement(ElementBase* element); /** Careful before adding with certain Values - since Positions like x,y of a child inside a container like window are relative which is why a Button(10,10) is not on the left top corner of the program but on the parenting/enclosing container  **/
        void updateElements(void);


        void update(void) override; /** Could possible just call updateElements, after updating its own graphics **/
        void close(void);
    private:
        std::vector<ElementBase*> elements;

    };

    extern std::vector<ElementBase*> elements;
    extern Font textFont;

    Button* createButton(int x, int y, int width, int height);
    Panel* createPanel(int x, int y, int width, int height); /** Add Input::Register for automatic registrations **/
    Window* createWindow(int width, int height, const char* title);

    void renderElements(void);
    void initialise(void);
    void cleanUp(void);
    bool checkColor(Color first, Color second);
    extern ElementBase* getElementByPos(Vector2 pos);

}
#endif //NIMBLEGUI_BASEELEMENT_H