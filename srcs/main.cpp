/*
 * Simple Computer Vision Demo using OpenCV
 * Features: Face Detection, Edge Detection, and Image Filters
 * Author: [Xiaoyun XU]
 * 
 * This program demonstrates fundamental computer vision techniques:
 * - Haar Cascade face detection
 * - Canny edge detection
 * - Gaussian blur filtering
 * - Grayscale conversion
 */

#include "../include/faceDetector.hpp"

int main(void)
{
	CascadeClassifier face_cascade;
	String path = CASCADEPATH;

	if (!face_cascade.load(path))
	{
		std::cerr << RED << "Error: Could not load face cascade classifier" << RESET << std::endl;
		std::cout << "Make sure OpenCV haarcascades are installed" << std::endl;
		return 1;
	}

	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		std::cerr << RED << "Error: Cannot open webcam" << RESET << std::endl;
		std::cout << "Trying to load a sample image instead..." << std::endl;

		Mat sample = Mat::zeros(480, 640, CV_8UC3);
		putText(sample, "OpenCV Demo - Webcam not available", 
				Point(50, 240), FONT_HERSHEY_SIMPLEX, 0.7, 
				Scalar(255, 255, 255), 2);
		imshow("Computer Vision Demo", sample);
		waitKey(3000);
		return 1;
	}

	std::cout << "======================================" << std::endl;
	std::cout << "  OpenCV Computer Vision Demo" << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "Controls:" << std::endl;
	std::cout << "  'q' - Quit" << std::endl;
	std::cout << "  'e' - Toggle edge detection" << std::endl;
	std::cout << "  'f' - Toggle face detection" << std::endl;
	std::cout << "  'g' - Toggle grayscale" << std::endl;
	std::cout << "  'b' - Toggle blur" << std::endl;
	std::cout << "======================================" << std::endl;

	bool show_edges = false;
	bool show_faces = true;
	bool show_grayscale = false;
	bool show_blur = false;

	Mat frame, gray, edges, blurred;

	while (42)
	{
		cap >> frame;

		if (frame.empty())
		{
			std::cerr << RED << "Error: Cannot read frame" << RESET << std::endl;
			break;
		}

		Mat display = frame.clone();

		if (show_grayscale)
		{
			cvtColor(frame, gray, COLOR_BGR2GRAY);
			cvtColor(gray, display, COLOR_GRAY2BGR);
		}
		else cvtColor(frame, gray, COLOR_BGR2GRAY);

		if (show_blur)
		{
			GaussianBlur(display, blurred, Size(15, 15), 0);
			display = blurred.clone();
		}

		if (show_edges) {
			Canny(gray, edges, 50, 150);
			cvtColor(edges, display, COLOR_GRAY2BGR);
		}

		if (show_faces && !show_edges)
		{
			std::vector<Rect> faces;
			face_cascade.detectMultiScale(gray, faces, 1.1, 5, 0, Size(30, 30));

			for (size_t i = 0; i < faces.size(); i++)
			{
				rectangle(display, faces[i], Scalar(0, 255, 0), 3);

				String label = "Face " + std::to_string(i + 1);
				int baseline = 0;
				Size textSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseline);
				Point textOrg(faces[i].x, faces[i].y - 10);

				rectangle(display, 
						textOrg + Point(0, baseline),
						textOrg + Point(textSize.width, -textSize.height),
						Scalar(0, 255, 0), FILLED);

				putText(display, label, textOrg, FONT_HERSHEY_SIMPLEX, 
						0.5, Scalar(0, 0, 0), 1);
			}

			String count_text = "Faces detected: " + std::to_string(faces.size());
			putText(display, count_text, Point(10, 30), 
					FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);
		}

		int y_offset = display.rows - 30;
		String status = "Active: ";
		if (show_faces && !show_edges) status += "[Face Detection] ";
		if (show_edges) status += "[Edges] ";
		if (show_grayscale) status += "[Grayscale] ";
		if (show_blur) status += "[Blur] ";

		putText(display, status, Point(10, y_offset), 
				FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 1);

		imshow("Computer Vision Demo - Press 'q' to quit", display);

		char key = static_cast<char>(waitKey(30));

		if (key == 'q' || key == 'Q') break;
		else if (key == 'e' || key == 'E')
		{
			show_edges = !show_edges;
			std::cout << "Edge detection: " << (show_edges ? "ON" : "OFF") << std::endl;
		}
		else if (key == 'f' || key == 'F')
		{
			show_faces = !show_faces;
			std::cout << "Face detection: " << (show_faces ? "ON" : "OFF") << std::endl;
		}
		else if (key == 'g' || key == 'G')
		{
			show_grayscale = !show_grayscale;
			std::cout << "Grayscale: " << (show_grayscale ? "ON" : "OFF") << std::endl;
		}
		else if (key == 'b' || key == 'B')
		{
			show_blur = !show_blur;
			std::cout << "Blur: " << (show_blur ? "ON" : "OFF") << std::endl;
		}
	}

	cap.release();
	destroyAllWindows();

	std::cout << GREEN << "Program terminated successfully" << RESET << std::endl;
	return 0;
}
