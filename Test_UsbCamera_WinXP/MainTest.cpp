#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, const char** argv)
{
	cv::String savePath = "G:\\Nampc\\Src\\Test_UsbCamera_WinXP\\Binaries\\Bin\\lastimg.jpg";

	cv::Mat frame;
	cv::VideoCapture cap;

	cap.open(0);
	if (!cap.isOpened()) {
		std::cout << "Not found the camera." << std::endl;
		return -1;
	}
	
	if (cap.isOpened()) {
		while (true)
		{
			cap >> frame;
			if (!frame.empty()) {
				cv::imshow("Usb Camera", frame);
			}
			else {
				std::cout << "--(!) No captured frame. Break" << std::endl;
			}

			int c = cv::waitKey(10);
			if (c == 'q') break;
			if (c == 's') {
				cv::imwrite(savePath, frame);
			}
		}
		cv::destroyAllWindows();
	}
	return 0;

}