// updated for OF0.10 - uses ofSoundStreamSettings rather than passing everything into the function. AudioOut & AudioIn now use &soundbuffer and sample.getsample methods

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    /* ****** sound setup ****** */
    
    sampleRate 	= 44100;
    bufferSize	= 1024;
    
    ofSoundStreamSettings soundSettings;
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    
    
    auto devices = soundStream.getDeviceList();
    soundStream.printDeviceList();

    soundSettings.numInputChannels= 0;
    soundSettings.numOutputChannels=2;
    soundSettings.sampleRate = sampleRate;
    soundSettings.bufferSize = bufferSize;
    soundSettings.numBuffers = 4;
    soundSettings.setOutListener(this);
    soundSettings.setOutDevice(devices[1]);
    
    soundStream.setup(soundSettings);
    
    // Load samaples

    kick1.load(ofToDataPath       ("samples/kick-vinyl01.wav"));
    kick2.load(ofToDataPath       ("samples/kick-vinyl01.wav"));
    kick3.load(ofToDataPath       ("samples/kick-vinyl01.wav"));

    snare.load(ofToDataPath       ("samples/snare.wav"));
    sax.load(ofToDataPath         ("samples/sax.wav"));
    
    clock.setTempo(130);
    clock.setTicksPerBeat(3);

    
    env1.setAttack(100);
    env1.setDecay(10);
    env1.setSustain(1000);
    env1.setRelease(1000);
    
    env2.setAttack(25);
    env2.setDecay(10);
    env2.setSustain(100);
    env2.setRelease(1000);
    
    env3.setAttack(30);
    env3.setDecay(1000);
    env3.setSustain(100);
    env3.setRelease(100);
    
    env4.setAttack(50);
    env4.setDecay(10);
    env4.setSustain(100);
    env4.setRelease(1000);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &outBuffer) {
    
    float speed = snare.length / kick1.length;

  	for (size_t i = 0; i < outBuffer.getNumFrames(); i++){
        
        clock.ticker();
        
            env1.trigger = LFO1.phasor(3);
            env2.trigger = LFO2.phasor(3.1);
            env3.trigger = osc1.phasor(3.2);
            env4.trigger = osc1.phasor(3.3);

        if (clock.tick){
            
            kick1.trigger();
            kick2.trigger();
            kick3.trigger();
            snare.trigger();
        }
    
        env1.setRelease(abs(timer1.sinewave(3)*1000)+1);
        env2.setRelease(abs(timer2.sinewave(4)*1000)+1);
        env3.setRelease(abs(timer3.sinewave(5)*1000)+1);
        env4.setRelease(abs(timer4.sinewave(2)*1000)+1);

        
        
        double out1 = kick1.playOnce()*env1.adsr(1.-env2.trigger, env1.trigger);
        double out2 = kick2.playOnce()*env2.adsr(1.-env3.trigger, env2.trigger);
        double out3 = kick3.playOnce()*env3.adsr(1.-env4.trigger, env3.trigger);
        double out4 = snare.playOnce(speed)*env4.adsr(1.-env1.trigger, env4.trigger);

        
        double mixOut = out4 +out3 *.25 + out2 *.25 + out1 *.25;
        
        outBuffer.getSample(i, 0) = mixOut * 0.5;
        outBuffer.getSample(i, 1) = mixOut * 0.5;
    
       
   	}


}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer &input){
    
    for (size_t i = 0; i < input.getNumFrames(); i++){
        
        
   }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
//--------------------------------------------------------------

