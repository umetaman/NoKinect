#pragma once
#include "ofMain.h"
#include "ofxOpenCV.h"

#define WIDTH 640
#define HEIGHT 480

class CamVideo
{
public:
	CamVideo();

	//Web�J��������̉摜�擾
	ofVideoGrabber vidGrabber;

	ofxCvColorImage colorImg;
	ofxCvGrayscaleImage grayImg;
	//�������Ƃ�w�i�C���[�W
	ofxCvGrayscaleImage grayBgImg;
	
	//�w�i�擾�t���O
	bool getBgImg = false;

	//�����摜
	ofxCvGrayscaleImage grayDiffImg;
	//�֊s���o
	ofxCvContourFinder contourFinder;

	//臒l
	int threshold = 0;

	void setup();
	void update();
	
	vector<ofPolyline> edgeLines;
	vector<ofPoint> points;
	ofVboMesh vboMesh;
	
	~CamVideo();
};

