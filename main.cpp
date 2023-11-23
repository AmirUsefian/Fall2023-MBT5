#include <opencv4/opencv2/opencv.hpp>
using namespace std;

class Camera {
public:
    Camera() {}
    void run() {
        cv::VideoCapture cap(2);
        if (!cap.isOpened()) {
            cout << "Cannot open camera" << endl;
            return;
        }
        cv::Mat frame, gray;
        while (true) {
            cap >> frame;
            cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            imshow("Normal", frame);
            imshow("Grayscale", gray);
            if (cv::waitKey(30) == 'q')
                break;
        }
    }
};

int main() {
    cv::Mat tmp(500, 500, CV_8UC3, cv::Scalar(0, 255, 255));
    cv::imshow("ss", tmp);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
    Camera cam;
    cam.run();
    return 0;
}
