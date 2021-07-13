#include "raylib.h"
#include "elements/BaseElement.h"
#include "elements/Input.h"

static Gui::Window window();

int main() {
    InitWindow(800, 600, "NimbleGUI");
    SetTargetFPS(25); /** Lower the Framerate, which makes debugging and testing much easier with UIs **/

    Gui::initialise();

    while(!(WindowShouldClose())) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        Gui::renderElements();
        // Input::handle();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}