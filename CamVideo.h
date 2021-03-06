#pragma once
#include "ofMain.h"
#include "ofxOpenCV.h"

#define WIDTH 640
#define HEIGHT 480

class CamVideo
{
public:
	CamVideo();

	//WebJ©çÌææ¾
	ofVideoGrabber vidGrabber;

	ofxCvColorImage colorImg;
	ofxCvGrayscaleImage grayImg;
	//·ªðÆéwiC[W
	ofxCvGrayscaleImage grayBgImg;
	
	//wiæ¾tO
	bool getBgImg = false;

	//·ªæ
	ofxCvGrayscaleImage grayDiffImg;
	//Öso
	ofxCvContourFinder contourFinder;

	//èl
	int threshold = 0;

	void setup();
	void update();
	
	vector<ofPolyline> edgeLines;
	vector<ofPoint> points;
	ofVboMesh vboMesh;
	
	~CamVideo();
};

