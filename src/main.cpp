#include "raylib.h"
#include "elements/BaseElement.h"
#include "elements/Input.h"


int main() {
    Gui::Window* window = Gui::createWindow(800, 600, "NimbleGUI");
    window->color = DARKGRAY;

    Gui::Button* button = Gui::createButton(50, 30, 90, 50);
    button->color = YELLOW;
    button->text = Gui::Label(button->pos, "Button");

    Gui::Panel* panel = Gui::createPanel(200, 50, 300, 300);
    panel->color = GREEN;

    Gui::Panel* second = Gui::createPanel(300, 500, 220, 90);
    second->color = DARKBLUE;


    panel->addElement(button);

    window->addElement(panel);
    window->addElement(second);

    Gui::initialise();

    while(!(WindowShouldClose())) {
        BeginDrawing();

        window->update();
        Gui::renderElements();
        Input::handle();

        EndDrawing();
    }

    window->close();
    Gui::cleanUp();

    return 0;
}