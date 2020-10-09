#include "ofApp.h"

ofApp::ofApp(int port, std::string address) : _port(port), _address(address) {}
void ofApp::setup(){
}
void ofApp::update(){
    while(_receiver.hasWaitingMessages()){
		ofxOscMessage m;
		_receiver.getNextMessage(m);
        if(m.getAddress() == _address){
            // TODO: check arg count
			auto channel = m.getArgAsInt(0);
			auto status = m.getArgAsInt(1);
			// auto pitch = m.getArgAsInt(2);
			// auto velocity = m.getArgAsInt(3);

            switch(status){
                case MIDI_NOTE_ON: {
            // _midiOut.sendNoteOn(channel, pitch, velocity);
                    break;
                }
                case MIDI_NOTE_OFF: {
                    // _midiOut.sendNoteOff(channel, pitch, velocity);
                    break;
                }
                // TODO: CC, SYSEX, AFTERTOUCH, ...
                default {
                    break;
                }
            }
		}
    }
}