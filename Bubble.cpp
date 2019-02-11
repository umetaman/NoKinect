#include "Bubble.h"



Bubble::Bubble(){
	//cout << "Generate random." << "\n";
	position = ofPoint(
		ofRandom(0, ofGetWidth()),
		ofRandom(0, ofGetHeight())
	);

	targetRadius = ofRandom(OBJ_SIZE_MIN, obj_size_max);
	color = ofColor(
		ofRandom(0, 255),
		ofRandom(0,255),
		ofRandom(0,255)
	);
	easeSeed = ofRandom(0.005, 0.08);
}

Bubble::Bubble(ofPoint _pos, float _targetRadius, ofColor _color){
	position = _pos;
	targetRadius = _targetRadius;
	color = _color;
	easeSeed = ofRandom(0.005, 0.08);
}

Bubble::Bubble(const Bubble & BubbleObj){
	position = BubbleObj.position;
	targetRadius = BubbleObj.targetRadius;
	color = BubbleObj.color;
	easeSeed = ofRandom(0.005, 0.08);
}


void Bubble::update(){
	//‘å‚«‚³‚ÌXV
	if (endAnimation == false) {
		radius = easeSeed + radius * (1 + EASE_CONEFFICIENT);
	}

	if (radius > obj_size_max) {
		endAnimation = true;
		//cout << "ANIMATION is ENDED." << "\n";
	}

	//cout << endAnimation << "\n";
}

void Bubble::draw(){
	ofSetColor(color, ofMap(radius, 0, obj_size_max, 255, 0));
	ofDrawCircle(position, radius);
	//ofDrawCircle(position, targetRadius);
}

Bubble::~Bubble()
{
}
