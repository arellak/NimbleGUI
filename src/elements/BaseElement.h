#ifndef NIMBLEGUI_BASEELEMENT_H
#define NIMBLEGUI_BASEELEMENT_H

#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"

namespace Gui {

    enum ElementType{
        BASE = 0,
        WINDOW = 1,
        BUTTON = 2,
        LABEL = 3,
        TITLEBAR = 4,
        PANEL = 5,
        BORDER = 6
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
        void update(void) override;
    };

    class Panel: public ElementBase {
    public:
        // TODO implement borders
        bool hasBorders;
        Color borderColor;
        int borderThickness;

        std::vector<ElementBase*> elements;
        TitleBar* titleBar;

        Panel(int x, int y, int width, int height);
        Panel(int x, int y);
        explicit Panel(Vector2 pos);

        void addElement(ElementBase* element);
        void update(void) override;
        void updateBorder(void);
    };

    class Label: public ElementBase{
    public:
        std::string value;
        int textSize;

        explicit Label(std::string text);
        Label(float x, float y, std::string text);
        Label(Vector2 pos, std::string text);

        void update(void) override;
    };

    /*
     * Ignore any Button/or similar Events specific to some Interactions, until these Systems work on its own how they are intended to
     * Afterwards it'll be easier
     */
    class Button : public ElementBase {
    public:
        typedef void (*ClickAction)(Button* button);

        ClickAction action;

        Label text = Label(Vector2{}, "");
        Vector2 offset;

        Button(Vector2 pos, Vector2 dimension);

        void update(void) override;
        void addAction(ClickAction action);
        void cutText(void);
        void updateText(std::string newText);
    };

    class Window: public ElementBase{
    public:
        bool hasBorders;
        Color borderColor;
        std::string title;

        Window(float width, float height, std::string title); /** On each Constructor of Widgets/Elements make sure to also set its proper ElementType  **/
        Window(Vector2 dimension, std::string title);


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
    Window* createWindow(int width, int height, std::string title);

    void renderElements(void);
    void initialise(void);
    void cleanUp(void);
    bool checkColor(Color first, Color second);
    extern ElementBase* getElementByPos(Vector2 pos);

}
#endif //NIMBLEGUI_BASEELEMENT_H