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
        DROP_DOWN = 3,
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

    class Panel: public ElementBase{
    public:
        bool hasBorders;
        Color borderColor;

        Panel(float x, float y);
        explicit Panel(Vector2 pos);

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

        bool checkColor(Color newColor);
        void update(void) override;
    };

    class DropDown : public Button {
    public:
        std::vector<Button*> elements;
        bool unfolded;

        DropDown(Vector2 pos, Vector2 dimension);
        ~DropDown(void);

        void addElement(const char* value);
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

    Panel* createPanel(int x, int y, int width, int height); /** Add Input::Register for automatic registrations **/
    Window* createWindow(int width, int height, const char* title);

    void renderElements(void);
    void initialise(void);
    void cleanUp(void);

}
#endif //NIMBLEGUI_BASEELEMENT_H