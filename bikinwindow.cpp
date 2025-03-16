#include <graphics.h>
#include <cstdio>   

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)""); 

    int totalFrames = 2000; 
    int frameDelay = 10;

    for (int i = 1; i <= totalFrames; i++) {
        char filename[100];
        sprintf(filename, "D:/coding/dasprog/proglan/fileBmpApelBuruk/%05d.bmp", i); 

        readimagefile(filename, 0, 0, getmaxx(), getmaxy());

        delay(frameDelay);

        if (kbhit()) break;
    }

    closegraph();
    return 0;
}
