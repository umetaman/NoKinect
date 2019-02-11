#include "GUI.h"


GUI::GUI(){
	//パラメーターの初期値を設定

	//ParticleRadius
	float initRadius = 40;
	float minRadius = 15;
	float maxRadius = 200;

	//randomScale
	int initScale = 5;
	int minScale = 1;
	int maxScale = 50;

	//particleNum
	int initParticleNum = 10;
	int minParticleNum = 1;
	int maxParticleNum = 25;

	string elementName[4];
	elementName[0] = "HUE";
	elementName[1] = "SATUATION";
	elementName[2] = "BRIGHTNESS";
	elementName[3] = "ALPHA";

	gui.setup();
	for (int i = 0; i < 4; i++) {
		gui.add(colorElement[i].setup(elementName[i], 125, 0, 255));
	}
	gui.add(particleRadius.setup("RADIUS", initRadius, minRadius, maxRadius));
	gui.add(randomScale.setup("RANDOM_SCALE", initScale, minScale, maxScale));
	gui.add(particleNum.setup("PARTICLE_NUM", initParticleNum, minParticleNum, maxParticleNum));
}

float GUI::getParticleRadius(){
	return particleRadius;
}

ofColor GUI::getParticleColor(){
	particleColor = ofColor::fromHsb(
		colorElement[0], colorElement[1], colorElement[2], colorElement[3]
	);

	return particleColor;
}

int GUI::getRandomScale(){
	return randomScale;
}

int GUI::getParticleNum(){
	return particleNum;
}


void GUI::draw(){
	gui.draw();
}

GUI::~GUI()
{
}
