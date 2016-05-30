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

#pragma once

#ifdef COC_CI

#include "cocButton.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

namespace coc {

class ciButton : public coc::Button {

public:

    ciButton(coc::Rect rect = coc::Rect());
    
    void mouseMoved(ci::app::MouseEvent & mouse);
    void mousePressed(ci::app::MouseEvent & mouse);
    void mouseDragged(ci::app::MouseEvent & mouse);
    void mouseReleased(ci::app::MouseEvent & mouse);
    
    virtual void handleMovedInside();
    virtual void handleMovedOutside();
    virtual void handlePressedInside();
    virtual void handleDraggedOutside();
    virtual void handleReleasedInside();
    virtual void handleReleasedOutside();
    virtual void handleEventRegister();
    virtual void handleEventUnregister();
    
};

}

#endif


