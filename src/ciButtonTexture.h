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

#pragma once

#include "ciButton.h"
#include "cinder/gl/Texture.h"

// TODO: hover states

namespace coc {

class ciButtonTexture : public ciButton {

public:

	void setTexture( ci::gl::TextureRef _tex );
	ci::gl::TextureRef getTexture() { return tex; }

	void draw() override;


private:

	ci::gl::TextureRef	tex;

};//class ciButtonTexture

}//namespace coc


