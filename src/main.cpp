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

    Gui::Button* test = Gui::createButton(120, 90, 120, 50);
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


    panel->addElement(button);
    panel->addElement(test);

    window->addElement(panel);
    window->addElement(second);

    while(!(WindowShouldClose())) {
        BeginDrawing();

        if(IsKeyPressed(KEY_SPACE)) {
            panel->visible = !panel->visible;
        }
        window->update();
        Gui::renderElements();
        Input::handle();

        EndDrawing();
    }

    window->close();
    Gui::cleanUp();

    return 0;
}