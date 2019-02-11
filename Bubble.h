#pragma once
#include "ofMain.h"

#define OBJ_SIZE_MIN 10

//�C�[�W���O�W��
#define EASE_CONEFFICIENT 0.09

class Bubble
{
public:
	//�R���X�g���N�^
	Bubble();	//����
	Bubble(ofPoint _pos, float _targetRadius, ofColor _color);	//���W�ƐF�̐ݒ�
	Bubble(const Bubble & BubbleObj);	//�R�s�[�R���X�g���N�^

	//�I�u�W�F�N�g
	ofPoint position;
	float radius = 0;
	float obj_size_max = 40;
	ofColor color;

	//�ŏI�I�ȑ傫��
	float targetRadius;

	void update();
	void draw();

	//�A�j���[�V�����I������
	bool endAnimation = false;
	float easeSeed;

	~Bubble();
};

