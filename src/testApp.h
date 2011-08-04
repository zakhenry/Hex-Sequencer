#pragma once

#include "ofMain.h"
#include "ofxOP1.h"
#include "hexSequencer.h"

//class Program : public IScreen
//{
//public:
//    // Here we actually implement it
//    virtual void drawScreen()
//    {
//        // Draw some stuff here
//    }
//};

class testApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void op1Event(midiPacket &packet);
    
        HexSequencer sequencer;
        OP1 op1;
    
        
        
    
//        Program prog;
//        IScreen *isprog = dynamic_cast<IScreen*>(&prog);
//        OP1 comp1(isprog);
//        comp1.drawScreen();
        
		
};
