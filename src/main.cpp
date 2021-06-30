#include "raylib.h"
#include "elements/Button.h"
#include "elements/ElementManager.h"

int main() {
    InitWindow(800, 600, "NimbleGUI");
    SetTargetFPS(60);

    Button two({120, 60}, {0, 200}, GREEN);

    ElementManager::createButton({90, 60}, {250, 180}, YELLOW);

    ElementManager::buttons.at(0).addAction([](Button *button){
        button->color = BLACK;
    });

    ElementManager::addButton(two);


    while(!(WindowShouldClose())) {
        BeginDrawing();
        ClearBackground(GRAY);

        ElementManager::triggerClickEvents(GetMousePosition(), IsMouseButtonDown(MOUSE_LEFT_BUTTON));
        ElementManager::renderAll();

        EndDrawing();
    }
    CloseWindow();

    return 0;
}