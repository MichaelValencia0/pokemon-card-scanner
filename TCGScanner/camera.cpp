#include "camera.h"
#include <iostream>

//Simple intitalizer for the camera.
void Camera::open(int cameraIndex) {
	cam.open(cameraIndex);
}

//Closes and realeases the camera.
void Camera::close() {
	cam.release();
}

//Checks to make sure camera has been opened then captures frame on camera.
cv::Mat Camera::capture() {
	if(!cam.isOpened()) {
		std::cerr << "Camera is not opened." << std::endl;
		return cv::Mat();
	}
	cv::Mat frame;
	cam >> frame;
	return frame;
}

//allows access to check the camera's is open boolean data member.
bool Camera::isOpened() {
	return cam.isOpened();
}