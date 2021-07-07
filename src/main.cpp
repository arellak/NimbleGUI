#include "raylib.h"
#include "elements/Button.h"
#include "elements/ElementManager.h"

int main() {
    InitWindow(800, 600, "NimbleGUI");
    SetTargetFPS(60);


    Button &button = ElementManager::createButton({150, 88}, {250, 180}, BLUE);

    button.setText("Submit", 30);
    button.addAction(
            [](Button *button){
                if(button->checkColor(BLUE)) {
                    button->color = GREEN;
                }
            },
            [](Button *button) {
                if(button->checkColor(GREEN)) {
                    button->color = BLUE;
                }
            }
    );

    while(!(WindowShouldClose())) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        ElementManager::triggerClickEvents(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON),
                                           IsMouseButtonReleased(MOUSE_LEFT_BUTTON));
        ElementManager::render();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}