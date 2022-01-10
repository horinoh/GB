#include <stdio.h>
#include <rand.h>

#include <gb/gb.h>
//#include <gbdk/metasprites.h>

#include "../define.h"
#include "../gblib.h"

#define TR 0
#define C0 1
#define C1 2
#define C2 3

#define M0 1
#define M1 2

#define P(c, m, b) PATTERN(c, m, b)
const uint8_t Patterns[] = {
    //!< パターン 0
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(TR, M0, 3) | P(C0, M0, 2) | P(C0, M0, 1) | P(C0, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(TR, M1, 3) | P(C0, M1, 2) | P(C0, M1, 1) | P(C0, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(C0, M0, 3) | P(C0, M0, 2) | P(C0, M0, 1) | P(C0, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(C0, M1, 3) | P(C0, M1, 2) | P(C0, M1, 1) | P(C0, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(C2, M0, 1) | P(C1, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(C2, M1, 1) | P(C1, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(C2, M0, 4) | P(C1, M0, 3) | P(C2, M0, 2) | P(C1, M0, 1) | P(C1, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(C2, M1, 4) | P(C1, M1, 3) | P(C2, M1, 2) | P(C1, M1, 1) | P(C1, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(C2, M0, 4) | P(C1, M0, 3) | P(C2, M0, 2) | P(C2, M0, 1) | P(C1, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(C2, M1, 4) | P(C1, M1, 3) | P(C2, M1, 2) | P(C2, M1, 1) | P(C1, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(C1, M0, 2) | P(C1, M0, 1) | P(C1, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(C1, M1, 2) | P(C1, M1, 1) | P(C1, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(TR, M0, 3) | P(C1, M0, 2) | P(C1, M0, 1) | P(C1, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(TR, M1, 3) | P(C1, M1, 2) | P(C1, M1, 1) | P(C1, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(C0, M0, 1) | P(C2, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(C0, M1, 1) | P(C2, M1, 0), 

    //!< パターン 1
    P(C0, M0, 7) | P(C0, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(TR, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C0, M1, 7) | P(C0, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(TR, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C0, M0, 7) | P(C0, M0, 6) | P(C0, M0, 5) | P(C0, M0, 4) | P(C0, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C0, M1, 7) | P(C0, M1, 6) | P(C0, M1, 5) | P(C0, M1, 4) | P(C0, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C1, M0, 7) | P(C2, M0, 6) | P(C1, M0, 5) | P(TR, M0, 4) | P(TR, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C1, M1, 7) | P(C2, M1, 6) | P(C1, M1, 5) | P(TR, M1, 4) | P(TR, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C1, M0, 7) | P(C2, M0, 6) | P(C1, M0, 5) | P(C1, M0, 4) | P(C1, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C1, M1, 7) | P(C2, M1, 6) | P(C1, M1, 5) | P(C1, M1, 4) | P(C1, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C1, M0, 7) | P(C1, M0, 6) | P(C2, M0, 5) | P(C1, M0, 4) | P(C1, M0, 3) | P(C1, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C1, M1, 7) | P(C1, M1, 6) | P(C2, M1, 5) | P(C1, M1, 4) | P(C1, M1, 3) | P(C1, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C1, M0, 7) | P(C2, M0, 6) | P(C2, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C1, M1, 7) | P(C2, M1, 6) | P(C2, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C1, M0, 7) | P(C1, M0, 6) | P(C1, M0, 5) | P(C1, M0, 4) | P(TR, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C1, M1, 7) | P(C1, M1, 6) | P(C1, M1, 5) | P(C1, M1, 4) | P(TR, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C2, M0, 7) | P(C2, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(TR, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C2, M1, 7) | P(C2, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(TR, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),

    //!< パターン 2
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(C0, M0, 1) | P(C2, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(C0, M1, 1) | P(C2, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(C2, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(C0, M0, 1) | P(C0, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(C2, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(C0, M1, 1) | P(C0, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(C1, M0, 5) | P(C1, M0, 4) | P(C2, M0, 3) | P(C0, M0, 2) | P(C1, M0, 1) | P(C0, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(C1, M1, 5) | P(C1, M1, 4) | P(C2, M1, 3) | P(C0, M1, 2) | P(C1, M1, 1) | P(C0, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(C1, M0, 5) | P(C1, M0, 4) | P(C1, M0, 3) | P(C0, M0, 2) | P(C0, M0, 1) | P(C0, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(C1, M1, 5) | P(C1, M1, 4) | P(C1, M1, 3) | P(C0, M1, 2) | P(C0, M1, 1) | P(C0, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(C1, M0, 5) | P(C1, M0, 4) | P(C0, M0, 3) | P(C0, M0, 2) | P(C0, M0, 1) | P(C0, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(C1, M1, 5) | P(C1, M1, 4) | P(C0, M1, 3) | P(C0, M1, 2) | P(C0, M1, 1) | P(C0, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(TR, M0, 4) | P(C0, M0, 3) | P(C0, M0, 2) | P(C0, M0, 1) | P(TR, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(TR, M1, 4) | P(C0, M1, 3) | P(C0, M1, 2) | P(C0, M1, 1) | P(TR, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(TR, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(TR, M1, 7) | P(TR, M1, 6) | P(TR, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0), 
    P(TR, M0, 7) | P(TR, M0, 6) | P(C2, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0), 
    P(TR, M1, 7) | P(TR, M1, 6) | P(C2, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0), 

    //!< パターン 3
    P(C2, M0, 7) | P(C0, M0, 6) | P(C2, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C2, M1, 7) | P(C0, M1, 6) | P(C2, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C0, M0, 7) | P(C0, M0, 6) | P(C2, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C0, M1, 7) | P(C0, M1, 6) | P(C2, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C0, M0, 7) | P(C1, M0, 6) | P(C0, M0, 5) | P(C2, M0, 4) | P(C1, M0, 3) | P(C1, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C0, M1, 7) | P(C1, M1, 6) | P(C0, M1, 5) | P(C2, M1, 4) | P(C1, M1, 3) | P(C1, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C0, M0, 7) | P(C0, M0, 6) | P(C0, M0, 5) | P(C1, M0, 4) | P(C1, M0, 3) | P(C1, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C0, M1, 7) | P(C0, M1, 6) | P(C0, M1, 5) | P(C1, M1, 4) | P(C1, M1, 3) | P(C1, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(C0, M0, 7) | P(C0, M0, 6) | P(C0, M0, 5) | P(C0, M0, 4) | P(C1, M0, 3) | P(C1, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(C0, M1, 7) | P(C0, M1, 6) | P(C0, M1, 5) | P(C0, M1, 4) | P(C1, M1, 3) | P(C1, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(TR, M0, 7) | P(C0, M0, 6) | P(C0, M0, 5) | P(C0, M0, 4) | P(TR, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(TR, M1, 7) | P(C0, M1, 6) | P(C0, M1, 5) | P(C0, M1, 4) | P(TR, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(TR, M0, 7) | P(TR, M0, 6) | P(C2, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(TR, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(TR, M1, 7) | P(TR, M1, 6) | P(C2, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(TR, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
    P(TR, M0, 7) | P(TR, M0, 6) | P(C2, M0, 5) | P(C2, M0, 4) | P(C2, M0, 3) | P(C2, M0, 2) | P(TR, M0, 1) | P(TR, M0, 0),
    P(TR, M1, 7) | P(TR, M1, 6) | P(C2, M1, 5) | P(C2, M1, 4) | P(C2, M1, 3) | P(C2, M1, 2) | P(TR, M1, 1) | P(TR, M1, 0),
};
#undef P
#undef M1
#undef M0
#undef C2
#undef C1
#undef C0
#undef TR

void main()
{
    Sprite16 sp16[10];
    // const metasprite_t MetaSprite0[] = {
    //     METASPR_ITEM(0, 0, 0, 0/*S_FLIPX | S_FLIPY*/),
    //     METASPR_ITEM(8, 0, 2, 0),
    //     METASPR_ITEM(0, 8, 4, 0),
    //     METASPR_ITEM(8, 8, 6, 0),
    // };
    // const metasprite_t* const MetaSprites[] = { MetaSprite0 };

    disable_interrupts(); {
        SHOW_SPRITES;

        //!< パレット
        OBP0_REG = OBP1_REG = DEFAULT_PALETTE;

        //!< スプライトパターン
        set_sprite_data(0, COUNTOF(Patterns), Patterns);

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

#if 0
        move_sprite(0, x.b.h, y.b.h);
        move_sprite(1, x.b.h + 8, y.b.h);
        move_sprite(2, x.b.h, y.b.h + 8);
        move_sprite(3, x.b.h + 8, y.b.h + 8);
        //move_metasprite(MetaSprites[0], 0, 0, x.b.h, y.b.h);
#else
        for(uint8_t i = 0;i < COUNTOF(sp16);++i){
            Sprite16SetPosCC(&sp16[i], x.b.h + (i << 4), y.b.h + (i << 3));
        }
#endif
    }
}