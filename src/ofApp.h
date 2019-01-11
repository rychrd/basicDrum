#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // Audio output and input methods...OF 0.10 style with a buffer object
    
        void audioOut(ofSoundBuffer &outBuffer);
        void audioIn(ofSoundBuffer &input);
    
        double length, kickEnv;
    
        int           bufferSize, counter;
        int           sampleRate;
    
		maxiSample    kick1, kick2, kick3, kick4, snare, sax;
		maxiOsc       LFO1, LFO2, osc1, osc2, osc3, osc4, timer1, timer2, timer3, timer4;
        maxiClock     clock;
        maxiEnv       env1, env2, env3, env4;
    
        ofSoundStream soundStream;
    
};
