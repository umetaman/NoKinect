#include "SettingXML.h"



void SettingXML::initialize(){
	_threshold = 0;
	_drawScale = ofVec2f(1, 1);
}

SettingXML::SettingXML(){
	_fileName = "settings.xml";
	initialize();
}

SettingXML::SettingXML(string FileName) {
	_fileName = FileName;
	initialize();
}

void SettingXML::loadXML(){
	readSucceeded = xml.loadFile(_fileName);

	if (readSucceeded == true) {
		cout << "========================" << "\n";
		cout << "     XML is LOADED." << "\n";
		cout << "========================" << "\n";
	}
	else {
		cout << "========================" << "\n";
		cout << "      F A I L E D ." << "\n";
		cout << "========================" << "\n";
		
		xml.addTag("THRESHOLD");
		xml.addTag("DRAWSCALE");
	}
}

void SettingXML::setThreshold(int & Threshold){
	_threshold = Threshold;
	xml.setValue("THRESHOLD", _threshold);
}

void SettingXML::setDrawScale(ofVec2f & DrawScale){
	_drawScale = DrawScale;
	xml.pushTag("DRAWSCALE");
	xml.setValue("X", _drawScale.x * 10);
	xml.setValue("Y", _drawScale.y * 10);
	xml.popTag();
}

void SettingXML::saveXML(){
	xml.saveFile(_fileName);
}

int SettingXML::getThreshold(){
	int retThreshold;
	
	retThreshold = xml.getValue("THRESHOLD", 0);
	
	return retThreshold;
}

ofVec2f SettingXML::getDrawScale(){
	ofVec2f retVec;

	retVec.x = float(xml.getValue("DRAWSCALE:X", 0)) / 10;
	retVec.y = float(xml.getValue("DRAWSCALE:Y", 0)) / 10;

	return retVec;
}


SettingXML::~SettingXML()
{
}
