#pragma once
#include "ofMain.h"

#define OBJ_SIZE_MIN 10

//イージング係数
#define EASE_CONEFFICIENT 0.09

class Bubble
{
public:
	//コンストラクタ
	Bubble();	//乱数
	Bubble(ofPoint _pos, float _targetRadius, ofColor _color);	//座標と色の設定
	Bubble(const Bubble & BubbleObj);	//コピーコンストラクタ

	//オブジェクト
	ofPoint position;
	float radius = 0;
	float obj_size_max = 40;
	ofColor color;

	//最終的な大きさ
	float targetRadius;

	void update();
	void draw();

	//アニメーション終了判定
	bool endAnimation = false;
	float easeSeed;

	~Bubble();
};

