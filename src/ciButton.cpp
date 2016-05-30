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
    setRegisterEvents(true);
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
    // TODO: add signal.
}

void ciButton::handleMovedOutside() {
    // TODO: add signal.
}

void ciButton::handlePressedInside() {
    // TODO: add signal.
}

void ciButton::handleDraggedOutside() {
    // TODO: add signal.
}

void ciButton::handleReleasedInside() {
    // TODO: add signal.
}

void ciButton::handleReleasedOutside() {
    // TODO: add signal.
}

void ciButton::handleEventRegister() {
    // TODO: hook up to cinder events.
}

void ciButton::handleEventUnregister() {
    // TODO: unhook from cinder events.
}

}

#endif