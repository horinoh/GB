#include <stdio.h>
#include <rand.h>

#include <gb/gb.h>
#include <gb/cgb.h>

#include "../define.h"

void VBlank() {}

void main()
{
    switch(_cpu) {
        default: puts("UNKNOWN"); break;
        case DMG_TYPE: puts("GB"); break;
        case MGB_TYPE: puts("GBPocket"); break;
        case CGB_TYPE: puts("GBColor"); break;
    }
    
    puts("Hello World");

    disable_interrupts(); {
        //!< GBC では CPU を速いモードにすることが可能
        cpu_fast();
        //cpu_slow();

        CRITICAL {
            add_VBL(VBlank);
        }

        SHOW_BKG;
        BGP_REG = DEFAULT_PALETTE;

        //!< GBC カラー設定
        #if 0
        set_default_palette();
        #else
        //!< 15 ビットカラー B[0, 31], G[0, 31], R[0, 31]
        //!< -BBB BBGG GGGR RRRR
         const palette_color_t Data[] = { 
            /*RGB_BLACK*/RGB_YELLOW, RGB_RED, RGB_GREEN, RGB_BLUE, 
            RGB_BLACK, RGB_YELLOW, RGB_PINK, RGB_AQUA,
            RGB_BLACK, RGB_CYAN, RGB_PURPLE, RGB_ORANGE,
            RGB_BLACK, RGB_BROWN, RGB_TEAL, RGB_DARKGREEN,
            RGB_BLACK, RGB_DARKRED, RGB_DARKGREEN, RGB_DARKBLUE,
            RGB_BLACK, RGB_DARKYELLOW, RGB_LIGHTGRAY, RGB_DARKGRAY,
            RGB_BLACK, RGB_WHITE, RGB_LIGHTFLESH, RGB_BLACK,
            RGB_BLACK, RGB_BLACK, RGB_BLACK, RGB_BLACK,
        };
        //!< パレット [0, 7]、各 4 色
        set_bkg_palette(0, sizeof(Data) / sizeof(Data[0]) >> 2, Data);
        //!< スプライトの場合
        //set_sprite_palette(0, sizeof(Data) / sizeof(Data[0]) >> 2, Data)
        #endif

        DISPLAY_OFF;{ 
        } DISPLAY_ON;
    } enable_interrupts();

    initrand(0xdeadbeef);

    while(1) {
        delay(1000UL);
    }
}