#include "raylib.h"
#include "elements/Button.h"
#include "elements/ElementManager.h"

int main() {
    InitWindow(800, 600, "NimbleGUI");
    SetTargetFPS(60);


    ElementManager::createButton({90, 60}, {250, 180}, BLUE);

    Button &button = ElementManager::buttons.at(0);

    button.setText("Submit", 70);
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

    ElementManager::init();

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