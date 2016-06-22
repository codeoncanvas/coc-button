/**
 *
 * Copyright (c) 2014-2016 Code on Canvas Pty Ltd, http://codeoncanvas.cc
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
//  cocButton.h
//  Created by Lukasz Karluk on 2/06/2014.
//  http://codeoncanvas.cc
//

#pragma once

#include "cocCore.h"

namespace coc {

//--------------------------------------------------------------
/** @brief class Button in coc-button */
class Button {

public:

    Button(coc::Rect rect = coc::Rect());
    ~Button();

    void setRect(coc::Rect rect);
    void setRect(float x, float y, float w, float h);
    const coc::Rect & getRect() const;

    void setEnabled(bool value);
    void setUseHandlers(bool value);
    void setUpdateAsync(bool value);
    void setRegisterEvents(bool value);

	void moveTo( int x, int y);
	void moveCenterTo( int x, int y);

    const glm::ivec2 & getPointPosLast();

    void update();

    bool over() const;
    bool overChanged() const;
    bool down() const;
    bool downChanged() const;

    bool movedInside();
    bool movedOutside();
    bool pressedInside();
    bool draggedOutside();
    bool releasedInside();
    bool releasedOutside();

	void pointMoved(int x, int y);
    void pointPressed(int x, int y);
	void pointDragged(int x, int y);
	void pointReleased(int x, int y);

    virtual void handleMovedInside(){};
    virtual void handleMovedOutside(){};
    virtual void handlePressedInside(){};
    virtual void handleDraggedOutside(){};
    virtual void handleReleasedInside(){};
    virtual void handleReleasedOutside(){};
    virtual void handleEventRegister(){};
    virtual void handleEventUnregister(){};

protected:

    coc::Rect rect;
    bool bEnabled;
    bool bUseHandlers;
    bool bUpdateAsync;
    bool bRegisterEvents;

    coc::Value<bool> bOver;
    coc::Value<bool> bDown;
    glm::ivec2 pointPos;
};

}
