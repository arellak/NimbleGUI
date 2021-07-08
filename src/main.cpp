#include "raylib.h"
#include "elements/BaseElement.h"
#include "elements/Input.h"



static Gui::Panel p;

int main() {
    InitWindow(800, 600, "NimbleGUI");
    SetTargetFPS(60);

    Gui::initialise();

    while(!(WindowShouldClose())) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        Gui::renderElements();
        Input::handle();


        EndDrawing();
    }
    CloseWindow();

    return 0;
}