#ifndef NIMBLEGUI_BASEELEMENT_H
#define NIMBLEGUI_BASEELEMENT_H

#include "raylib.h"
#include <iostream>
#include <vector>

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

        ElementBase(); /** Initialise every Attribute with fixed default values, which will avoid a lot of potential errors and annoying bug searches  **/
        virtual void update(Vector2 pos) = 0;

    };

    class Panel: public ElementBase{
    public:
        bool hasBorders;
        Color borderColor;

        Panel(float x, float y);
        explicit Panel(Vector2 pos);

        void update(Vector2 pos) override;
    };

    class Label: public ElementBase{
    public:
        const char* text;
        int textSize;

        Label(const char *text);
        Label(float x, float y);
        Label(float x, float y, const char * text);
        explicit Label(Vector2 pos);

        void update(Vector2 pos) override;
    };

    /*
     * Ignore any Button/or similar Events specific to some Interactions, until these Systems work on its own how they are intended to
     * Afterwards it'll be easier
     */
    class Button : public ElementBase {
    public:
        Label text = "";

        Button(Vector2 pos);
        Button(Vector2 pos, Vector2 dimension);

        bool checkColor(Color newColor);
    };

    class DropDown : public Button {
    public:
        std::vector<Button*> elements;
        bool unfolded;

        DropDown(Vector2 pos);
        DropDown(Vector2 pos, Vector2 dimension);

        void addElement(std::string value);
    };

    class Window: public ElementBase{
    public:
        bool hasBorders;
        Color borderColor;

        Window(float x, float y); /** On each Constructor of Widgets/Elements make sure to also set its proper ElementType  **/
        explicit Window(Vector2 pos);

        void addElement(ElementBase* element); /** Careful before adding with certain Values - since Positions like x,y of a child inside a container like window are relative which is why a Button(10,10) is not on the left top corner of the program but on the parenting/enclosing container  **/
        void updateElements();


        void update(Vector2 pos) override; /** Could possible just call updateElements, after updating its own graphics **/

    private:
        std::vector<ElementBase*> elements;

    };

    std::vector<ElementBase*> elements;

    Font textFont;

    Panel* createPanel(int x, int y, int width, int height); /** Add Input::Register for automatic registrations **/
    void renderElements(void);
    void initialise();

}
#endif //NIMBLEGUI_BASEELEMENT_H




