#include <stdio.h>
#include <gb/gb.h>
#include <gbdk/console.h>

#include "../define.h"

void main()
{
    uint8_t KeyState = 0, PrevState = 0;
    uint8_t x = 0, y = 0;

    while (1) {
        wait_vbl_done();

        PrevState = KeyState;
        KeyState = joypad();
        uint8_t KeyTrig = (KeyState ^ PrevState) & PrevState;

        //!< Up, Right, Down, Left : Arrow key
        gotoxy(x + 1, y + 0);
        (KeyState & J_UP) ? puts("+") : puts("-");
        gotoxy(x + 2, y + 1);
        (KeyState & J_RIGHT) ? puts("+") : puts("-");
        gotoxy(x + 1, y + 2);
        (KeyState & J_DOWN) ? puts("+") : puts("-");
        gotoxy(x + 0, y + 1);
        (KeyState & J_LEFT) ? puts("+") : puts("-");

        gotoxy(x + 1, y + 0 + 3);
        (KeyTrig & J_UP) ? puts("@") : puts(" ");
        gotoxy(x + 2, y + 1 + 3);
        (KeyTrig & J_RIGHT) ? puts("@") : puts(" ");
        gotoxy(x + 1, y + 2 + 3);
        (KeyTrig & J_DOWN) ? puts("@") : puts(" ");
        gotoxy(x + 0, y + 1 + 3);
        (KeyTrig & J_LEFT) ? puts("@") : puts(" ");

        //!< Select, Run : BackSpace, Enter
        gotoxy(x + 4, y + 2);
        (KeyState & J_SELECT) ? puts("+") : puts("-");
        gotoxy(x + 5, y + 2);
        (KeyState & J_START) ? puts("+") : puts("-");
        gotoxy(x + 4, y + 2 + 3);
        (KeyTrig & J_SELECT) ? puts("@") : puts(" ");
        gotoxy(x + 5, y + 2 + 3);
        (KeyTrig & J_START) ? puts("@") : puts(" ");
  
        //!< B, A : Z, X
        gotoxy(x + 7, y + 2);
        (KeyState & J_B) ? puts("+") : puts("-");
        gotoxy(x + 8, y + 2);
        (KeyState & J_A) ? puts("+") : puts("-");
        gotoxy(x + 7, y + 2 + 3);
        (KeyTrig & J_B) ? puts("@") : puts(" ");
        gotoxy(x + 8, y + 2 + 3);
        (KeyTrig & J_A) ? puts("@") : puts(" ");
    }
}
