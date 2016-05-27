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

	ciButton();

	void mouseMoved(ci::app::MouseEvent & mouse);
	void mouseDragged(ci::app::MouseEvent & mouse);
	void mousePressed(ci::app::MouseEvent & mouse);
	void mouseReleased(ci::app::MouseEvent & mouse);

#ifdef CINDER_COCOA_TOUCH
	//todo: touch events
#endif

protected:

	//

};//class ciScrollView

}//namespace coc

#endif


