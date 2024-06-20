#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;


///////////////// Import test Images  //////////////////////

//int main() {
//
//	string path = "Resources12/test1.png";
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//
//}

///////////////  Import Video  //////////////////////

//void main() {
//
//	string path = "resources12/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//
//		cap.read(img);
//		imshow("image", img);
//		waitKey(20);
//	}
//}

/////////////////  Webcam  //////////////////////

void main() {

	VideoCapture cap(0);
	Mat img;

	while (true) {

		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}
