#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#pragma comment(lib, "winmm.lib")


class tPeluru {
public:
    int x, y, kecepatanPeluru = 20;
    bool dalam_window;

    tPeluru() {
        x = 0;
        y = 0;
        dalam_window = false;
    }

    tPeluru(int xi, int yi) {
        x = xi;
        y = yi;
        dalam_window = true;
    }

    void gambarPeluru() {
        if (dalam_window) {
            line(x, y, x + 5, y);
        }
    }

    void gerakPeluru() {
        if (dalam_window) {
            x += kecepatanPeluru;
            if (x > getmaxx()) {
                dalam_window = false;
            }
        }
    }
};

class tWorld{
public : 
    int section;

};

class tPesawat {
    public:
        int x, y;
        tPeluru peluru[200];  // Menyesuaikan array peluru untuk menampung hingga 200 peluru
        int peluruDitembakkan;
        int peluruDimiliki = 2000;
    
        tPesawat() {
            x = 200;
            y = 550;
            peluruDitembakkan = 0;
        }
    
        void gambarPesawat() {
            setcolor(WHITE);
            for (int i = 0; i < peluruDitembakkan; i++) {
                peluru[i].gambarPeluru();
            }
        }
        
        void animasiPesawat(){
            readimagefile("D:/coding/dasprog/proglan/rickroll/00012.bmp", x-30, y-30, x+150, y+130);
        }
        
        void animasiSerangan(){
            for (int i = 1; i <= 100; i++) {
                char namafile[100]; 
                sprintf(namafile, "D:/coding/dasprog/proglan/rickroll/%05d.bmp", i); 
    
                readimagefile(namafile, x-30, y-30, x+150, y+130);
    
                delay(1/100);
            }
        }
    
        void gerakPesawat() {
            if (kbhit()) {
                char ch = getch();  
                if (ch == 'w' || ch == 'W') { 
                    y -= 5;
                } else if (ch == 's' || ch == 'S') { 
                    y += 5;
                } else if (ch == 'a' || ch == 'A') { 
                    x -= 5;
                } else if (ch == 'd' || ch == 'D') { 
                    x += 5;
                } else if (ch == 'e'){
                    tembak();
                    animasiSerangan();
                }
            }
        }
    
        void tembak() {
            if (peluruDitembakkan < peluruDimiliki && peluruDitembakkan < 200) {
                peluru[peluruDitembakkan] = tPeluru(x + 10, y);
                peluruDitembakkan++;
            }
            //PlaySound(L"tertembak.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
    
        void gerakPeluru() {
            for (int i = 0; i < peluruDitembakkan; i++) {
                peluru[i].gerakPeluru();
            }
        }
    };
    

class tMusuh {
public:
    int x, y;
    bool tertembak, gerakBawah;

    tMusuh() {
        x = 500;
        y = 550;
        tertembak = false;
        gerakBawah = true;
    }

    void gambarMusuh() {
        if (tertembak == false) {
            readimagefile("D:/coding/dasprog/proglan/fileBmpApelBuruk/01988.bmp", x-30, y-30, x+150, y+130);
        }
    }

    void kenaTembak(tPesawat &pesawat) {
        for (int i = 0; i < pesawat.peluruDitembakkan; i++) {
            int dx = pesawat.peluru[i].x - x;
            int dy = pesawat.peluru[i].y - y;
            int jarak = sqrt(dx * dx + dy * dy);

            if (jarak < 20) {
                tertembak = true;
                break;
            }
        }
    }

    void gerakMusuh() {
        if (gerakBawah) {
            x += 3;
            if (x >= getmaxx()) {
                gerakBawah = false;
            }
        } else {
            x -= 3;
            if (x <= 0) {
                gerakBawah = true;
            }
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initwindow(1200,750, "mamat", 1,-1);
    tPesawat pesawat;
    tMusuh musuh;

    while (true) {
        cleardevice();
        pesawat.gerakPesawat();
        pesawat.gambarPesawat();
        pesawat.animasiPesawat();
        pesawat.gerakPeluru();
        musuh.gerakMusuh();
        musuh.kenaTembak(pesawat);
        musuh.gambarMusuh();

        delay(10);
    }

    getch();
    closegraph();
    return 0;
}
