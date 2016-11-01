#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVec2f Pos[1000];
    ofVec2f newPos[1000];
    ofVec2f Velocity[1000];
    ofVec2f Acceleration[1000];
    
    int size[1000];
    
    int alpha[1000];
    float alphaGo;
    
    int red[1000];
    int green[1000];
    int blue[1000];
    
    float Friction=0.99;
		
};
