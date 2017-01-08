#include "ofApp.h"
ofApp::ofApp(){
    _midiIn.openVirtualPort("midi2osc");
    _midiIn.addListener(this);

    //_oscSender.setup("192.168.178.10", 8010);
    _oscSender.setup("127.0.0.1", 8010);

    for(int i = 0; i< 32; i++){
        _reds[i] = -1;
        _greens[i] = -1;
        _blues[i] = -1;
    }
}

void ofApp::setup(){}
void ofApp::update(){}
void ofApp::draw(){}
void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}

void ofApp::newMidiMessage(ofxMidiMessage &message)
{
    ofLogNotice()<<"midi message "<<message.channel<<" "<<message.pitch<<" "<<message.velocity;
    auto index = message.pitch;
    int row = -1;
    int column = -1;
    int value = message.velocity * 2;
    if(message.status == MIDI_NOTE_OFF){
        value = 0;
    }

    if(message.channel == 1){
        _reds[index] = value;
    }else if(message.channel == 2){
        _greens[index] = value;
    }else if(message.channel == 3){
        _blues[index] = value;
    }

    if(index < 12){
        row = 0;
    }else if(2 * 12){
        row = 1;
    }else if(3 * 12){
        row = 2;
    }
    column = index - row * 12;

    if(_reds[index] != -1 && _greens[index] != -1 && _blues[index] != -1){
        ofxOscMessage oscMessage;
        oscMessage.setAddress("/pixel");
        oscMessage.addIntArg(column);
        oscMessage.addIntArg(row);
        oscMessage.addIntArg(_reds[index]);
        oscMessage.addIntArg(_greens[index]);
        oscMessage.addIntArg(_blues[index]);
        _oscSender.sendMessage(oscMessage);

        _reds[index] = _greens[index] = _blues[index] = -1;
    }

}

void ofApp::dragEvent(ofDragInfo dragInfo){}
