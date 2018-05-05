#include <stdio.h>
#include <dirent.h>
#ifdef __MINGW32__
#include <sys/stat.h>
#endif
#include <time.h>
#include <ios>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

static void showDetections(const vector<Point>& found, Mat& imageData) {
    size_t i, j;
    for (i = 0; i < found.size(); ++i) {
        Point r = found[i];
        rectangle(imageData, Rect(r.x-16, r.y-32, 32, 64), Scalar(64, 255, 64), 3);
    }
}
static void showDetections(const vector<Rect>& found, Mat& imageData) {
    vector<Rect> found_filtered;
    size_t i, j;
    for (i = 0; i < found.size(); ++i) {
        Rect r = found[i];
        for (j = 0; j < found.size(); ++j)
            if (j != i && (r & found[j]) == r)
                break;
        if (j == found.size())
            found_filtered.push_back(r);
    }
    for (i = 0; i < found_filtered.size(); i++) {
        Rect r = found_filtered[i];
        rectangle(imageData, r.tl(), r.br(), Scalar(64, 255, 64), 3);
    }
}

int main(int argc, char **argv){
    HOGDescriptor hog; // Use standard parameters here
        
    String hogfile;
    char serialPortFilename[] = "/dev/ttyUSB0";
    double hitThreshold;

    hogfile = "genfiles/cvHOGClassifier.yaml";

    hog.winSize = Size(64, 64); // Default training images size as used in paper

    hog.load(hogfile);
    
    hitThreshold = 1.677329;


    VideoCapture cap(0); // open the default camera

    if(!cap.isOpened()) { // check if we succeeded
        printf("Error opening camera!\n");
        return EXIT_FAILURE;
    }
    
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 360);
    cap.set(CV_CAP_PROP_FPS, 60);
    
    Mat testImage, testing;
	
	char key;
	int a, b;
	a = 1;
	b = 212;

	int iLowH = 0;
    int iHighH = 23;
    int iLowS = 127; 
    int iHighS = 255;
    int iLowV = 120;
    int iHighV = 255;
    int erodehsv = 5;
    int dilatehsv = 10;

    int lowR = 93;	//Hue (0 - 179)
    int highR = 255;
    int lowG = 0;	//Saturation (0 - 255)
    int highG = 50;
    int lowB =  0;	//Value (0 - 255)
    int highB = 255;
    int erodebgr = 5;
    int dilatebgr = 10;

    while (1){
    	FILE *serPort = fopen(serialPortFilename, "w");
		clock_t begin = clock();
        cap >> testImage; // get a new frame from camera
		
		Mat imgHSV;
		vector<Rect> found;
		cvtColor(testImage, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat output;
		createTrackbar("LowR", "RGB", &lowR, 255);	//Red (0 - 179)
		createTrackbar("HighR", "RGB", &highR, 255);

		createTrackbar("LowG", "RGB", &lowG, 255);	//Green (0 - 255)
		createTrackbar("HighG", "RGB", &highG, 255);

		createTrackbar("LowB", "RGB", &lowB, 255);	//Blue (0 - 255)
		createTrackbar("HighB", "RGB", &highB, 255);
		inRange(testImage, Scalar(lowB, lowG, lowR), Scalar(highB, highG, highR), output);

		Mat imgThresholded;
		Mat outputlast;
		createTrackbar("LowH", "HSV", &iLowH, 179);	//Hue (0 - 179)
		createTrackbar("HighH", "HSV", &iHighH, 279);

		createTrackbar("LowS", "HSV", &iLowS, 255);	//Saturation (0 - 255)
		createTrackbar("HighS", "HSV", &iHighS, 255);

		createTrackbar("LowV", "HSV", &iLowV, 255);	//Value (0 - 255)
		createTrackbar("HighV", "HSV", &iHighV, 255);
		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image


		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)) ); 

		dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)) ); 
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		erode(output, output, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		dilate(output, output, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)) ); 

		dilate(output, output, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)) ); 
		erode(output, output, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		Size padding(Size(8, 8));
		Size winStride(Size(8, 8));
		double scale = 1.2;

		hog.detectMultiScale(testImage, found, 1.677329, winStride, padding, scale);
		int a = found.size();
		printf("%d", a);
		outputlast = output.clone();
		outputlast = outputlast + imgThresholded;
		float rx = 0;
		float ry = 0;
		bool adaputih = true;
		for (int i = 0; i < found.size(); i++) {
		    for(int k = -15; k <=15; k++ ){
		         for(int j = -15; j <=15; j++ ){
					if (outputlast.at<uchar>((found[i].y + found[i].height*0.5 + k),(found[i].x + found[i].width*0.5 + j)) == 255){
		                adaputih = true;
		            }
		            else {
						adaputih = false;
		            }                
		        }
		    }
			if(adaputih == true) {
				rx += found[i].x + found[i].width*0.5;
				ry += found[i].y + found[i].height*0.5;
				circle(testImage,Point(rx, ry),3,Scalar(0, 255,0),CV_FILLED);
				circle(testImage,Point(rx, ry),50,Scalar(0, 0, 255),3);
			}
		}
		showDetections(found, testImage);
		printf("x : %f \t", rx);
		printf("y : %f \n", ry);

		char writeBuffer[50];
		fprintf(serPort, "hello world");
		clock_t goal = 50000 + clock();
    	while (goal > clock());
    			
		fclose(serPort);
		
		imshow("RGB", output);
		imshow("HSV", imgThresholded); //show the thresholded image
		imshow("Result", outputlast);
		imshow("HOG custom detection", testImage);
		key = cvWaitKey(10);

		if (char(key) == 'a'){
			char filename[80];
			sprintf(filename,"datapos/test_%d.png",a);
			imwrite(filename, testing);
			a++;
		}

		if (char(key) == 's'){
			char filename[80];
			sprintf(filename,"dataneg/test_%d.png",b);
			imwrite(filename, testing);
			b++;
		}

		if(key == 'x'){
			break;
		}
    }
    return 0;
}
