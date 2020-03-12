#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
    
        void initializePerson();
        void initializeFace();
    
        void drawText(ofVec2f position);
    
        void drawFace(ofVec2f position);
        void drawEyebrows(ofVec2f position, int angle);
    
        void drawHappyParts(ofVec2f position, int intensity);
        void drawSadParts(ofVec2f position, int intensity);
        void drawAngryParts(ofVec2f position, int intensity);
        void drawSurprisedParts(ofVec2f position, int intensity);

    
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
        
        //gui
        void volumeFloatSliderChanged(float & volumeFloatSlider) ;
        void changeExpressionButtonPressed();
        
        //face variables
        ofColor faceColor;
        ofColor faceOutlineColor;
    
        ofRectangle face;
        ofRectangle faceOutline;
        
        //position vectors of face, offset relative to HEAD ANCHOR
        ofVec2f headAnchor,
                    facePosition, //head anchor
                    leftEyebrowOffset, rightEyebrowOffset,
                    leftEyeOffset, rightEyeOffset,
                    topNoseOffset, leftNoseOffset, rightNoseOffset,
                    sadMouthOffset,happyMouthOffset, angryMouthOffset,surprisedMouthOffset,
                    neckPosition,
        //position vectors of body, offset relative to TORSO ANCHOR
                torsoAnchor,
                    topTorsoOffset, leftTorsoOffset, rightTorsoOffset,
                    leftHandOffset, rightHandOffset,
                    bodyPosition,
        //position vectors of legs, offset relative to HIP ANCHOR
                hipAnchor, hipOffset,
                    leftFootOffset, rightFootOffset,
                    leftFrontFootOffset, rightFrontFootOffset,
                    
                worldPosition;

    
        //face variables
        int strokeThickness = 15;
        int faceWidth = 170;
        int faceHeight = 110;
    
        int eyeDistanceX = 45;
        int eyeDistanceY = 2;
        int eyeSize = 12;

        int eyebrowDistanceX = 33;
        int eyebrowDistanceY = 20;
        int eyebrowWidth = 30;
        int eyebrowHeight = 13;
        int eyebrowRotateAngle = 0;

        int noseWidth = 28;
        int noseHeight = 20;

        int mouthWidth = 26;

    
        //control variables
        ofPoint myMouse;
        ofVec2f currVec;
        ofVec2f targetVec;
        bool moveRight = false;
        bool moveLeft = false;
        int emotionCounter = 0;

        ofSoundPlayer bgm;
        float bgmVolume = 0.2f;
    
        ofxPanel gui;

        ofxFloatSlider volumeFloatSlider;
        ofxButton changeExpressionButton;
        ofxVec2Slider sunVecSlider;
        ofxColorSlider backgroundColorSlider;
        ofxIntSlider emotionalIntSlider;
    
        ofxLabel screenSize;
        

    
};
