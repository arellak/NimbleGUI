#include "raylib.h"
#include "elements/Button.h"
#include "elements/ElementManager.h"

int main() {
    InitWindow(800, 600, "NimbleGUI");
    SetTargetFPS(60);

    Button two({120, 60}, {0, 200}, GREEN);

    ElementManager::createButton({90, 60}, {250, 180}, BLUE);

    ElementManager::buttons.at(0).setText("Submit", 20);
    ElementManager::buttons.at(0).addAction(
            [](Button *button){
                button->size.x = button->size.x * 2;
                button->size.y = button->size.y * 2;
            },
            [](Button *button) {
                button->size.x = button->size.x / 2;
                button->size.y = button->size.y / 2;
            }
    );

    ElementManager::addButton(two);

    while(!(WindowShouldClose())) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        ElementManager::triggerClickEvents(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON),
                                           IsMouseButtonReleased(MOUSE_LEFT_BUTTON));
        ElementManager::renderAll();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}