- **Purpose of the project:** Create a Document scanner to detect documents and prepare an A4 paper-size output image.
 
- **Further possibility of extending this project:** we can detect any texts, handwriting, and patterns from documents.
 
- **Prerequisites environment:** VS code editor, Visual Studio compiler 2022,  CMake build engine V_3.30.0, OpenCV library v_4.10.0 windows.

- **Usage libraries:**
 - #include<opencv2/imgcodecs.hpp>,  #include<opencv2/highgui.hpp>, #include<opencv2/imgproc.hpp>, #include <opencv2/objdetect.hpp>
 - Haar Feature-based Cascade Classifier. https://github.com/opencv/opencv/tree/master/data/haarcascades

- **Debugging:**  C/c++: g++.exe build and debug active file( Compiler tools: MSYS2-64)

- **What have I learned from implementing this project ??**
  - Detect text, images, and patterns from documents.
  - Convert original image to Gray, Blurr, and Canny Images.
  - Detect the Shape/ Contour of the image.
  - Again draw new contour points on a new image.
  - Reorder contour points.
  - Warp and crop image.
  - Finally, A4 paper-size output image
  
- Before scanning the image:
![paper_scanner](https://github.com/abulzunayed/C_plus_plus_Projects/assets/122612945/05456762-f5d0-423a-bee6-b289eec0df2d)

- After image processing:

![Image_Dial](https://github.com/abulzunayed/C_plus_plus_Projects/assets/122612945/c3a20351-24e5-40ec-85b1-47dbb85d9747)

- Final Output:

  
![Image Crop](https://github.com/abulzunayed/C_plus_plus_Projects/assets/122612945/62a72417-890f-4543-9fbf-4bd2848a2152)
