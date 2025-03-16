#include <graphics.h>
#include <sstream>  // For string formatting
#include <cstdio>   // For sprintf

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)""); // Initialize graphics mode

    int totalFrames = 2000; // Total number of frames
    int frameDelay = 10; // Delay between frames (milliseconds)

    for (int i = 1; i <= totalFrames; i++) {
        // Generate the filename (e.g., "frame001.bmp")
        char filename[256];
        sprintf(filename, "D:/coding/dasprog/proglan/fileBmpApelBuruk/%05d.bmp", i); // Adjust format based on your filenames

        cleardevice();

        // Display the image
        readimagefile(filename, 0, 0, getmaxx(), getmaxy());

        // Add delay to control frame rate
        delay(frameDelay);

        // Exit loop on key press
        if (kbhit()) break;
    }

    closegraph();
    return 0;
}