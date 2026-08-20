#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0);
    
    if (!cap.isOpened()) {
        std::cerr << "Erreur : Impossible d'ouvrir la webcam !" << std::endl;
        return -1;
    }

    cv::Mat frame1, frame2;
    cv::Mat gray1, gray2, diff, thresh;

    cap.read(frame1);
    cap.read(frame2);

    std::cout << "Appuie sur la touche 'q' dans la fenetre video pour quitter." << std::endl;

    while (true) {
        if (frame1.empty() || frame2.empty()) break;

        cv::cvtColor(frame1, gray1, cv::COLOR_BGR2GRAY);
        cv::cvtColor(frame2, gray2, cv::COLOR_BGR2GRAY);

        cv::GaussianBlur(gray1, gray1, cv::Size(21, 21), 0);
        cv::GaussianBlur(gray2, gray2, cv::Size(21, 21), 0);

        cv::absdiff(gray1, gray2, diff);

        cv::threshold(diff, thresh, 25, 255, cv::THRESH_BINARY);

        cv::dilate(thresh, thresh, cv::Mat(), cv::Point(-1, -1), 2);

        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(thresh, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        bool mouvementDetecte = false;

        for (const auto& contour : contours) {
            if (cv::contourArea(contour) < 1000) {
                continue;
            }

            mouvementDetecte = true;

            cv::Rect rect = cv::boundingRect(contour);
            cv::rectangle(frame1, rect, cv::Scalar(0, 255, 0), 2);
        }

        if (mouvementDetecte) {
            cv::putText(frame1, "MOUVEMENT DETECTE !", cv::Point(20, 40),
                        cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 0, 255), 2);
        }

        cv::imshow("Detecteur de Mouvement", frame1);

        frame1 = frame2.clone();
        cap.read(frame2);

        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}