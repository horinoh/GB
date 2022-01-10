#pragma once

//!< 1バイトで4諧調
#define COLOR_WHITE 0
#define COLOR_LGRAY 1
#define COLOR_DGRAY 2
#define COLOR_BLACK 3
#define PALETTE(c0, c1, c2, c3) (uint8_t)(((c3) << 6) | ((c2) << 4) | ((c1) << 2) | ((c0) << 0));
#define DEFAULT_PALETTE PALETTE(COLOR_WHITE, COLOR_LGRAY, COLOR_DGRAY, COLOR_BLACK)