#pragma once

#define COUNTOF(x) sizeof(x) / sizeof(x[0])
#define BIT_ON(x) (1 << x)

#define PATTERN(col, mask, bit) (((col) & (mask)) ? 1 : 0) << (bit)

//!< 1バイトで4諧調
#define COLOR_WHITE 0
#define COLOR_LGRAY 1
#define COLOR_DGRAY 2
#define COLOR_BLACK 3
#define PALETTE(c0, c1, c2, c3) (uint8_t)(((c3) << 6) | ((c2) << 4) | ((c1) << 2) | ((c0) << 0));
#define DEFAULT_PALETTE PALETTE(COLOR_WHITE, COLOR_LGRAY, COLOR_DGRAY, COLOR_BLACK)

//!< サウンド
#define NR1X_CLEAR NR10_REG = 0x00; NR11_REG = 0x00; NR12_REG = 0x00; NR13_REG = 0x00; NR14_REG = 0x80
#define NR2X_CLEAR NR21_REG = 0x00; NR22_REG = 0x00; NR23_REG = 0x00; NR24_REG = 0x80
#define NR3X_CLEAR NR30_REG = 0x00; NR31_REG = 0x00; NR32_REG = 0x00; NR33_REG = 0x00; NR34_REG = 0x00
#define NR4X_CLEAR NR41_REG = 0x00; NR42_REG = 0x00; NR43_REG = 0x00; NR44_REG = 0x00

#define NR52_MASTER_POWER (uint8_t)BIT_ON(7)
#define NR52_IS_CH4_ON (NR52_REG & BIT_ON(3))
#define NR52_IS_CH3_ON (NR52_REG & BIT_ON(2))
#define NR52_IS_CH2_ON (NR52_REG & BIT_ON(1))
#define NR52_IS_CH1_ON (NR52_REG & BIT_ON(0))

#define NR51_CH4_L_ON (uint8_t)BIT_ON(7)
#define NR51_CH3_L_ON (uint8_t)BIT_ON(6)
#define NR51_CH2_L_ON (uint8_t)BIT_ON(5)
#define NR51_CH1_L_ON (uint8_t)BIT_ON(4)
#define NR51_CH4_R_ON (uint8_t)BIT_ON(3)
#define NR51_CH3_R_ON (uint8_t)BIT_ON(2)
#define NR51_CH2_R_ON (uint8_t)BIT_ON(1)
#define NR51_CH1_R_ON (uint8_t)BIT_ON(0)
#define NR51_CH_ALL_ON (NR51_CH4_L_ON | NR51_CH3_L_ON | NR51_CH2_L_ON | NR51_CH1_L_ON | NR51_CH4_R_ON | NR51_CH3_R_ON| NR51_CH2_R_ON | NR51_CH1_R_ON)

#define NR50_VIN_S02_ON (uint8_t)BIT_ON(7)
#define NR50_L_VOL_MASK (BIT_ON(4) | BIT_ON(5) | BIT_ON(6)) //!< [0, 7]
#define NR50_L_VOL(x) (uint8_t)(((x) << 4) & NR50_L_VOL_MASK)
#define NR50_VIN_S01_ON (uint8_t)BIT_ON(3)
#define NR50_R_VOL_MASK (BIT_ON(0) | BIT_ON(1) | BIT_ON(2))
#define NR50_R_VOL(x) (uint8_t)((x) & NR50_R_VOL_MASK) //!< [0, 7]

//!< 複数チャンネル共通
#define SOUND_DUTY_MASK (BIT_ON(4) | BIT_ON(5) | BIT_ON(6))
#define SOUND_DUTY(x) (uint8_t)(((x) << 4) & SOUND_DUTY_MASK) //!< [0, 7]
#define SOUND_LENGTH_MASK (BIT_ON(0) | BIT_ON(1) | BIT_ON(2)| BIT_ON(3) | BIT_ON(4) | BIT_ON(5))
#define SOUND_LENGTH(x) (uint8_t)((x) & SOUND_LENGTH_MASK) //!< [0, 31]

