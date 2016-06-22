/**
 *
 *      ┌─┐╔═╗┌┬┐┌─┐
 *      │  ║ ║ ││├┤
 *      └─┘╚═╝─┴┘└─┘
 *   ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
 *   │  ├─┤║║║└┐┌┘├─┤└─┐
 *   └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
 *
 * Copyright (c) 2014-2016 Code on Canvas Pty Ltd, http://CodeOnCanvas.cc
 *
 * This software is distributed under the MIT license
 * https://tldrlegal.com/license/mit-license
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code
 *
 **/

#pragma once

#include "cocCore.h"

namespace coc {

//--------------------------------------------------------------
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
