#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class GUI
{
private:
	ofxFloatSlider particleRadius;
	
	//HSB
	ofxFloatSlider colorElement[4];
	ofColor particleColor;
	
	ofxIntSlider randomScale;
	ofxIntSlider particleNum;

public:
	GUI();

	//GUIの基本的な部分
	ofxPanel gui;

	float getParticleRadius();
	ofColor getParticleColor();
	int getRandomScale();
	int getParticleNum();

	void draw();

	~GUI();
};

