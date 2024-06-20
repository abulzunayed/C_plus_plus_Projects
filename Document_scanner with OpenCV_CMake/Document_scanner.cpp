
///////////////// Project name: Document scanner  //////////////////////

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat imgOriginal, imgGray, imgCanny, imgBlurr, imgDial, imgErode, imgThre,  imgWarp, imgCrop;
vector<Point> initialPoints, docPoints;
float w= 420, h = 596;  // dimension of standard A4 papaer

////// Define function for image Preprecessing:
Mat prepocessing(Mat img)
{
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlurr, Size(3,3),3,0);
    Canny(imgBlurr, imgCanny, 50, 150);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));   // create kernel for filter
	dilate(imgCanny, imgDial, kernel);
    //erode(imgDial, imgErode, kernel);
    return imgCanny;

}

////// Define function for getting contour or shape of image:
vector<Point> getContours(Mat image) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	vector<Point> biggest;
	int maxArea=0;

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;

		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			if (area > maxArea && conPoly[i].size()==4 )     // check whether corner is 4 or rectangle
            {

				drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 5);
				biggest = { conPoly[i][0],conPoly[i][1] ,conPoly[i][2] ,conPoly[i][3] };
				maxArea = area;
			}
			//drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 2);
			//rectangle(imgOriginal, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}
	return biggest;
}

////// Here you can drwap the corners of contour points:
void drawPoints(vector<Point> points, Scalar color)
{
    for ( int i =0; i< points.size(); i++)
    {
        circle(imgOriginal, points[i], 10, color, FILLED);
        putText(imgOriginal, to_string(i), points[i], FONT_HERSHEY_PLAIN, 4, color, 4);
    }
}

///  Here you need to reorder the corners of contour points: 
vector<Point> reorder(vector<Point> points)
{
	vector<Point> newPoints;
	vector<int>  sumPoints, subPoints;

	for (int i = 0; i < 4; i++)
	{
		sumPoints.push_back(points[i].x + points[i].y);
		subPoints.push_back(points[i].x - points[i].y);
	}

	newPoints.push_back(points[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); // 0
	newPoints.push_back(points[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //1
	newPoints.push_back(points[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //2
	newPoints.push_back(points[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); //3

	return newPoints;
}

/// / Defind function for warp image: 
Mat getWarp(Mat img, vector<Point> points, float w, float h )
{
	Point2f src[4] = { points[0],points[1],points[2],points[3] };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	Mat matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	return imgWarp;
}

void main() 
{
	string path = "E:/C++project/computer_project/document_scanner_images/paper_scanner.jpg";
	imgOriginal = imread(path);
    resize(imgOriginal, imgOriginal, Size(), 0.25, 0.25);

    ///// Preprecessing step 1:
    imgThre = prepocessing(imgOriginal);

    ///// Get Contours - Biggest  - Step 2
    initialPoints = getContours(imgThre);
    //drawPoints(initialPoints, Scalar(0,0,255));
    docPoints = reorder(initialPoints);
    drawPoints(docPoints, Scalar(0, 255, 0));

    ///// Warp - Step 3 
    imgWarp = getWarp(imgOriginal, docPoints, w, h);

    /////Crop - Step 4
	int cropVal= 5;
	Rect roi(cropVal, cropVal, w - (2 * cropVal), h - (2 * cropVal));
	imgCrop = imgWarp(roi);

    //////Display image - Step 4:
	imshow("Image", imgOriginal);
    //imwrite("Original_Image.jpg", imgOriginal);

    imshow("Image_Dial", imgThre);
    //imwrite("Image_Dial.jpg", imgThre);

    imshow("Image Warp", imgWarp);
    //imwrite("Image Warp.jpg", imgWarp);

    imshow("Image Crop", imgCrop);
    //imwrite("Image Crop.jpg", imgCrop);


    waitKey(0);

}