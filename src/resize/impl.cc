#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat output(new_rows, new_cols, input.type());
    // IMPLEMENT YOUR CODE HERE
    for(int i=0;i<new_rows;i++){
        for(int j=0;j<new_cols;j++){
            int src_i = static_cast<int>(i/scale);
            int src_j = static_cast<int>(j/scale);
            //边界处理
            if(src_i >= input.rows) src_i = input.rows - 1;
            if(src_j >= input.cols) src_j = input.cols - 1;
            src_i = std::max(0, src_i);
            src_j = std::max(0, src_j);
            if (input.channels() == 1) {
                output.at<uchar>(i, j) = input.at<uchar>(src_i, src_j);
            }
            else if (input.channels() == 3) {
                output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(src_i, src_j);
            }
        }
    }
    return cv::Mat::zeros(new_rows, new_cols, input.type());
}