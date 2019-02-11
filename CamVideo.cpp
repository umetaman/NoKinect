#include "CamVideo.h"



CamVideo::CamVideo()
{
}


void CamVideo::setup(){
	//videoGrabber������
	vidGrabber.initGrabber(WIDTH, HEIGHT);
	//�o�b�t�@�̊m��
	colorImg.allocate(WIDTH, HEIGHT);
	grayImg.allocate(WIDTH, HEIGHT);
	grayBgImg.allocate(WIDTH, HEIGHT);
	grayDiffImg.allocate(WIDTH, HEIGHT);

}

void CamVideo::update(){
	//videoGrabber�X�V
	vidGrabber.update();

	//�V�K�t���[���擾�t���O
	bool getNewFrame = false;

	getNewFrame = vidGrabber.isFrameNew();

	//�t���[����V�K�擾�����Ƃ�
	if (getNewFrame == true) {
		colorImg.setFromPixels(vidGrabber.getPixels());
		colorImg.mirror(false, true);
		grayImg = colorImg;

		//�w�i�擾
		if (getBgImg == true) {
			grayBgImg = colorImg;

			//������
			getBgImg = false;
		}

		//������
		getNewFrame = false;
	}

	//�����摜�̐���
	grayDiffImg.absDiff(grayImg, grayBgImg);
	//��l��
	grayDiffImg.threshold(threshold);

	//�֊s���̐���
	contourFinder.findContours(grayDiffImg, 20, (WIDTH*HEIGHT) / 3, 10, true);


	//�֊s���̓��I�z����N���A
	edgeLines.clear();
	points.clear();
	//vboMesh.clear();

	//�֊s�����璊�o
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		ofPolyline line;

		for (int j = 0; j < contourFinder.blobs[i].pts.size(); j++) {
			ofPoint pnt = contourFinder.blobs[i].pts[j];
			
			points.push_back(pnt);
			line.addVertex(pnt);
			//vboMesh.addVertex(pnt);
		}

		edgeLines.push_back(line);
	}
}

CamVideo::~CamVideo()
{
}
