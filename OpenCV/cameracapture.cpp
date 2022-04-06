#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main()
{
    VideoCapture cap(0); // get first cam
    while( cap.isOpened() )
    {
        Mat frame;
        if ( ! cap.read(frame) ) // cam might need some warmup
            continue;

        // your processing goes here

        imshow("Klutuk Capture",frame);
        if ( waitKey(10)==27 )
            break;
    }
    return 0;
}
