/**
 *
 * Copyright (c) 2016 Code on Canvas Pty Ltd, http://codeoncanvas.cc
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
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://codeoncanvas.cc
//
// Created by Rene Christen on 28/01/2016.
// Copyright (c) 2016, Code on Canvas Pty Ltd
//

#ifdef COC_CI

#include "ciButton.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace coc {

//--------------------------------------------------------------
ciButton::ciButton(coc::Rect rect) : coc::Button(rect) {
    setUseHandlers(true);
    setUpdateAsync(false);
    setRegisterEvents(false);
}

//--------------------------------------------------------------
void ciButton::draw() {
    gl::drawSolidRect( rect );
}

//--------------------------------------------------------------
void ciButton::mouseMoved(ci::app::MouseEvent & mouse) {
    coc::Button::pointMoved(mouse.getX(), mouse.getY());
}

void ciButton::mousePressed(ci::app::MouseEvent & mouse) {
    coc::Button::pointPressed(mouse.getX(), mouse.getY());
}

void ciButton::mouseDragged(ci::app::MouseEvent & mouse) {
    coc::Button::pointDragged(mouse.getX(), mouse.getY());
}

void ciButton::mouseReleased(ci::app::MouseEvent & mouse) {
    coc::Button::pointReleased(mouse.getX(), mouse.getY());
}

//--------------------------------------------------------------
void ciButton::handleMovedInside() {
    signalOnMovedInside.emit();
}

void ciButton::handleMovedOutside() {
    signalOnMovedOutside.emit();
}

void ciButton::handlePressedInside() {
    signalOnPressedInside.emit();
}

void ciButton::handleDraggedOutside() {
    signalOnDraggedOutside.emit();
}

void ciButton::handleReleasedInside() {
    signalOnReleasedInside.emit();
}

void ciButton::handleReleasedOutside() {
    signalOnReleasedOutside.emit();
}

void ciButton::handleEventRegister() {
    cbMouseDown = getWindow()->getSignalMouseDown().connect( std::bind( &ciButton::mousePressed, this, std::placeholders::_1 ) );
    cbMouseDrag = getWindow()->getSignalMouseDrag().connect( std::bind( &ciButton::mouseDragged, this, std::placeholders::_1 ) );
    cbMouseUp   = getWindow()->getSignalMouseUp().connect( std::bind( &ciButton::mouseReleased, this, std::placeholders::_1 ) );
    cbMouseMove = getWindow()->getSignalMouseMove().connect( std::bind( &ciButton::mouseMoved, this, std::placeholders::_1 ) );
}

void ciButton::handleEventUnregister() {
    cbMouseDown.disconnect();
    cbMouseDrag.disconnect();
    cbMouseUp.disconnect();
    cbMouseMove.disconnect();
}

}

#endif
