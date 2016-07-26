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

void ButtonSampleApp::update() {
    button.update();
}

void ButtonSampleApp::draw() {
	
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::color(ColorA(0.5, 0.5, 0.5, 1.0));
    gl::drawStrokedRect(button.getRect());
    
    gl::color(ColorA(1, 1, 1, 1));
}

CINDER_APP( ButtonSampleApp, RendererGl )
