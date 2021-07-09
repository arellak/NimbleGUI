//
// Created by master on 09.07.21.
//

#include "Input.h"

void Input::handle(){
    if(IsMouseButtonPressed(0)){
        checkCollisions();
    }
    if(IsMouseButtonPressed(0)){
        /** Could be combined inside checkCollisions, but can stand on its own; Since, in order to being able to drag
         * the element needs to be in focus anyway it doesn't require any Parameters, since focussed Widget is already saved
         */
        dragElement();
    }
}

void Input::registr(){
    auto* rect = new Rectangle();

    ui_collision.push_back(rect);
}

void Input::checkCollisions(){
    /** Check if MouseClick is hitting a UI Element or Window and if so focus it / throw their or in general Events **/

}