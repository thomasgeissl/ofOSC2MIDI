#include "ofApp.h"

ofApp::ofApp(int port, std::string address, int midiPort) : _port(port), _address(address), _midiPort(midiPort) {}
void ofApp::setup(){
    ofSetFrameRate(60);
    _receiver.setup(_port);
    if(_midiPort < _midiOut.getNumOutPorts()){
        _midiOut.openPort(_midiPort);
    }else{
        ofLogError() << "invalid port index";
        listPorts();
        ofExit();
    }
    _virtualMidiOut.openVirtualPort("ofOSC2MIDI");
}
void ofApp::update(){
    while(_receiver.hasWaitingMessages()){
		ofxOscMessage m;
		_receiver.getNextMessage(m);
        if(m.getAddress() == _address){
            auto numberOfArguments = m.getNumArgs();
            if(numberOfArguments >= 3){

			auto channel = m.getArgAsInt(0);
			auto status = m.getArgAsInt(1);

            switch(status){
                case MIDI_NOTE_ON: {
                    if(numberOfArguments >= 4){
                        _virtualMidiOut.sendNoteOn(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                        _midiOut.sendNoteOn(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                    }else{
                        ofLogError() << "invalid number of arguments";
                    }
                    break;
                }
                case MIDI_NOTE_OFF: {
                    if(numberOfArguments >= 4){
                        _virtualMidiOut.sendNoteOff(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                        _midiOut.sendNoteOff(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                    }else{
                        ofLogError() << "invalid number of arguments";
                    }
                    break;
                }
                case MIDI_PITCH_BEND : {
                    if(numberOfArguments >= 3){
                        _virtualMidiOut.sendPitchBend(channel, m.getArgAsInt(2));
                        _midiOut.sendPitchBend(channel, m.getArgAsInt(2));
                    }else{
                        ofLogError() << "invalid number of arguments";
                    }
                    break;
                }
                case MIDI_POLY_AFTERTOUCH : {
                    if(numberOfArguments >= 4){
                        _virtualMidiOut.sendPolyAftertouch(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                        _midiOut.sendPolyAftertouch(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                    }else{
                        ofLogError() << "invalid number of arguments";
                    }
                    break;
                }
                case MIDI_CONTROL_CHANGE: {
                    if(numberOfArguments >= 4){
                        _virtualMidiOut.sendControlChange(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                        _midiOut.sendControlChange(channel, m.getArgAsInt(2), m.getArgAsInt(3));
                    }else{
                        ofLogError() << "invalid number of arguments";
                    }
                    break;
                }
                case MIDI_PROGRAM_CHANGE: {
                    if(numberOfArguments >= 3){
                        _virtualMidiOut.sendProgramChange(channel, m.getArgAsInt(2));
                        _midiOut.sendProgramChange(channel, m.getArgAsInt(2));
                    }else{
                        ofLogError() << "invalid number of arguments";
                    }
                    break;
                }
                // TODO: SYSEX, ...
                default: {
                    break;
                }
            }
            }else{
                ofLogError("") << "invalid number of arguments";
            }
            
		}
    }
}


void ofApp::listPorts(){
    _midiOut.listOutPorts();
}