#include <graphics.h>
#include <stdio.h>
#include <dos.h>

// Function to display BMP images
void displayBMP(const char* filename) {
    readimagefile(filename, 0, 0, getmaxx(), getmaxy());
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, const_cast<char*>("D:/coding/dasprog/proglan/fileBmpApelBuruk"));

    const char* images[] = {
        "00001.bmp",
        "00002.bmp",
        "00003.bmp",
        "00004.bmp",
        "00005.bmp",
        "00006.bmp",
        "00007.bmp",
        "00008.bmp",
        "00009.bmp",
        "00010.bmp",
        "00011.bmp",
        "00012.bmp",
        "00013.bmp",
        "00014.bmp",
        "00015.bmp",
        "00016.bmp",
        "00017.bmp",
        "00018.bmp",
        "00019.bmp",
        "00020.bmp",
        "00021.bmp",
        "00022.bmp",
        "00023.bmp",
        "00024.bmp",
        "00025.bmp",
        "00026.bmp",
        "00027.bmp",
        "00028.bmp",
        "00029.bmp",
        "00030.bmp",
        "00031.bmp",
        "00032.bmp",
        "00033.bmp",
        "00034.bmp",
        "00035.bmp",
        "00036.bmp",
        "00037.bmp",
        "00038.bmp",
        "00039.bmp",
        "00040.bmp",
        "00041.bmp",
        "00042.bmp",
        "00043.bmp",
        "00044.bmp",
        "00045.bmp",
        "00046.bmp",
        "00047.bmp",
        "00048.bmp",
        "00049.bmp",
        "00050.bmp",
        "00051.bmp",
        "00052.bmp",
        "00053.bmp",
        "00054.bmp",
        "00055.bmp",
        "00056.bmp",
        "00057.bmp",
        "00058.bmp",
        "00059.bmp",
        "00060.bmp",
    };

    int frameCount = sizeof(images) / sizeof(images[0]);

    for (int i = 0; i < frameCount; i++) {
        cleardevice();  // Clear screen for the next frame
        displayBMP(images[i]);
        delay(100);  // Show each frame for 100 milliseconds
    }

    getch();
    closegraph();
    return 0;
}
