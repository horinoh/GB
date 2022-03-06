#include <stdio.h>
#include <rand.h>

#include <gb/gb.h>
#include <gbdk/incbin.h>

#include "../define.h"

INCBIN(Patterns, "res/PatternBG.bin")
INCBIN_EXTERN(Patterns)

INCBIN(Map, "res/MapBG.bin")
INCBIN_EXTERN(Map)

void main()
{
    disable_interrupts(); {
        SHOW_BKG;
        //!< BG パレット
        BGP_REG = DEFAULT_PALETTE;
        //!< BG パターン
        set_bkg_data(0, INCBIN_SIZE(Patterns) / 16, Patterns);

        DISPLAY_OFF; {
            //!< BG ネームテーブル (マップ)
            set_bkg_tiles(0, 0, 32, 32, Map);
        } DISPLAY_ON;
    } enable_interrupts();
    
    fixed x = { 0 }, y = { 0 };
    while(1) {
        wait_vbl_done();

        const uint8_t KeyState = joypad();
        const uint8_t Speed = 128;
        if(KeyState & J_UP) { y.w -= Speed; }
        if(KeyState & J_RIGHT) { x.w += Speed; }
        if(KeyState & J_DOWN) { y.w += Speed; }
        if(KeyState & J_LEFT) { x.w -= Speed; }

        #if 1
        move_bkg(x.b.h, y.b.h);
        #else
        SCX_REG = x.b.h;
        SCY_REG = y.b.h;
        #endif
    }
}