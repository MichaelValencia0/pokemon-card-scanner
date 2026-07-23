#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>

// Camera class of the Project that uses opencv to access the camera and capture frames.

class Camera {
public:
	void open(int);
	void close();
	cv::Mat capture();
	bool isOpened();
private:
	cv::VideoCapture cam;
};

#endif


