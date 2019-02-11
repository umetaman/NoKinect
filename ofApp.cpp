#include "ofApp.h"

bool debugMode = false;
bool fullCVMode = false;
bool guiMode = false;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255);
	cv.setup();
	b_obj.clear();
	setting.loadXML();

	drawScale = ofVec2f(1, 1);

	if (setting.readSucceeded == true) {
		cv.threshold = setting.getThreshold();
		drawScale = setting.getDrawScale();
	}

	
}

//--------------------------------------------------------------
void ofApp::update(){
	cv.update();

	static int frames;

	frames++;

	if (frames % 2 == 0) {
		for (int i = 0; i < gui.getParticleNum(); i++) {
			if (cv.points.size() > 0) {
				int pntIndex = ofRandom(0, cv.points.size());
				ofColor color = ofColor::fromHsb(
					gui.getParticleColor().getHue(),
					gui.getParticleColor().getSaturation(),
					gui.getParticleColor().getBrightness(),
					gui.getParticleColor().a
				);

				ofPoint pnt = cv.points[pntIndex] * drawScale;
				pnt.x += ofRandom(-gui.getRandomScale(), gui.getRandomScale());
				pnt.y += ofRandom(-gui.getRandomScale(), gui.getRandomScale());

				float particleRadius = gui.getParticleRadius();
				b_obj.push_back(Bubble(pnt, ofRandom(-10 + particleRadius, 10 + particleRadius), color));
			}
		}
	}
	
	for (int i = 0; i < b_obj.size(); i++) {
		
		b_obj[i].update();

		if (b_obj[i].endAnimation == true) {
			b_obj.erase(b_obj.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	//デバッグ
	if (debugMode == true && fullCVMode == false) {
		cv.colorImg.draw(0, 0, ofGetWidth() / 2, ofGetHeight() / 2);
		cv.grayImg.draw(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight() / 2);
		cv.grayBgImg.draw(0, ofGetHeight() / 2, ofGetWidth() / 2, ofGetHeight() / 2);
		cv.grayDiffImg.draw(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth() / 2, ofGetHeight() / 2);
	}

	if (fullCVMode == true) {
		cv.colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());
		ofSetColor(255, 230);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	}

	
	if (debugMode == true) {
		ofPushMatrix();
		ofScale(drawScale.x, drawScale.y);
		ofSetColor(255, 0, 255);
		ofSetLineWidth(3);
		for (int i = 0; i < cv.edgeLines.size(); i++) {
			cv.edgeLines[i].draw();
		}
		ofPopMatrix();
	}
	

	/*
	//デバッグ用
	ofPushMatrix();
	ofTranslate(0, ofGetHeight() / 2);
	if (debugMode == true) {
		ofSetColor(255, 75);
		ofDrawRectangle(0, 0, ofGetWidth() / 2, ofGetHeight() / 2);
		ofSetColor(0);
		
		ofDrawBitmapString("edgeLine Scale:\nx: " + ofToString(drawScale.x) + "\n" + "y: " + ofToString(drawScale.y),
			10, 20);
		ofDrawBitmapString("Threshold: " + ofToString(cv.threshold), 10, 80);
		
	}
	ofPopMatrix();
	*/

	if (guiMode == true) {
		gui.draw();
	}

	//Bubbleの描画
	for (int i = 0; i < b_obj.size(); i++) {
		b_obj[i].draw();
	}

	ofSetColor(255, 255, 0);
	//cv.vboMesh.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key){
	case ' ':
		cv.getBgImg = true;
		break;
	
	case '+':
		cv.threshold++;
		break;

	case '-':
		cv.threshold--;
		break;

	case OF_KEY_LEFT:
		drawScale.x += -0.1;
		break;

	case OF_KEY_RIGHT:
		drawScale.x += 0.1;
		break;

	case OF_KEY_UP:
		drawScale.y += -0.1;
		break;

	case OF_KEY_DOWN:
		drawScale.y += 0.1;
		break;

	case OF_KEY_RETURN:
		debugMode = !debugMode;
		break;
	
	case 's':
		setting.setThreshold(cv.threshold);
		setting.setDrawScale(drawScale);
		setting.saveXML();
		break;

	case OF_KEY_SHIFT:
		fullCVMode = !fullCVMode;
		break;

	case 'g':
		guiMode = !guiMode;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
