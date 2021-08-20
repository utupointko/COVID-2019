#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	cap.open(0);
	// Loading the actual image
	for(;;) {
		Mat image, gray;
		cap >> image;
		// Edge cases
		if (image.empty()) {
			cout << "Error loading image" << endl;
			return -1;
		}

		// converting the color image into grayscale
		cvtColor(image, gray, COLOR_BGR2GRAY);

		// Smoothing the image to get rid of noise, so no false detections
		// Here we used a 11x11 filter
		blur(gray, gray, Size(7, 7), Point(-1, -1));
		cv::imshow("Blurred_image", gray);
		//cv::imwrite("Blurred_image.jpg", gray);

		// Store the detected circles in a 3d-vector
		vector<Vec3f> circles;

		for (int maxR = 0; maxR < 200; maxR = maxR + 10) {

			// Apply hough transform
			HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
						 100, // detect circle with different distance
						 100, 90,
						 0, maxR);

			// Draw the detected circles
			for (size_t i = 0; i < circles.size(); i++) {
				Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
				int radius = cvRound(circles[i][2]);
				// Draw the center point of the circle
				circle(image, center, 3, Scalar(0, 255, 0), -1, 8, 0);
				// Draw the circle shape
				circle(image, center, radius, Scalar(0, 255, 0), 3, 8, 0);
			}
		}
		// Displaying the result
		cv::imshow("circles", image);
		//cv::imwrite("Detected_circles.jpg", image);
		if (cv::waitKey(10) == 27)
			break;
	}
	return 0;
}