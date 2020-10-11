#include "ofAppNoWindow.h"
#include "ofApp.h"
#include "ofxCommandLineUtils.h"

// ./bin/example-commandlineargs.app/Contents/MacOS/example-commandlineargs -v -d -p 8000 -h localhost

int main(int argc, char *argv[])
{
    cxxopts::Options options("ofOSC2MIDI", "OSC to MIDI bridge");
    options.add_options()("d,debug", "Enable debugging")
        ("l,list", "list", cxxopts::value<bool>()->default_value("false"))
        ("p,port", "port", cxxopts::value<int>()->default_value("1883"))
        ("m,midiport", "midiport", cxxopts::value<int>()->default_value("0"))
        ("a,address", "address", cxxopts::value<std::string>()->default_value("/ofOSC2MIDI"));
    auto result = options.parse(argc, argv);

    ofAppNoWindow window;
    ofSetupOpenGL(&window, 640, 480, OF_WINDOW);

    auto app = new ofApp(
        result["p"].as<int>(),
        result["a"].as<std::string>(),
        result["m"].as<int>()
        );
    if(result["l"].as<bool>()){
        app->listPorts();
        return 0;
    }
	return ofRunApp(app);
}