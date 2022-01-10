#include <stdio.h>
#include <gb/gb.h>

#include "../define.h"

void main()
{
    u8 KeyState = 0, PrevState = 0;

    while (1) {
        wait_vbl_done();

        PrevState = KeyState;
        KeyState = joypad();
        #if 1
        if((KeyState & J_UP) && !(PrevState & J_UP)) puts("UP");
        if((KeyState & J_RIGHT) && !(PrevState & J_RIGHT)) puts("RIGHT");
        if((KeyState & J_DOWN) && !(PrevState & J_DOWN)) puts("DOWN");
        if((KeyState & J_LEFT) && !(PrevState & J_LEFT)) puts("LEFT");
        if((KeyState & J_SELECT) && !(PrevState & J_SELECT)) puts("SELECT");
        if((KeyState & J_START) && !(PrevState & J_START)) puts("START");
        if((KeyState & J_B) && !(PrevState & J_B)) puts("B");
        if((KeyState & J_A) && !(PrevState & J_A)) puts("A");
        #else
        if(KeyState & J_UP) puts("UP");
        if(KeyState & J_RIGHT) puts("RIGHT");
        if(KeyState & J_DOWN) puts("DOWN");
        if(KeyState & J_LEFT) puts("LEFT");
        if(KeyState & J_SELECT) puts("SELECT");
        if(KeyState & J_START) puts("START");
        if(KeyState & J_B) puts("B");
        if(KeyState & J_A) puts("A");
        #endif
    }
}
