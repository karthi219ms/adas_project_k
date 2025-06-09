#include <jetson-utils/videoSource.h>
#include <jetson-utils/videoOutput.h>
#include <iostream>

int main(int argc, char** argv) {
    // Create a video source (USB camera or CSI camera)
    //videoSource* camera = videoSource::Create("csi://0");  // For CSI Camera
     videoSource* camera = videoSource::Create("/dev/video0");  // For USB Camera

    if (!camera) {
        std::cerr << "Failed to initialize camera!" << std::endl;
        return -1;
    }

    // Create a video output window
    videoOutput* display = videoOutput::Create("display://0");

    if (!display) {
        std::cerr << "Failed to create display output!" << std::endl;
        delete camera;
        return -1;
    }

    // Buffer to store the captured image
    uchar3* image = NULL;

    // Capture and display loop
    while (true) {
        int status = 0;

        // Capture a frame
        if (!camera->Capture(&image, 1000, &status)) {  // 1000ms timeout
            if (status == videoSource::TIMEOUT)
                continue; // Retry capturing

            std::cerr << "Camera stream ended or error occurred!" << std::endl;
            break;
        }

        // Display the frame
        display->Render(image, camera->GetWidth(), camera->GetHeight());

        // Check if the display window was closed
        if (!display->IsStreaming())
        {
            std::cerr << "While loop exit!" << std::endl;
            break;
        }
    }

    // Cleanup resources
    SAFE_DELETE(camera);
    SAFE_DELETE(display);

    return 0;
}
