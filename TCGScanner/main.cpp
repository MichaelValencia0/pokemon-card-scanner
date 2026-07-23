
#include <iostream>
#include "camera.h"
#include <opencv2/opencv.hpp>

int main()
{
	// Create a Camera object
    Camera camera;

	// Open the camera (0 is usually the default camera)
    camera.open(0);

	// Check if the camera is opened successfully
    if (!camera.isOpened()) {
        std::cerr << "Failed to open camera." << std::endl;
        return -1;
    }

    cv::Mat frame;

	// Capture wrap frames on camera untill the user presses the esc.
    while (true) {
        frame = camera.capture();
        if(frame.empty()) {
            std::cerr << "Failed to capture frame." << std::endl;
            break;
        }
        cv::imshow("Camera Feed", frame);
        if (cv::waitKey(1) == 27) { // ESC key
            break;
        }
    }

	// Release the camera and closes any OpenCV windows
    camera.close();
	return 0;
}

