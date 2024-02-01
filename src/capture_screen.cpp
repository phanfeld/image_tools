#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "capture_screen.hpp"

namespace capture_screen {
void captureScreen(cv::Mat &output) {
    Display *display = XOpenDisplay(nullptr);
    Window root = DefaultRootWindow(display);

    XWindowAttributes attributes;
    XGetWindowAttributes(display, root, &attributes);

    //       x ->
    // +-----------+   y 
    // '           '   |
    // '           '   ˅
    // '           '
    // +-----------+ 

    // int x_min = 121;   
    // int y_min = 188;
    // int x_max = 533; //width
    // int y_max = 320; //height

    int x_min = 0;   
    int y_min = 171;
    int x_max = 725; //width
    int y_max = 500; //height


    XImage *img = XGetImage(display, root, x_min, y_min, x_max, y_max, AllPlanes, ZPixmap);

    unsigned char *data = reinterpret_cast<unsigned char *>(img->data);

    // cv::Mat image;
    output = cv::Mat(y_max, x_max, CV_8UC4, data).clone();
    // cv::resize(image, output, cv::Size(image.cols * 5, image.rows * 5), 0, 0, cv::INTER_LINEAR);
    cv::cvtColor(output.clone(), output, cv::COLOR_BGR2RGBA, 4);

    XDestroyImage(img);
    XCloseDisplay(display);
    }
}