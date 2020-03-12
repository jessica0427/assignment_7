#include "ofApp.h"

//palette
ofColor red(255,0,0);
ofColor black(0,0,0);
ofColor white(255,255,255);
ofColor green(0, 255, 0);
ofColor gray(128, 128, 128);
ofColor cyan(0, 255, 255);
ofColor yellow(255, 255, 0);
ofColor pink(255, 192, 203);

ofVec2f textOffset(50, 50);

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    bgm.load("music.mp3");
    bgm.play();
    bgm.setLoop(true);
    bgm.setVolume(bgmVolume);
    
    volumeFloatSlider.addListener(this, &ofApp::volumeFloatSliderChanged);
    changeExpressionButton.addListener(this, &ofApp::changeExpressionButtonPressed);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(volumeFloatSlider.setup("volume", 0.2f, 0.0f, 1.0f));
    gui.add(backgroundColorSlider.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.add(changeExpressionButton.setup("change expression"));
    gui.add(emotionalIntSlider.setup("emotional", 5, 0, 10));
    
    initializePerson();
    
    currVec.set(ofGetWidth() - 100, 100);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofEnableAlphaBlending();
    
    //update person
    headAnchor.set(ofGetWidth()/2, ofGetHeight()/2 + bobOffset * sin(vertMoveAngle));
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(backgroundColorSlider);
    
    drawText(textOffset);
    drawFace(headAnchor);
    
    if (emotionCounter == 0) {
        //screen auto cleared
    }
    if (emotionCounter == 1) {
        drawHappyParts(headAnchor, emotionalIntSlider);
    }
    if (emotionCounter == 2) {
        drawSadParts(headAnchor, emotionalIntSlider);
    }
    if (emotionCounter == 3) {
        drawAngryParts(headAnchor, emotionalIntSlider);
    }
    if (emotionCounter == 4) {
        drawSurprisedParts(headAnchor, emotionalIntSlider);
    }
    if (emotionCounter == 5) {
        emotionCounter = 0;
    }
    
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a') {
        moveLeft = true;
    }
    if(key == 'd') {
        moveRight = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'a') {
        moveLeft = false;
    }
    if(key == 'd') {
        moveRight = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    targetVec.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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

void ofApp::volumeFloatSliderChanged(float & volumeFloatSlider ) {
    bgm.setVolume(volumeFloatSlider);
}
void ofApp::changeExpressionButtonPressed() {
    emotionCounter++;
}

void ofApp::initializePerson() {
    faceColor = white;
    faceOutlineColor = black;
    
    initializeFace();
    

}
void ofApp::initializeFace() {
    leftEyeOffset.set(-eyeDistanceX, eyeDistanceY);
    rightEyeOffset.set(eyeDistanceX, eyeDistanceY);
    
    leftEyebrowOffset.set(-eyeDistanceX, -eyebrowDistanceY);
    rightEyebrowOffset.set(eyeDistanceX, -eyebrowDistanceY);
    
    topNoseOffset.set(0, -noseHeight/2);
    leftNoseOffset.set(-noseWidth/2, noseHeight/2);
    rightNoseOffset.set(noseWidth/2, noseHeight/2);
    
    sadMouthOffset.set(0, noseHeight + 10);
    angryMouthOffset.set(0, noseHeight + 10);
    happyMouthOffset.set(0, noseHeight + 2);
    surprisedMouthOffset.set(0, noseHeight + 10);
}
void ofApp::drawText(ofVec2f position) {
    ofSetColor(black);

}

void ofApp::drawFace(ofVec2f position) {
    //outline of face
    ofSetColor(faceOutlineColor);
    ofDrawCircle(position, faceWidth/2 + strokeThickness);
    
    //face
    ofSetColor(faceColor);
    ofDrawCircle(position, faceWidth/2);
    
    //eyes
    ofSetColor(faceOutlineColor);
    ofDrawCircle(leftEyeOffset + position, eyeSize);
    ofDrawCircle(rightEyeOffset + position, eyeSize);
    
    //nose
    ofDrawTriangle(topNoseOffset + position, leftNoseOffset + position, rightNoseOffset + position) ;
   
}
void ofApp::drawEyebrows(ofVec2f position, int angle) {
    ofSetRectMode(OF_RECTMODE_CENTER);
    //eyebrows
    ofPushMatrix();
        ofTranslate(leftEyebrowOffset + position);
        ofRotateDeg(-angle);
        ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(rightEyebrowOffset + position);
        ofRotateDeg(angle);
        ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
}

void ofApp::drawHappyParts(ofVec2f position, int intensity) {
    
    ofVec2f offset(0,ofMap(intensity, 0, 10, 4, -10));
    int mouthSize = ofMap(intensity, 0, 10, -5, 10);
    //int angle = ofMap(intensity, 0, 10, 10, 35);
    
    //eyebrows
    drawEyebrows(position + offset, 25);

    //mouth
    ofPath path;
    path.arc(position + happyMouthOffset, noseWidth/2, noseWidth/2 + mouthSize, 0, 180);
    path.setFilled(true);
    path.setFillColor(black);
    path.setStrokeWidth(5);
    path.draw();
}


void ofApp::drawSadParts(ofVec2f position, int intensity) {
    
    ofVec2f offset(0,ofMap(intensity, 0, 10, 0, 10));
    int mouthSize = ofMap(intensity, 0, 10, -5, 10);
    int angle = ofMap(intensity, 0, 10, 10, 45);
    
    //eyebrows
    drawEyebrows(position, angle);
    
    //mouth
    ofPath path;
    path.arc(position + sadMouthOffset + offset, noseWidth/2, noseWidth/2 + mouthSize, -180, 0);
    path.setFilled(true);
    path.setFillColor(black);
    path.setStrokeWidth(5);
    path.draw();
    
}
void ofApp::drawAngryParts(ofVec2f position, int intensity) {
    
    ofVec2f offset(0,ofMap(intensity, 0, 10, 0, 10));
    int mouthSize = ofMap(intensity, 0, 10, -5, 10);
    int angle = ofMap(intensity, 0, 10, -10, -45);
    
    //eyebrows
    drawEyebrows(position, angle);
    
    //mouth
    ofPath path;
    path.arc(position + sadMouthOffset + offset, noseWidth/2, noseWidth/2 + mouthSize, -180, 0);
    path.setFilled(true);
    path.setFillColor(black);
    path.setStrokeWidth(5);
    path.draw();
    
}
void ofApp::drawSurprisedParts(ofVec2f position, int intensity) {
    
    ofVec2f offset(0,ofMap(intensity, 0, 10, 5, -10));
    float mouthSize = ofMap(intensity, 0, 10, 0.5f, 1.2f);
    int angle = ofMap(intensity, 0, 10, -10, -45);
    
    //eyebrows
    drawEyebrows(position + offset, 0);
    
    //mouth
    ofPushMatrix();
        ofTranslate(position + surprisedMouthOffset);
        ofScale(1, mouthSize); //to change the mouth shape
        ofDrawCircle(0, 0, mouthWidth/2);
    ofPopMatrix();
    
}





