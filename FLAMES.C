#include<stdio.h>
#include<dos.h>

char far * screen = (char far*) 0xA0000000L;


void init()
{
    // VGA mode
    _asm {
        mov ax, 13h
        int 10h
    }
}

void quit()
{
    // text mode
    _asm {
	mov ax, 03h
	int 10h
    }
}

void putpixel(int x, int y, int color)
{
    screen[(y << 8) + (y << 6) + x] = color;
}

void loop()
{
    for (int y = 0; y < 200; y++) {
	for (int x = 0; x < 320; x++) {
	    int color = (y * 24 / 320) + 32;
	    putpixel(x, y, color);
	}
    }
    getchar();
}

int main()
{
    init();
    loop();
    quit();
    return 0;
}
