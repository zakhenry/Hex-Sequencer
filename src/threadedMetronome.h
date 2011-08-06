#ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"

// this is not a very exciting example yet
// but ofThread provides the basis for ofNetwork and other
// operations that require threading.
//
// please be careful - threading problems are notoriously hard
// to debug and working with threads can be quite difficult


class threadedMetronome : public ofThread{

	public:
    
        ofEvent<int> beat;
        ofEvent<int> subBeat;


	    int beatNum;
        int bpm;
        float millisPerSubBeat;
        int subBeatSubdivision;
    
    
    // threaded fucntions that share data need to use lock (mutex)
	                // and unlock in order to write to that data
	                // otherwise it's possible to get crashes.
	                //
	                // also no opengl specific stuff will work in a thread...
	                // threads can't create textures, or draw stuff on the screen
	                // since opengl is single thread safe

		//--------------------------
		threadedMetronome(){
			beatNum = 0;
            bpm = 120;
            subBeatSubdivision = 32;
            millisPerSubBeat = 60000/(bpm*subBeatSubdivision);
		}

		void start(){
            startThread(true, false);   // blocking, verbose
        }

        void stop(){
            stopThread();
        }
    
        void setBPM(int _bpm){
            bpm = _bpm;
            millisPerSubBeat = 60000/(bpm*subBeatSubdivision);
        }

		//--------------------------
		void threadedFunction(){

			while( isThreadRunning() != 0 ){
				if(lock()){
					beatNum++;
					if(beatNum > subBeatSubdivision-1){
                        beatNum = 0;
                        ofNotifyEvent(beat, beatNum, this);
                    }
                    ofNotifyEvent(subBeat, beatNum, this);
					unlock();
					ofSleepMillis(millisPerSubBeat);
				}
			}
		}

		//--------------------------
		void draw(){

			string str = "I am a slowly increasing thread. \nmy current count is: ";

			if( lock() ){
				str += ofToString(beatNum);
				unlock();
			}else{
				str = "can't lock!\neither an error\nor the thread has stopped";
			}
			ofDrawBitmapString(str, 50, 56);
		}



};

#endif
