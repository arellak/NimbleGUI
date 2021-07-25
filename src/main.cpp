#include "raylib.h"
#include "elements/BaseElement.h"
#include "elements/Input.h"

int main() {
    Gui::Window* window = Gui::createWindow(800, 600, "NimbleGUI");
    window->color = DARKGRAY;


    Gui::initialise();

    Gui::Button* button = Gui::createButton(50, 30, 90, 50);
    button->color = YELLOW;
    button->updateText("Button");
    button->addAction([](Gui::Button* button) {
        printf("Click!\n");
    });

    Gui::Button* test = Gui::createButton(40, 30, 120, 50);
    test->color = RED;
    test->text.textSize = 30;
    test->updateText("Submit");
    test->addAction([](Gui::Button* button) {
        if(Gui::checkColor(button->color, RED)) {
            button->color = PINK;
        } else if(Gui::checkColor(button->color, PINK)) {
            button->color = RED;
        }
    });

    Gui::Panel* panel = Gui::createPanel(200, 50, 300, 300);
    panel->color = GREEN;
    panel->borderColor = BLACK;
    panel->borderThickness = 3;

    Gui::Panel* second = Gui::createPanel(300, 500, 220, 90);
    second->color = DARKBLUE;

    Gui::Textbox* textbox = Gui::createTextbox(20, 200, 250, 50, WHITE);


    panel->addElement(button);
    panel->addElement(textbox);

    second->addElement(test);

    window->addElement(panel);
    window->addElement(second);

    Rectangle rec{50, 50, 200, 100};
    int MAX_INPUT_CHARS = 25;
    char name[MAX_INPUT_CHARS + 1];
    for(int i = 0; i < MAX_INPUT_CHARS; i++) {
        name[i] = '\0';
    }
    name[MAX_INPUT_CHARS+1] = '\0';

    int letterCount = 0;
    bool mouseOnText = false;

    int framesCounter = 0;


    while(!(WindowShouldClose())) {
        /*
         * if(CheckCollisionPointRec(GetMousePosition(), rec)) {
            mouseOnText = true;
        } else {
            mouseOnText = false;
        }

        if(mouseOnText) {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();

            while(key > 0) {
                if((key >= 32) && (key <= 125) && letterCount < 25) {
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0';
                    letterCount++;
                }

                key = GetCharPressed();
            }

            if(IsKeyPressed(KEY_BACKSPACE)) {
                letterCount--;
                if(letterCount < 0) {
                    letterCount = 0;
                }
                name[letterCount] = '\0';
            }
        } else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        if(mouseOnText) {
            framesCounter++;
        } else {
            framesCounter = 0;
        }
        */

        BeginDrawing();

        window->update();
        Gui::renderElements();
        Input::handle();
        /*
        DrawRectangleRec(rec, LIGHTGRAY);
        if(mouseOnText) {
            DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, RED);
        } else {
            DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, BLACK);
        }

        DrawText(name, rec.x + 5, rec.y + 8, 40, MAROON);
        if(mouseOnText) {
            if(letterCount < MAX_INPUT_CHARS) {
                if (((framesCounter/20)%2) == 0) DrawText("_", rec.x + 8 + MeasureText(name, 40), rec.y + 12, 40, MAROON);
            } else {
                DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
            }
        }
         */

        EndDrawing();
    }

    window->close();
    Gui::cleanUp();

    return 0;
}