
#include "read_camera.h"

videoOptions options;

options.width = 1280;
options.height = 720;
options.frameRate = 30;
options.flipMethod = videoOptions::FLIP_ROTATE_180;

videoSource* input = videoSource::Create("/dev/video0", options);

int main()
{
    Read_camera(argc, argv);
    return 0;
}