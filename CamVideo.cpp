#include "CamVideo.h"



CamVideo::CamVideo()
{
}


void CamVideo::setup(){
	//videoGrabber初期化
	vidGrabber.initGrabber(WIDTH, HEIGHT);
	//バッファの確保
	colorImg.allocate(WIDTH, HEIGHT);
	grayImg.allocate(WIDTH, HEIGHT);
	grayBgImg.allocate(WIDTH, HEIGHT);
	grayDiffImg.allocate(WIDTH, HEIGHT);

}

void CamVideo::update(){
	//videoGrabber更新
	vidGrabber.update();

	//新規フレーム取得フラグ
	bool getNewFrame = false;

	getNewFrame = vidGrabber.isFrameNew();

	//フレームを新規取得したとき
	if (getNewFrame == true) {
		colorImg.setFromPixels(vidGrabber.getPixels());
		colorImg.mirror(false, true);
		grayImg = colorImg;

		//背景取得
		if (getBgImg == true) {
			grayBgImg = colorImg;

			//初期化
			getBgImg = false;
		}

		//初期化
		getNewFrame = false;
	}

	//差分画像の生成
	grayDiffImg.absDiff(grayImg, grayBgImg);
	//二値化
	grayDiffImg.threshold(threshold);

	//輪郭線の生成
	contourFinder.findContours(grayDiffImg, 20, (WIDTH*HEIGHT) / 3, 10, true);


	//輪郭線の動的配列をクリア
	edgeLines.clear();
	points.clear();
	//vboMesh.clear();

	//輪郭線から抽出
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
