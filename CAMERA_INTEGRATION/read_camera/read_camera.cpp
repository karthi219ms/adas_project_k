// Correct code , can start working with this as the base code

#include "read_camera.h"

int Read_camera(int argc, char** argv)
{
    // create input/output streams
    videoSource* input = videoSource::Create(argc, argv, ARG_POSITION(0));
    videoOutput* output = videoOutput::Create(argc, argv, ARG_POSITION(1));
	
    if( !input )
        return 0;

    // capture/display loop
    while( true )
    {
        uchar3* image = NULL;  // can be uchar3, uchar4, float3, float4
        int status = 0;        // see videoSource::Status (OK, TIMEOUT, EOS, ERROR)
		
        if( !input->Capture(&image, 1000, &status) )  // 1000ms timeout (default)
        {
            if( status == videoSource::TIMEOUT )
                continue;
				
            break; // EOS
        }

        if( output != NULL )
        {
            output->Render(image, input->GetWidth(), input->GetHeight());

            if( !output->IsStreaming() )  // check if the user quit
                break;
        }
    }

    // destroy resources
    SAFE_DELETE(input);
    SAFE_DELETE(output);
}
