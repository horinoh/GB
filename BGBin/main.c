#include <stdio.h>
#include <rand.h>

#include <gb/gb.h>
#include <gbdk/incbin.h>

#include "../define.h"

#if 1
INCBIN(Patterns, "res/sample_PAT.bin")
INCBIN_EXTERN(Patterns)
INCBIN(Map, "res/sample_MAP.bin")
INCBIN_EXTERN(Map)
#include "res/sample_PAL.txt"
#define GET_BG_PAL sample_PAL
#define MAP_W 20
#define MAP_H 18
#else
INCBIN(Patterns, "res/mapchip_PAT.bin")
INCBIN_EXTERN(Patterns)
INCBIN(Map, "res/mapchip_MAP.bin")
INCBIN_EXTERN(Map)
#include "res/mapchip_PAL.txt"
#define GET_BG_PAL mapchip_PAL
#define MAP_W 24
#define MAP_H 20
#endif

void main()
{
    disable_interrupts(); {
        SHOW_BKG;
        //!< BG パレット
        BGP_REG = GET_BG_PAL[0];
        //!< BG パターン
        set_bkg_data(0, INCBIN_SIZE(Patterns) / 16, Patterns);

        DISPLAY_OFF; {
            //!< BG ネームテーブル (マップ)
            set_bkg_tiles(0, 0, MAP_W, MAP_H, Map);
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