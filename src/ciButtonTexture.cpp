//
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://CodeOnCanvas.cc
//
// Created by Rene Christen on 31/05/2016.
// Copyright (c) 2016, Code on Canvas Pty Ltd//

#include "ciButtonTexture.h"

using namespace std;
using namespace ci;
using namespace ci::app;


namespace coc {


void ciButtonTexture::setTexture( ci::gl::TextureRef _tex )
{
	tex = _tex;
}

void ciButtonTexture::draw()
{
	if (tex) {
		gl::draw( tex, rect );
	}
	else {
		ciButton::draw();
	}
}


}