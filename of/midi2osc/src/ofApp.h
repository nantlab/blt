#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxMidi.h"

class ofApp :
        public ofBaseApp,
        public ofxMidiListener
{

public:
    ofApp();
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void newMidiMessage(ofxMidiMessage & message);

private:
    ofxOscSender _oscSender;
    ofxMidiIn _midiIn;
    int _reds[32];
    int _greens[32];
    int _blues[32];
};
