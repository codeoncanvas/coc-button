/**
 *
 * Copyright (c) 2014-2016 Code on Canvas Pty Ltd, http://codeoncanvas.cc
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 **/

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
void Button::moveTo( int x, int y ) {
    rect.setX(x);
    rect.setY(y);
}

void Button::moveCenterTo( int x, int y ) {
    rect.setX(x - rect.getW()/2);
    rect.setY(y - rect.getH()/2);
}

//--------------------------------------------------------------
const glm::ivec2 & Button::getPointPosLast() {
    return pointPos;
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

    pointPos.x = x;
    pointPos.y = y;

    bOver = rect.isInside(x, y);

    if(bUpdateAsync) {
        update();
    }
}

void Button::pointPressed(int x, int y) {
    if(bEnabled == false) {
        return;
    }

    pointPos.x = x;
    pointPos.y = y;

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

    pointPos.x = x;
    pointPos.y = y;

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

    pointPos.x = x;
    pointPos.y = y;

    bOver = rect.isInside(x, y);
    if(bDown == true) {
        bDown = false;
    }

    if(bUpdateAsync) {
        update();
    }
}

}
