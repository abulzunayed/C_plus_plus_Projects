#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;


///////////////// Import test Images  //////////////////////

/* int main() {

	string path = "E:/C++project/Image_processing_opencv/image/test.jpg";
	Mat img = imread(path);      // here, mat is matrix data type.
	imshow("Image", img);
	waitKey(0);

} */

///////////////  Import Video  //////////////////////

/* void main() 
{

	string path = "E:/C++project/Image_processing_opencv/image/test_video.mp4";
	VideoCapture cap(path);
	Mat img;

	while (true) {

		cap.read(img);
		imshow("image", img);
		waitKey(10);
	}
} */

/////////////////  Webcam  //////////////////////

void main() 
{

	VideoCapture cap(0);
	Mat img;

	while (true) {

		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}

gdfsdjdks




