#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "ciButton.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ButtonSampleApp : public App {
  public:
	void setup() override;
	void update() override;
	void draw() override;
    
    void mouseMove( MouseEvent event ) override;
    void mouseDown( MouseEvent event ) override;
    void mouseDrag( MouseEvent event ) override;
	void mouseUp( MouseEvent event ) override;
    void keyDown( KeyEvent event ) override;
    
    coc::ciButton button;
};

void ButtonSampleApp::setup() {
    
    int sw = getWindowWidth();
    int sh = getWindowHeight();
    
    int w = coc::min(sw, sh) * 0.5;
    int h = w;
    int x1 = (sw - w) * 0.5;
    int y1 = (sh - w) * 0.5;
    int x2 = x1 + w;
    int y2 = y1 + h;
    
    button.setRect(Rectf(x1, y1, x2, y2));
}

void ButtonSampleApp::update() {
    button.update();
    
    // below are button states which can be used to do different things.
    
    if(button.movedInside()) {
        cout << "movedInside" << endl;
    }
    if(button.movedOutside()) {
        cout << "movedOutside" << endl;
    }
    if(button.pressedInside()) {
        cout << "pressedInside" << endl;
    }
    if(button.releasedInside()) {
        cout << "releasedInside" << endl;
    }
    if(button.releasedOutside()) {
        cout << "releasedOutside" << endl;
    }
}

void ButtonSampleApp::draw() {
	
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::color(ColorA(0.1, 0.1, 0.1, 1.0)); // default color.
    if(button.over()) {
        gl::color(ColorA(0.5, 0.5, 1.0, 1.0)); // over color.
    }
    if(button.down()) {
        gl::color(ColorA(1.0, 0.5, 0.5, 1.0)); // down color;
    }
    gl::drawSolidRect(button.getRect());
    
    gl::color(ColorA(0.5, 0.5, 0.5, 1.0));
    gl::drawStrokedRect(button.getRect());
    
    gl::color(ColorA(1, 1, 1, 1));
}

void ButtonSampleApp::mouseMove( MouseEvent event ) {
    button.pointMoved(event.getX(), event.getY());
}

void ButtonSampleApp::mouseDown( MouseEvent event ) {
    button.pointPressed(event.getX(), event.getY());
}

void ButtonSampleApp::mouseDrag( MouseEvent event ) {
    button.pointDragged(event.getX(), event.getY());
}

void ButtonSampleApp::mouseUp( MouseEvent event ) {
    button.pointReleased(event.getX(), event.getY());
}

void ButtonSampleApp::keyDown( KeyEvent event ) {

    // here are some other controlled user cases.
    // where sometimes multiple events come through on the same frame,
    // or when win10 touch events don't fire when they should.

    int cx = getWindowWidth() * 0.5;
    int cy = getWindowHeight() * 0.5;

    if(event.getChar() == '1') {
        button.pointPressed(cx, cy);
        button.pointReleased(cx, cy);
    }
    
    if(event.getChar() == '2') {
        button.pointPressed(cx, cy);
        button.pointDragged(cx, cy);
        button.pointReleased(cx, cy);
    }
}

CINDER_APP( ButtonSampleApp, RendererGl )
