#pragma once
#include "ofMain.h"
#include "ofxOpenCV.h"

#define WIDTH 640
#define HEIGHT 480

class CamVideo
{
public:
	CamVideo();

	//Webカメラからの画像取得
	ofVideoGrabber vidGrabber;

	ofxCvColorImage colorImg;
	ofxCvGrayscaleImage grayImg;
	//差分をとる背景イメージ
	ofxCvGrayscaleImage grayBgImg;
	
	//背景取得フラグ
	bool getBgImg = false;

	//差分画像
	ofxCvGrayscaleImage grayDiffImg;
	//輪郭検出
	ofxCvContourFinder contourFinder;

	//閾値
	int threshold = 0;

	void setup();
	void update();
	
	vector<ofPolyline> edgeLines;
	vector<ofPoint> points;
	ofVboMesh vboMesh;
	
	~CamVideo();
};

