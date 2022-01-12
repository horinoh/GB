#include <stdio.h>
#include <rand.h>

#include <gb/gb.h>

#include "../define.h"

//!< Vブランク発生時
void VBlank()
{
    uint8_t KeyState = joypad();
    if(KeyState & J_B) {
        NR1X_CLEAR;
        NR2X_CLEAR;
        NR3X_CLEAR;
        NR4X_CLEAR;
    }
    if(KeyState & J_UP) {
        //!< チャンネル1 (矩形波スイープあり)
        NR10_REG = NR10_SWEEP_TIME(7) | NR10_SWEEP_DEC | NR10_SWEEP_AMOUNT(7);
        NR11_REG = SOUND_DUTY(3) | SOUND_LENGTH(0);
        NR12_REG = SOUND_INIT_VOL(15) | SOUND_VOL_SWEEP_DEC | SOUND_SWEEP_LEN(0);
        NR13_REG = SOUND_FREQ_LOWER(2000);
        NR14_REG = SOUND_INIT_CH | /*SOUND_ENABLE_LEN |*/ SOUND_FREQ_UPPER(2000);
    }
    if(KeyState & J_RIGHT) {
        //!< チャンネル2 (矩形波)
        NR21_REG = SOUND_DUTY(3) | SOUND_LENGTH(0);
        NR22_REG = SOUND_INIT_VOL(15) | SOUND_VOL_SWEEP_DEC | SOUND_SWEEP_LEN(0);
        NR23_REG = SOUND_FREQ_LOWER(2000);
        NR24_REG = SOUND_INIT_CH | /*SOUND_ENABLE_LEN |*/SOUND_FREQ_UPPER(2000);
    }
    if(KeyState & J_DOWN) {
        //!< チャンネル3 (波形メモリ音源)
        NR30_REG = NR30_MASTER_POWER;
        NR31_REG = NR31_LENGTH(0);
        NR32_REG = NR31_VOL_100;
        NR33_REG = SOUND_FREQ_LOWER(1000);
        NR34_REG = SOUND_INIT_CH | /*SOUND_ENABLE_LEN |*/SOUND_FREQ_UPPER(1000);
    }
    if(KeyState & J_LEFT) {
        //!< チャンネル4 (ノイズ)
        NR41_REG = SOUND_DUTY(3) | SOUND_LENGTH(0);
        NR42_REG = SOUND_INIT_VOL(15) | SOUND_VOL_SWEEP_DEC | SOUND_SWEEP_LEN(3);
        NR43_REG = NR43_SHIFT_FREQ(3) | NR43_SHIFT_15BIT | NR43_DIV_RATIO_FREQ(7);
        NR44_REG = SOUND_INIT_CH | /*SOUND_ENABLE_LEN |*/SOUND_FREQ_UPPER(0);
    }
}

void Timer() { }

void main()
{
    disable_interrupts(); {
         CRITICAL {
            add_VBL(VBlank);
            add_TIM(Timer);
        }
        TMA_REG = 0x00; //!< TMA_REG が 0xff -> 0x00 になる時に割り込みが発生
        TAC_REG = 0x04; //!< クロックを 4096 hz にする
        set_interrupts(VBL_IFLAG | TIM_IFLAG);

        //!< サウンド初期設定
        NR52_REG = NR52_MASTER_POWER;
        NR51_REG = NR51_CH_ALL_ON;
        NR50_REG = NR50_L_VOL(7) | NR50_R_VOL(7);

    } enable_interrupts();

    while(1) { delay(1000UL); }
}