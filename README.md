# ofOSC2MIDI

## Build status
[![Build Status](https://travis-ci.com/thomasgeissl/ofOSC2MIDI.svg?branch=master)](https://travis-ci.com/thomasgeissl/ofOSC2MIDI)

## Description
Command line util to convert osc messages to midi messages.
Please note that this is still a work in progress. 

## Installation
### osx
```
brew tap thomasgeissl/tools
brew install ofosc2midi
# brew upgrade ofosc2midi
```

## Usage
* noteon: (channel, status, note, velocity), e.g. ofOSCDebugger -h 127.0.0.1 -p 8000 -m "/ofOSC2MIDI 1 144 60 127"
* noteoff: (channel, status, note, velocity), e.g. ofOSCDebugger -h 127.0.0.1 -p 8000 -m "/ofOSC2MIDI 1 128 60 127"
* program change: (channel, status, value), e.g. ofOSCDebugger -h 127.0.0.1 -p 8000 -m "/ofOSC2MIDI 1 192 1"
* control change: (channel, status, control, value), e.g. ofOSCDebugger -h 127.0.0.1 -p 8000 -m "/ofOSC2MIDI 1 224 1 127"
* pitch bend: (channel, status, value), e.g. ofOSCDebugger -h 127.0.0.1 -p 8000 -m "/ofOSC2MIDI 1 176 127"
* polyaftertouch: (channel, status, pitch, value), e.g. ofOSCDebugger -h 127.0.0.1 -p 8000 -m "/ofOSC2MIDI 1 160 60 127"


* list midi ports: `ofOSCMIDI -l`
* listen: `ofOSCMIDI -a /ofOSC2MIDI -p 8000 -m 0`

## TODO
* MIDI2OSC
* add to brew tap