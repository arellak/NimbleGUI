# NimbleGUI
## Introduction

## Installation
Good luck with that.

## How to use
```cpp
#include "BaseElement.h"
#include "Input.h"
#include "raylib.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    // initialize window
    Gui::Window* window = Gui::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Test!");
    // set background color
    window->color = DARKGRAY;

    // create a new button with the following parameters:
    // x, y, width, height
    Gui::Button* button = Gui::createButton(50, 30, 90, 50);
    // set the background color of the button to yellow
    button->color = YELLOW;
    // set the Label of the Button and its position
    button->text = Gui::Label(button->pos, "Button");

    // Create a new Panel, same parameters as the Button has
    Gui::Panel* panel = Gui::createPanel(200, 50, 300, 300);
    // set its background color to green
    panel->color = GREEN;

    // same as above
    Gui::Panel* second = Gui::createPanel(300, 500, 220, 90);
    // this time set the background color to darkblue
    second->color = DARKBLUE;
    
    // add the button as element to the first panel
    // if the buttons->pos is outside the panel, it won't be shown
    // button is now a part of the panel
    // no, there is no way for the button to know its parent you fuck
    panel->addElement(button);
    
    // add the panels to the window
    window->addElement(panel);
    window->addElement(second);
    
    // initialize the gui
    Gui::initialise();
    
    // raylib shit
    while(!(WindowShouldClose())) {
        BeginDrawing();
        
        // render the window
        window->update();
        // render all gui elements,idfk what it means
        Gui::renderElements();
        // handle the input, e.g. dragging a panel
        Input::handle();
        
        EndDrawing();
    }
    // close the window
    window->close();
    // cleanup some memory so there are no memory leaks
    // yea I know, it should happen waaayy before and not in the
    // end when everything goes back to normal because your OS handles it
    Gui::cleanUp();
    
    return 0;
}
```

## Resources
[Raylib](https://raylib.com)

[Monoid Font](https://larsenwork.com/monoid/)