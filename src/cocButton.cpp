/**
 *
 *      ┌─┐╔═╗┌┬┐┌─┐
 *      │  ║ ║ ││├┤
 *      └─┘╚═╝─┴┘└─┘
 *   ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
 *   │  ├─┤║║║└┐┌┘├─┤└─┐
 *   └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
 *
 * Copyright (c) 2014-2016 Code on Canvas Pty Ltd, http://CodeOnCanvas.cc
 *
 * This software is distributed under the MIT license
 * https://tldrlegal.com/license/mit-license
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code
 *
 **/

#include "cocButton.h"

namespace coc {

Button::Button(coc::Rect rectNew) {

    rect = rectNew;
    bEnabled = true;
    bUseHandlers = false;
    bUpdateAsync = false;
    bRegisterEvents = false;

    bOver = false;
    bOverChanged = false;
    bDown = false;
    bDownChanged = false;
    
    bMovedInside = false;
    bMovedOutside = false;
    bPressedInside = false;
    bDraggedOutside = false;
    bReleasedInside = false;
    bReleasedOutside = false;
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

    bOverChanged = false;
    bDownChanged = false;
    
    bMovedInside = false;
    bMovedOutside = false;
    bPressedInside = false;
    bDraggedOutside = false;
    bReleasedInside = false;
    bReleasedOutside = false;

    //----------------------------------------------------------
    for(int i=0; i<points.size(); i++) {
        ButtonPoint & point = points[i];
        
        bool bOverNew = rect.isInside(point.pos.x, point.pos.y);
        bOverChanged = (bOver != bOverNew);
        if(bOverChanged) {
            bOver = bOverNew;
        }
        
        if(point.type == ButtonPoint::Type::Moved) {
            
            bMovedInside = bOver && bOverChanged && !bDown;
            bMovedOutside = !bOver && bOverChanged && !bDown;
        
        } else if(point.type == ButtonPoint::Type::Pressed) {
        
            bool bDownNew = bOver;
            bDownChanged = (bDown != bDownNew);
            if(bDownChanged) {
                bDown = bDownNew;
            }
            
            bPressedInside = bDown && bDownChanged;
            
        } else if(point.type == ButtonPoint::Type::Dragged) {
        
            if(bDown) {
                bool bDownNew = bOver;
                bDownChanged = (bDown != bDownNew);
                if(bDownChanged) {
                    bDown = bDownNew;
                }
            }
        
            bDraggedOutside = !bDown && bDownChanged;
        
        } else if(point.type == ButtonPoint::Type::Released) {

            bool bDownNew = false;
            bDownChanged = (bDown != bDownNew);
            if(bDownChanged) {
                bDown = bDownNew;
            }
        
            bReleasedInside = !bDown && bDownChanged && bOver;
            bReleasedOutside = !bDown && bDownChanged && !bOver;
        }
        
        pointPos = point.pos; // save last point position.
    }
    
    points.clear();
    
    //----------------------------------------------------------
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
    return bOverChanged;
}

bool Button::down() const {
    return bDown;
}

bool Button::downChanged() const {
    return bDownChanged;
}

//--------------------------------------------------------------
bool Button::movedInside() {
    return bMovedInside;
}

bool Button::movedOutside() {
    return bMovedOutside;
}

bool Button::pressedInside() {
    return bPressedInside;
}

bool Button::draggedOutside() {
    return bDraggedOutside;
}

bool Button::releasedInside() {
    return bReleasedInside;
}

bool Button::releasedOutside() {
    return bReleasedOutside;
}

//--------------------------------------------------------------
void Button::pointMoved(int x, int y) {
    if(bEnabled == false) {
        return;
    }
    
    pointNew(ButtonPoint::Type::Moved, x, y);
    
    if(bUpdateAsync) {
        update();
    }
}

void Button::pointPressed(int x, int y) {
    if(bEnabled == false) {
        return;
    }
    
    pointNew(ButtonPoint::Type::Pressed, x, y);
    
    if(bUpdateAsync) {
        update();
    }
}

void Button::pointDragged(int x, int y) {
    if(bEnabled == false) {
        return;
    }

    pointNew(ButtonPoint::Type::Dragged, x, y);
    
    if(bUpdateAsync) {
        update();
    }
}

void Button::pointReleased(int x, int y) {
    if(bEnabled == false) {
        return;
    }
    
    pointNew(ButtonPoint::Type::Released, x, y);
    
    if(bUpdateAsync) {
        update();
    }
}

void Button::pointNew(ButtonPoint::Type type, int x, int y) {
    points.push_back(ButtonPoint());
    ButtonPoint & point = points.back();
    point.type = type;
    point.pos = glm::ivec2(x, y);
}

}
