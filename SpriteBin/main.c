#include <stdio.h>
#include <rand.h>

#include <gb/gb.h>
#include <gbdk/incbin.h>

#include "../define.h"
#include "../gblib.h"

INCBIN(Patterns, "Pattern.bin")
INCBIN_EXTERN(Patterns)

void main()
{
    Sprite16 sp16[10];

    disable_interrupts(); {
        SHOW_SPRITES;

        //!< パレット
        OBP0_REG = OBP1_REG = DEFAULT_PALETTE;

        //!< スプライトパターン
        set_sprite_data(0,  INCBIN_SIZE(Patterns) / 16, Patterns);

        DISPLAY_OFF;{  
            //!< 16x16 スプライトタイル、プロパティ
            for(uint8_t i = 0;i < COUNTOF(sp16);++i) {
                const uint8_t BaseIndex = i << 2;
                const uint8_t i0 = BaseIndex, i1 = BaseIndex + 1, i2 = BaseIndex + 2, i3 = BaseIndex + 3;
                set_sprite_tile(i0, 0);
                set_sprite_tile(i1, 1);
                set_sprite_tile(i2, 2);
                set_sprite_tile(i3, 3);

                if(BaseIndex & 4){
                    set_sprite_prop(i0, S_FLIPX); 
                    set_sprite_prop(i1, S_FLIPX); 
                    set_sprite_prop(i2, S_FLIPX); 
                    set_sprite_prop(i3, S_FLIPX); 
                }
                else{
                    set_sprite_prop(i0, 0); 
                    set_sprite_prop(i1, 0); 
                    set_sprite_prop(i2, 0); 
                    set_sprite_prop(i3, 0); 
                }
                
                Sprite16Init(&sp16[i], i0, i1, i2, i3);
            }
        } DISPLAY_ON;
    } enable_interrupts();

    initrand(0xdeadbeef);

    fixed x = { 0 }, y = { 0 };
    while(1) {
        wait_vbl_done();
 
        const uint8_t KeyState = joypad();
        const uint8_t Speed = 128;
        if(KeyState & J_UP) { y.w -= Speed; }
        if(KeyState & J_RIGHT) { x.w += Speed; }
        if(KeyState & J_DOWN) { y.w += Speed; }
        if(KeyState & J_LEFT) { x.w -= Speed; }

        for(uint8_t i = 0;i < COUNTOF(sp16);++i){
            Sprite16SetPosCC(&sp16[i], x.b.h + (i << 4), y.b.h + (i << 3));
        }
    }
}