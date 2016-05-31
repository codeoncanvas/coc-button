//
//  cocButton.cpp
//  Created by Lukasz Karluk on 2/06/2014.
//  http://codeoncanvas.cc
//

#include "cocButton.h"

namespace coc {

Button::Button(coc::Rect rectNew) {

    rect = rectNew;
    bEnabled = true;
    bUseHandlers = false;
    bUpdateAsync = false;
    bRegisterEvents = false;

    bOver = coc::Value<bool>(false); // init with default value.
    bDown = coc::Value<bool>(false); // init with default value.
}

Button::~Button() {
    setRegisterEvents(false); // unregister events on destructor.
}

//--------------------------------------------------------------
void Button::setRect(coc::Rect value) {
    rect = value;
}

void Button::setRect(float x, float y, float w, float h) {
    coc::Rect r;
    r.setX(x);
    r.setY(y);
    r.setW(w);
    r.setH(h);
    setRect(r);
}

const coc::Rect & Button::getRect() const {
    return rect;
}

//--------------------------------------------------------------
void Button::setEnabled(bool value) {
    bEnabled = value;
}

void Button::setUseHandlers(bool value) {
    bUseHandlers = value;
}

void Button::setUpdateAsync(bool value) {
    bUpdateAsync = value;
}

void Button::setRegisterEvents(bool value) {
    if(bRegisterEvents == value) {
        return;
    }

    bRegisterEvents = value;
    if(bRegisterEvents == true) {
        handleEventRegister();
    } else {
        handleEventUnregister();
    }
}

//--------------------------------------------------------------


void Button::moveTo( int x, int y )
{
    rect.setX(x);
    rect.setY(y);
}

void Button::moveCenterTo( int x, int y )
{
    rect.setX(x - rect.getW()/2);
    rect.setY(y - rect.getH()/2);
}


//--------------------------------------------------------------
void Button::update() {
    
    bOver.update();
    bDown.update();
    
    if(bUseHandlers == false) {
        return;
    }
    
    if(movedInside()) {
        handleMovedInside();
    }
    if(movedOutside()) {
        handleMovedOutside();
    }
    if(pressedInside()) {
        handlePressedInside();
    }
    if(draggedOutside()) {
        handleDraggedOutside();
    }
    if(releasedInside()) {
        handleReleasedInside();
    }
    if(releasedOutside()) {
        handleReleasedOutside();
    }
}

bool Button::over() const {
    return bOver;
}

bool Button::overChanged() const {
    return bOver.hasChanged();
}

bool Button::down() const {
    return bDown;
}

bool Button::downChanged() const {
    return bDown.hasChanged();
}

//--------------------------------------------------------------
bool Button::movedInside() {
    return (over() && overChanged());
}

bool Button::movedOutside() {
    return (!over() && overChanged());
}

bool Button::pressedInside() {
    return (down() && downChanged());
}

bool Button::draggedOutside() {
    return (!down() && downChanged() && !over() && overChanged());
}

bool Button::releasedInside() {
    return (!down() && downChanged() && over());
}

bool Button::releasedOutside() {
    return (!down() && downChanged() && !over());
}

//--------------------------------------------------------------
void Button::pointMoved(int x, int y) {
    if(bEnabled == false) {
        return;
    }

    bOver = rect.isInside(x, y);
    
    if(bUpdateAsync) {
        update();
    }
}

void Button::pointPressed(int x, int y) {
    if(bEnabled == false) {
        return;
    }

    bOver = rect.isInside(x, y);
    if(bOver == true) {
        bDown = true;
    }
    
    if(bUpdateAsync) {
        update();
    }
}

void Button::pointDragged(int x, int y) {
    if(bEnabled == false) {
        return;
    }

    bOver = rect.isInside(x, y);
    if(bOver == false) {
        bDown = false;
    }
    
    if(bUpdateAsync) {
        update();
    }
}

void Button::pointReleased(int x, int y) {
    if(bEnabled == false) {
        return;
    }

    bOver = rect.isInside(x, y);
    bDown = false;
    
    if(bUpdateAsync) {
        update();
    }
}

}