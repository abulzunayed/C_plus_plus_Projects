

///////////////  Face detection from Images  //////////////////////

// original documents: https://www.youtube.com/watch?v=2FYm3GOonhk&t=1357s
//  https://www.computervision.zone/topic/chapter-8-face-detection/


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


void main() {

	string path = "E:/C++project/webimage/Project2/Resources12/Maria_Sharapova.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources12/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 10); // .tl--> top left and .br --> bottom right
	}

	imshow("Image", img);

	//// Crop Face Detected image:
	Mat imgCrop, imgResize;
	Rect roi(150, 20, 900, 700);  // Defined rectangle co-ordinate
	imgCrop = img(roi);
	resize(imgCrop, imgResize, Size(), 0.5, 0.5);

	imshow("Crop_image", imgResize);
	//imwrite("Face_detected_image.png", imgResize);
	waitKey(0);
}