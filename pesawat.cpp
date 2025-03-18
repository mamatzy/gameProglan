#include <graphics.h>
#include <conio.h>

class tLingkaran {
public:
    int x, y, r;
    int dx;

    tLingkaran(int xi, int yi, int ri, int speed) { 
        x = xi;
        y = yi;
        r = ri;
        dx = speed;
    }

    void gambar() {
        circle(x, y, r);
    }
    
    void gerak() {
        x += dx;
        if (x + r >= getmaxx() || x - r <= 0) {
            dx = -dx; 
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    const int jumlahLingkaran = 10;
    tLingkaran a[jumlahLingkaran] = {
        {20, 100, 20, 1},
        {40, 150, 20, 2},
        {80, 200, 20, 3},
        {100, 250, 20, 2},
        {120, 300, 20, 1},
        {140, 350, 20, 2},
        {160, 400, 20, 3},
        {180, 450, 20, 2},
        {200, 500, 20, 1},
        {220, 550, 20, 2}
    };

    while (!kbhit()) { // Loop sampai tombol ditekan
        cleardevice();

        for (int i = 0; i < jumlahLingkaran; i++) {
            a[i].gambar();
            a[i].gerak();
        }

        delay(10);
    }
    
    getch();
    closegraph();
    return 0;
}
