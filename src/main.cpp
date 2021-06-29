#include <iostream>

#include "raylib.h"
#include "elements/Button.h"
#include "elements/ElementManager.h"
#include "test/TestButtonClick.h"

int main() {
    InitWindow(800, 600, "NimbleGUI");
    SetTargetFPS(30);
    // BaseElement one({90, 60}, {250, 180}, BLACK);
    TestButtonClick testButtonClick;
    Button two({120, 60}, {300, 200}, GREEN, testButtonClick);

    ElementManager::createButton({90, 60}, {250, 180}, YELLOW, testButtonClick);

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