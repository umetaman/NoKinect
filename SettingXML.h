#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"

class SettingXML
{
private:
	int _threshold;
	ofVec2f _drawScale;
	string _fileName;

	void initialize();
public:
	SettingXML();
	SettingXML(string FileName);

	void loadXML();

	void setThreshold(int & Threshold);
	void setDrawScale(ofVec2f & DrawScale);
	void saveXML();

	int getThreshold();
	ofVec2f getDrawScale();

	ofxXmlSettings xml;

	bool readSucceeded = false;

	~SettingXML();
};

