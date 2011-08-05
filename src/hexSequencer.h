//
//  hexSequencer.h
//  OP-1 Sequencer
//
//  Created by Zak Henry on 2/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofMain.h"
#include "ofxOP1.h"
#include "threadedObject.h"

//class OP1; //forward declaration gives access to member methods

struct Note {
    Note();
    int midiId;
    bool playing;
    float targetX, targetY;
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
    int turretOneDir, turretTwoDir;
    vector<ofPoint>hexPoints;
    float radius, turretLength, turretWidth;
    void draw();
    int neighbours[6];
    
    vector<Note> notesIncoming;
    vector<Note> notesOutgoing;
    
    ofTrueTypeFont	verdana30, verdana10;
    
};



class HexSequencer : public ofBaseApp{
    
    threadedObject	TO;
    void beatEvent(int &beatCount);
    void subBeatEvent(int &subBeat);
    void stopNotes();
    
    float beatIndicatorScale;
    
    float width, height;
    
    float trackLength;
    
    int currentHover;
    
    void moveNotes();
    
//    int blue, green, lightGrey, orange, darkGrey, black, white;
    
    public:
    HexSequencer(); //constructor
    
    OP1 * op1;
    
    void setWidth(int width);
    void createGates();
    void update(); //update moving vars
    void draw();

    vector<HexGate>gates;
    
    vector<Note>activeNotes;
    
    int neighbourhood [13][6];
    
    void processOP1Event(midiPacket &event);
    
};