#define SOUND_INIT_VOL_MASK (BIT_ON(4) | BIT_ON(5) | BIT_ON(6) | BIT_ON(7))
#define SOUND_INIT_VOL(x) (uint8_t)(((x) << 4) & SOUND_INIT_VOL_MASK) //!< [0, 15]
#define SOUND_VOL_SWEEP_INC (uint8_t)BIT_ON(6)
#define SOUND_VOL_SWEEP_DEC 0
#define SOUND_SWEEP_LEN_MASK (BIT_ON(0) | BIT_ON(1) | BIT_ON(2))
#define SOUND_SWEEP_LEN(x) (uint8_t)((x) & SOUND_SWEEP_LEN_MASK) //!< [0, 7]

#define SOUND_FREQ_LOWER_MASK 0xff
#define SOUND_FREQ_LOWER(x) (uint8_t)((x) & SOUND_FREQ_LOWER_MASK) //!< [0, 2048] 上位 3 ビットと合わせて

#define SOUND_INIT_CH (uint8_t)BIT_ON(7)
#define SOUND_ENABLE_LEN (uint8_t)BIT_ON(6)
#define SOUND_FREQ_UPPER_MASK (BIT_ON(0) | BIT_ON(1) | BIT_ON(2))
#define SOUND_FREQ_UPPER(x) (uint8_t)(((x) >> 8) & SOUND_FREQ_UPPER_MASK) //!< [0, 2048] 下位 8 ビットと合わせて

//!< チャンネル1 (矩形波スイープあり)
#define NR10_SWEEP_TIME_MASK (BIT_ON(4) | BIT_ON(5) | BIT_ON(6))
#define NR10_SWEEP_TIME(x) (uint8_t)(((x) << 4) & NR10_SWEEP_TIME_MASK) //!< [0, 7]
#define NR10_SWEEP_DEC (uint8_t)BIT_ON(3)
#define NR10_SWEEP_INC 0
#define NR10_SWEEP_AMOUNT_MASK (BIT_ON(0) | BIT_ON(1) | BIT_ON(2))
#define NR10_SWEEP_AMOUNT(x) (uint8_t)((x) & NR10_SWEEP_AMOUNT_MASK) //!< [0, 7]

//!< チャンネル2 (矩形波)

//!< チャンネル3 (波形メモリ音源)
#define NR30_MASTER_POWER (uint8_t)BIT_ON(7)
#define NR31_LENGTH_MASK 0xff
#define NR31_LENGTH(x) (uint8_t)((x) & NR31_LENGTH_MASK) //!< [0, 255] 
#define NR31_VOL_MASK (uint8_t)(BIT_ON(5) | BIT_ON(6))
#define NR31_VOL_MUTE ((0 << 5) & NR31_VOL_MASK)
#define NR31_VOL_100 ((1 << 5) & NR31_VOL_MASK)
#define NR31_VOL_50 ((2 << 5) & NR31_VOL_MASK)
#define NR31_VOL_25 ((3 << 5) & NR31_VOL_MASK)

//!< チャンネル4 (ノイズ)
//!< FREQ = 524288 hz / IV_RATIO_FREQ / 2^(SHIFT_FREQ + 1)  //!< IV_RATIO_FREQ == 0 の場合は IV_RATIO_FREQ = 0.5
#define NR43_SHIFT_FREQ_MASK (BIT_ON(4) | BIT_ON(5) | BIT_ON(6) | BIT_ON(7))
#define NR43_SHIFT_FREQ(x) (uint8_t)(((x) << 4) & NR43_SHIFT_FREQ_MASK) //!< [0, 15]
#define NR43_SHIFT_7BIT BIT_ON(3)
#define NR43_SHIFT_15BIT 0
#define NR43_DIV_RATIO_FREQ_MASK (BIT_ON(0) | BIT_ON(1) | BIT_ON(2))
#define NR43_DIV_RATIO_FREQ(x) (uint8_t)((x) & NR43_DIV_RATIO_FREQ_MASK) //!< [0, 7]
