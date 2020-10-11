#!/bin/sh
cd "$(dirname "$0")"
cd ..
make -j4
mkdir ofOSC2MIDI
cp -R bin ofOSC2MIDI


zip -r ofOSC2MIDI_osx_version.zip ofOSC2MIDI
openssl dgst -sha256 ofOSC2MIDI_osx_version.zip