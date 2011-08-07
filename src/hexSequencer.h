//
//  hexSequencer.h
//  OP-1 Sequencer
//
//  Created by Zak Henry on 2/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofMain.h"
#include "ofxOP1.h"
#include "threadedMetronome.h"

//class OP1; //forward declaration gives access to member methods

struct Note {
    Note(float scale);
    float scale;
    int midiId;
    bool playing;
    float targetGateX, targetGateY, lastGateX, lastGateY;
    float posX, posY;
    void update(float speed);
    void draw();
    bool drawNote;
    bool moveNote;
};

struct HexGate : public ofBaseApp{
    
    HexGate(float size); //constructor
    int id;
    float posX, posY;
    bool selected, active;
    int turretZeroDir, turretOneDir; //direction
    int turretZeroGate, turretOneGate; //gate turret is pointing at
    int turretActive;
    vector<ofPoint>hexPoints;
    float radius, turretLength, turretWidth;
    void draw();
    int neighbours[6];
    
    vector<Note> notesIncoming;
    vector<Note> notesOutgoing;
    
    ofTrueTypeFont	verdana30, verdana10;
    
};



class HexSequencer : public OP1{
    
    threadedMetronome metro;
    void beatEvent(int &beatCount);
    void subBeatEvent(int &subBeat);
    void stopNotes();
    float currentBeatTime, beatTimestamp, currentBeatProgression;
    
    ofTrueTypeFont	verdana;
    
    float beatIndicatorScale;
    
    float width, height, posX, posY;
    float scale;
    
    float trackLength;
    
    int currentHover;
    
    void moveNotes();
    
//    int blue, green, lightGrey, orange, darkGrey, black, white;
    
    public:
    HexSequencer(); //constructor
    ~HexSequencer(); //destructor
    
    OP1 * op1;
    
    int bpm;
    bool orangeEncoderDown;
    int noteLength;
    string noteLengthName;
    string getNoteLengthName(int noteLength);
    int getGreatestCommonDenominator(int a, int b);

    
    void setPosition(float x, float y, int width);
    void createGates();
    void update(); //update moving vars
    void draw();

    vector<HexGate>gates;
    
    vector<Note>activeNotes;
    
    int neighbourhood [13][6];
    
    void processOP1Event(midiPacket &event);
    
};