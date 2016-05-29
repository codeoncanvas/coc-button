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
ciButton::ciButton() : coc::Button() {
    bUseHandlers = true;
    bUpdateAsync = true;
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
    //
}

void ciButton::handleMovedOutside() {
    //
}

void ciButton::handlePressedInside() {
    //
}

void ciButton::handleDraggedInside() {
    //
}

void ciButton::handleDraggedOutside() {
    //
}

void ciButton::handleReleasedInside() {
    //
}

void ciButton::handleReleasedOutside() {
    //
}

}

#endif