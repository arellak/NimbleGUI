#ifndef NIMBLEGUI_BASEELEMENT_H
#define NIMBLEGUI_BASEELEMENT_H

#include "raylib.h"
#include <iostream>
#include <vector>

namespace Gui {

    enum ElementType{
        WINDOW = 0,
        BUTTON = 1,
        LABEL = 2
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

        Panel(int x, int y);
        explicit Panel(Vector2 pos);

        void update(Vector2 pos) override;

    };

    class Label: public ElementBase{
    public:
        const char* text;
        int textSize;

        Label(int x, int y);
        explicit Label(Vector2 pos);

        void update(Vector2 pos) override;
    };

    /*
     * Ignore any Button/or similar Events specific to some Interactions, until these Systems work on its own how they are intended to
     * Afterwards it'll be easier
     */
    class Button : public ElementBase {
    public:
        Label text;

        bool checkColor(Color newColor);
    };

    class DropDown : public Button {
    public:
        std::vector<Button*> elements;
        bool unfolded = false;


        void addElement(std::string value);
    };

    class Window: public ElementBase{
    public:
        bool hasBorders;
        Color borderColor;

        Window(int x, int y); /** On each Constructor of Widgets/Elements make sure to also set its proper ElementType  **/
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



/** --------------- Input File .h ----------------- */


#include <vector>

namespace Input{
    std::vector<Rectangle*> ui_collision;
    Gui::ElementBase* focused;
    bool dragging = false;

    void registerContainer(Gui::Window* window);
    void registr();
    void handle();
    void dragElement();
}

void checkCollisions(){
    /** Check if MouseClick is hitting a UI Element or Window and if so focus it / throw their or in general Events **/

}

void Input::handle(){
    if(IsMouseButtonPressed(0)){
        checkCollisions();
    }
    if(IsMouseButtonPressed(0)){
        /** Could be combined inside checkCollisions, but can stand on its own; Since, in order to being able to drag
         * the element needs to be in focus anyway it doesn't require any Parameters, since focussed Widget is already saved
         */
        dragElement();
    }
}

void Input::registr(){
    auto* rect = new Rectangle();

    ui_collision.push_back(rect);
}



