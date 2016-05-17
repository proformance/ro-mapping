#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "ofx2DMapping.h"
#include "ShapeProperties.h"

#include "ofxLibwebsockets.h"

#include "coord2d.h"
#include "coord3d.h"
#include "Map3Dto2D.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
    void mouseMoved(ofMouseEventArgs &args);
    void mouseDragged(ofMouseEventArgs &args);
    void mousePressed(ofMouseEventArgs &args);
    void mouseReleased(ofMouseEventArgs &args);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxLibwebsockets::Client client;

		// websocket methods
		void onConnect( ofxLibwebsockets::Event& args );
		void onOpen( ofxLibwebsockets::Event& args );
		void onClose( ofxLibwebsockets::Event& args );
		void onIdle( ofxLibwebsockets::Event& args );
		void onMessage( ofxLibwebsockets::Event& args );
		void onBroadcast( ofxLibwebsockets::Event& args );

private:

    ofx2DMapping mapping;

    bool show_controls;

    int ic;

    ShapeProperties sprops;

    ShapeProperties *sp_boxes;
    ShapeProperties *sp_humans;

};
