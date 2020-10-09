#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp {
	public:
        ofApp(int port, std::string address);
		void setup();
		void update();

        ofxOscReceiver _receiver;
        ofxMidiOut _midiOut;
    
        std::vector<std::string> _messages;
        int _port;
        std::string _address;
};
