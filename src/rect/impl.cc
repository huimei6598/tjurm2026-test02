#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat gray;
    cv::cvtColor(input,gray,cv::COLOR_BGR2GRAY);
    cv::Mat binary;
    cv::threshold(gray,binary,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i>hierarchy;
    cv::findContours(binary,contours,hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    if(contours.empty()){
        return res;
    }
    double maxArea=0.0;
    int maxAreaidx=0;
    for(size_t i=0;i<contours.size();i++){
        double area = cv::contourArea(contours[i]);
        if(area > maxArea){
            maxArea = area;
            maxAreaidx = i;
        }
    }
    if(maxAreaidx>=0){
        const auto& target_contour = contours[maxAreaidx];
        res.first = cv::boundingRect(target_contour);
        res.second = cv::minAreaRect(target_contour);
    }
    return res;
}