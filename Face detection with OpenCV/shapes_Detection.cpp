

///////////////  Shape and contour Detection from Image  //////////////////////

/// For original documents:https://www.youtube.com/watch?v=2FYm3GOonhk&t=1357s //


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////// Shape or Contour image function  /////// 


void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;  // Point in subvector in subvector in vector--> {{(point(20,30))},{(point(20,30))},...}
	vector<Vec4i> hierarchy;   // Vect4i--> vector datatype contains 4 intigers

	// call contour functions:
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2); // -1 indicate all contours we want to draw, 2--> make contour wide

	vector<vector<Point>> conPoly(contours.size());  // create contour line of each endge
	vector<Rect> boundRect(contours.size());         //

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;   // shows each area of all contours
		string objectType;

		if (area > 1000)       // area>1000 make as a filter, it will delete noise or unpected contour area
		{
			float peri = arcLength(contours[i], true);                 // create bounding box
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;                        // providesus number edge points
			boundRect[i] = boundingRect(conPoly[i]);                  // boundingRect() is a function and boundingRect[] is variable

			int objCor = (int)conPoly[i].size();          //objcor provides us what type of object, means how many corner of object.        

			if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4)                      // check wheither it is rectangle or Square
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			else if (objCor > 4) { objectType = "Circle"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);  // create reactangle bound box image
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}


int main() {

	string path = "E:/C++project/webimage/Project2/Resources12/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	imwrite("Shape_detction_image.jpg", img);
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);

	return 0;

}