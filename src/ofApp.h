#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxApp.h"
#include "ofxMidi.h"

class ofApp : public ofxApp {
	public:
        ofApp(int port, std::string address, int midiPort);
		void setup();
		void update();

        void listPorts();

        ofxOscReceiver _receiver;
        ofxMidiOut _midiOut;
        ofxMidiOut _virtualMidiOut;
    
        std::vector<std::string> _messages;
        int _port;
        std::string _address;
        int _midiPort;
};
