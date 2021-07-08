#include "DropDown.h"

DropDown::DropDown(Vector2 size, Vector2 pos, Color color, std::string fontName)
        : Button(size, pos, color, fontName) {

    unfolded = false;
    if(text.empty()) {
        activeElement = new Button(size, pos, color, this->fontName);
        activeElement->setText("Test", 20); // for testing purposes
    }
    elements.push_back(activeElement);

    unfoldAction = [](DropDown* dropDown) {    /* Das ist keine Action - das ist ein Verhalten das jedes Widget der Art "Dropdown" besitzt und keine Eigenheit */
        if(dropDown->unfolded) {
            for(auto &element : dropDown->elements) {
                element->visible = true;
            }
        } else {
            for(auto &element : dropDown->elements) {
                element->visible = false;
            }
            dropDown->activeElement->visible = true;
        }

        dropDown->unfolded = !dropDown->unfolded;
    };
} // so gefühlt hat der gerade rumgeheult, weil diese clean Methode in "BaseElement" virtual ist

void DropDown::init() {

}

void DropDown::render() {
    if(unfolded) {
        for(auto &element : elements) {
            element->render();
        }
    } else {
        activeElement->render();
    }
}

// TODO if this->elements.size is 0 when this method is called, the given element should be the "activeElement"
void DropDown::addElement(std::string value) {
    float latestY = elements.at(elements.size()-1)->pos.y;
    Vector2 newPos{pos.x, latestY+size.y};

    Button tempButton(size, newPos, color, fontName);
    if(fontSize > 0) {
        tempButton.setText(value, fontSize);
    } else {
        tempButton.setText(value, 20);
    }

    elements.push_back(&tempButton);
}

void DropDown::addAction(DropDown::actionOnUnfold onUnfoldAction) {
    unfoldAction = onUnfoldAction;
}

void DropDown::isClicked(Vector2 mousePos, bool mouseIsPressed) {
    if(mouseIsPressed && inArea(mousePos) && unfoldAction != nullptr) {
        unfoldAction(this);
    }
}

void DropDown::clean() {
    for(auto &element : elements) {
        if(element == nullptr) continue;
        free(element);
    }
    printf("Cleared DropDowns!\n");
}
