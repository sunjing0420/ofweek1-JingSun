#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    for(int i=0; i<1000; i++){
        
    newPos[i] = ofVec2f(ofGetWindowWidth() / 2+50*(2*cos(i*0.1)-cos(i*0.2)), ofGetWindowHeight() / 2+ 50*(2*sin(i*0.1)-sin(i*0.2)));
    Pos[i] = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    Velocity[i] = ofVec2f(ofRandom(-1, 1) * 50*(2*cos(i*0.1)-cos(i*0.2)), ofRandom(-1, 1) * 50*(2*sin(i*0.1)-sin(i*0.2)));
    
    Acceleration[i] = ofVec2f(0, 0);
    red[i] = 255;
    green[i] = ofRandom(100,150);
    blue[i] = ofRandom(0, 255);
    alpha[i] = 0;
    size[i] = 5;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < 1000; i++) {
        Velocity[i] += Acceleration[i];
        Velocity[i] *= Friction;
        float distance = ofDist(Pos[i].x, Pos[i].y, newPos[i].x, newPos[i].y);

        newPos[i] += Velocity[i];
        alpha[i] = ofMap(distance, 0, 400, 255, 0);
        size[i] = ofMap(distance, 0, 400, 10, 20);
    }
    
    alphaGo += 0.05;

}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i=0; i<1000; i++){
        ofSetColor(red[i], green[i], green[i], alpha[i]-alphaGo);
        ofDrawCircle(newPos[i], size[i]);
        
    }
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    ofVec2f mousePos = ofVec2f(x, y);
    for(int i=0; i<1000;i++){
        Pos[i]=mousePos;

        newPos[i].x = x+50*(2*cos(i*0.1)-cos(i*0.2));
        newPos[i].y = y+50*(2*sin(i*0.1)-sin(i*0.2));
        Velocity[i] = ofVec2f(ofRandom(-1, 1) * (2*cos(i*0.1)-cos(i*0.2)), ofRandom(-1, 1) * (2*sin(i*0.1)-sin(i*0.2)));
        
        
        alpha[i] = 255;
        red[i] = 255;
        green[i] = ofRandom(100, 150);
        blue[i] = ofRandom(0, 255);
        Acceleration[i] = ofVec2f(0, 0);
    

    }
    alphaGo=0;
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
