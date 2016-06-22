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

	virtual void draw();

    virtual void handleMovedInside();
    virtual void handleMovedOutside();
    virtual void handlePressedInside();
    virtual void handleDraggedOutside();
    virtual void handleReleasedInside();
    virtual void handleReleasedOutside();

    virtual void handleEventRegister();
    virtual void handleEventUnregister();

	ci::signals::Signal<void()>& getSignalOnMovedInside() 	{ return signalOnMovedInside; }
	ci::signals::Signal<void()>& getSignalOnMovedOutside() 	{ return signalOnMovedOutside; }
	ci::signals::Signal<void()>& getSignalOnPressedInside() { return signalOnPressedInside; }
	ci::signals::Signal<void()>& getSignalOnDraggedOutside(){ return signalOnDraggedOutside; }
	ci::signals::Signal<void()>& getSignalOnReleasedInside(){ return signalOnReleasedInside; }
	ci::signals::Signal<void()>& getSignalOnReleasedOutside(){return signalOnReleasedOutside; }

private:

	ci::signals::Signal<void()>  signalOnMovedInside;
	ci::signals::Signal<void()>  signalOnMovedOutside;
	ci::signals::Signal<void()>  signalOnPressedInside;
	ci::signals::Signal<void()>  signalOnDraggedOutside;
	ci::signals::Signal<void()>  signalOnReleasedInside;
	ci::signals::Signal<void()>  signalOnReleasedOutside;

	ci::signals::ScopedConnection  cbMouseDown, cbMouseDrag, cbMouseUp, cbMouseMove;

};

}

#endif
