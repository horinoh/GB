#include <stdio.h>
#include <rand.h>

#include <gb/gb.h>

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
        CRITICAL {
            add_VBL(VBlank);
            //add_LCD(LCD);
            //add_TIM(Timer);
            //add_SIO(SerialTransfer);
            //add_JOY(Joystick);
        }
        //TMA_REG = 0x00; //!< TMA_REG が 0xff -> 0x00 になる時に割り込み
        //TAC_REG = 0x04; //!< クロックを 4096 hz にする 
        //set_interrupts(VBL_IFLAG | LCD_IFLAG | TIM_IFLAG | SIO_IFLAG | JOY_IFLAG);

        SHOW_BKG;
        //!< BG パレット
        BGP_REG = DEFAULT_PALETTE;
        //!< BG パターン
        //set_bkg_data();

        //!< スプライトパターン
        //set_sprite_data();

        DISPLAY_OFF;{ 
            //!< BG ネームテーブル(マップ)
            //set_bkg_tiles();

            //set_win_data();   

            //set_win_tiles();
            //set_sprite_prop();       
        } DISPLAY_ON;
    } enable_interrupts();

    initrand(0xdeadbeef);

    while(1) {
        delay(1000UL);
        //wait_vbl_done(); 

        //!< アニメーション(パターンチェンジ)
        //set_bkg_tiles();

        //!< アニメーション(パターンチェンジ)
        //set_sprite_tile();
        //!< 移動
        //move_sprite();
    }
}