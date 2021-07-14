#include "raylib.h"
#include "elements/BaseElement.h"
#include "elements/Input.h"


int main() {
    Gui::Window* window = Gui::createWindow(800, 600, "NimbleGUI");
    window->color = DARKGRAY;

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