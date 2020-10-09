#include "ofApp.h"

ofApp::ofApp(int port, std::string address) : _port(port), _address(address) {}
void ofApp::setup(){
}
void ofApp::update(){
    while(_receiver.hasWaitingMessages()){
		ofxOscMessage m;
		_receiver.getNextMessage(m);
        if(m.getAddress() == _address){
			auto channel = m.getArgAsInt(0);
			auto status = m.getArgAsInt(1);
			auto pitch = m.getArgAsInt(2);
			auto velocity = m.getArgAsInt(3);
		}
    }
}