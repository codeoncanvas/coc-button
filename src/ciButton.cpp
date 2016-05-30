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