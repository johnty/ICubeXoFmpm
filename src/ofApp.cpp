#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofxMidiIn::listPorts();
    ofxMidiOut::listPorts();
    
    myICubeX.connectMidiOut(0);
    myICubeX.connectMidiIn(0);
    myICubeX.setMode(0);
    myICubeX.setStream(true, 0);
    
    yarp.init();
    port.open("/I-CubeX");
    
    ofSetWindowShape(400, 300);
    ofSetFrameRate(60);
}



//--------------------------------------------------------------
void ofApp::update(){
    
    sensorVal = myICubeX.getSensorData(0);
    yarp::os::Bottle* bot;
    bot = &port.prepare();
    bot->clear();
    bot->add(sensorVal);
    port.write();
    ofSleepMillis(5);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0); //set background to black
    float x = ofGetWidth()/2;
    float y = ofGetHeight()/2;
    
    ofSetCircleResolution(120);
    ofSetColor(200, 200, 200); //set drawing colour to grey-ish white
    ofCircle(x, y, 10+1.5*sensorVal); // draw a circle proportional to sensor value
    
    string some_text = "sensor 0 val = " + ofToString(sensorVal);
    ofDrawBitmapString(some_text, 10, 10);
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
