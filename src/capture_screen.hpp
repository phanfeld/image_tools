#ifndef CAPTURE_SCREEN_HPP
#define CAPTURE_SCREEN_HPP


#include "opencv2/core/mat.hpp"
#include "opencv2/imgproc/imgproc.hpp"

namespace capture_screen {
void captureScreen(cv::Mat &output);
}
#endif
