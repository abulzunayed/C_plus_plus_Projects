
///////////      OpenCV image processing with important Functions     //////////////////////


/// For original documents:https://www.youtube.com/watch?v=2FYm3GOonhk&t=1357s //

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void getContours(Mat imgDil, Mat img);

int main() {

	//string path = "Resources12/test.jpg";
	//Mat img = imread(path);
	//imshow("Image", img);
	//imwrite("Massi_image.jpg", img);


	/////////////// covert to Gray scale image:
	//Mat imgGray;
	//cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//imshow("grayimage", imgGray);
	//imwrite("Gray_image.jpg", imgGray);


	////// covert Gassiun Burr image :
	//Mat imgBlurr;
	//GaussianBlur(img, imgBlurr, Size(3,3),3,0);
	//imshow("blurrimage", imgBlurr);


	////// Canny image detector:
	//Mat imgCanny;
	//Canny(imgBlurr, imgCanny, 50, 150);
	//imshow("cannyimage", imgCanny);
	//imwrite("canny_image.jpg", imgCanny);

	//// Dailation Image:( make image edge as a solid wide line and Better than Canny)
	//Mat imgDial;
	//Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));   // create kernel for filter
	//dilate(imgCanny, imgDial, kernel);
	//imshow("dialationimage", imgDial); 
	

	//// Erode Image (decrease Canny image):
	//Mat imgErode;
	//erode(imgDial, imgErode, kernel);
	//imshow("erodeimage", imgErode);

	//// resize image:
	//Mat imgResize;
	//cout <<"Original Image SIZE:"<< img.size() << endl;
	//resize(img, imgResize, Size(680, 280));
	//cout << "Original Image SIZE:" << imgResize.size() << endl;
	//imshow("resize_image", imgResize);
	

	//// Decrease scaling of image:
	//Mat imgResize1;
	//resize(img, imgResize1, Size(), 0.5, 0.5);
	//cout << "Original Image SIZE:" << imgResize1.size() << endl;
	//imshow("Resclae_image", imgResize1);

	//// Crop  of image:
	//Mat imgCrop;
	//Rect roi(200, 100, 300, 300);  // Defined rectangle co-ordinate
	//imgCrop = img(roi);
	//imshow("Crop_image", imgCrop);




	////////////  Draw Shape and text on Image/////
	//// 
	//// Blank Image 
	//// Here CV_U8UC_3 create 8 bit(0 to 255) unsigned 3 channel image
	//// Here Scalar(255,255,255) create white color Blank image

	//Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); 

	//circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED); // create Circle on white rectanle box
	//rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED); // create reactangle on white rectanle box
	//line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	//putText(img, "Zunayed's OpenCV", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);

	//imshow("Image", img);


	///////////////  Warp Images  //////////////////////

	//string path = "Resources12/cards.jpg";
	//Mat img = imread(path);
	//Mat matrix, imgWarp;
	//float w = 250, h = 350;  // destination card size

	//// Point2 indicate floating data type and get poinst values via Opening seperate Paint(image editor) of normal Xp windows

	//Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };  // source image
	//Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };      // destination image

	//// create transformation matrix from source image to destination image:
	//matrix = getPerspectiveTransform(src, dst);

	//// create Croped Wrap image:
	//warpPerspective(img, imgWarp, matrix, Point(w, h));

	//// Make mark point on our targeted wrap image with 4 coordinate points:
	//for (int i = 0; i < 4; i++)
	//{
	//	circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	//}

	//imshow("Image", img);
	//imshow("Image Warp", imgWarp);



	///////////////  Color Decttion from Image  //////////////////////


	//string path = "E:/C++project/webimage/Project2/Resources12/shapes.png";
	//Mat img = imread(path);
	//Mat imgHSV, mask;
	//// How knows these value?    Ans: Use TrackBar windows      /////
	//int hmin = 0, smin = 0, vmin = 0;
	//int hmax = 179, smax = 255, vmax = 255;

	//// make Huge satuaration image(HSV):
	//cvtColor(img, imgHSV, COLOR_BGR2HSV);

	//// create TrackBar for color detection:

	//namedWindow("Trackbars", (640, 200));
	//createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	//createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	//createTrackbar("Sat Min", "Trackbars", &smin, 255);
	//createTrackbar("Sat Max", "Trackbars", &smax, 255);
	//createTrackbar("Val Min", "Trackbars", &vmin, 255);
	//createTrackbar("Val Max", "Trackbars", &vmax, 255);

	//while (true) {

	//	Scalar lower(hmin, smin, vmin);
	//	Scalar upper(hmax, smax, vmax);

	//	// collect color from image via inrange() function:
	//	inRange(imgHSV, lower, upper, mask);

	//	imshow("Image", img);
	//	imshow("Image HSV", imgHSV);
	//	imshow("Image Mask", mask);
	//	waitKey(1);
	//}


///////////////  Shape and contour Detection from Image  //////////////////////

	string path = "E:/C++project/webimage/Project2/Resources12/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDial, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDial, kernel);

	getContours(imgDial, img);

	imshow("Image", img);
	//imshow("image gray", imgGray);
	//imshow("image blur", imgBlur);
	//imshow("image canny", imgCanny);
	//imshow("image dil", imgDial);

	waitKey(0);


	return 0;
}

/////// Contour image fimction  /////// 


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