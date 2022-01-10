#pragma once

void SpriteSetPosLT(uint8_t sp, const uint8_t x, const uint8_t y) { move_sprite(sp, x, y); }
void SpriteSetPosRT(uint8_t sp, const uint8_t x, const uint8_t y) { SpriteSetPosLT(sp, x - 8, y); }
void SpriteSetPosLB(uint8_t sp, const uint8_t x, const uint8_t y) { SpriteSetPosLT(sp, x, y - 8); }
void SpriteSetPosRB(uint8_t sp, const uint8_t x, const uint8_t y) { SpriteSetPosLT(sp, x - 8, y - 8); }
void SpriteSetPosCC(uint8_t sp, const uint8_t x, const uint8_t y) { SpriteSetPosLT(sp, x - 4, y - 4); }
struct Sprite16
{
    uint8_t sprites[4];
};
typedef struct Sprite16 Sprite16;
void Sprite16Init(Sprite16* sp16, const uint8_t lt, const uint8_t rt, const uint8_t lb, const uint8_t rb)
{
    sp16->sprites[0] = lt;
    sp16->sprites[1] = rt;
    sp16->sprites[2] = lb;
    sp16->sprites[3] = rb;
}
void Sprite16SetPosLT(Sprite16* sp16, const uint8_t x, const uint8_t y)
{
    const uint8_t p = get_sprite_prop(sp16->sprites[0]);
    const uint8_t h = (p & S_FLIPX) ? 1 : 0;//(sp16->sprites[0]->Attribute & SPR_ATTR_HFLIP_ON) >> 6;
    const uint8_t v = (p & S_FLIPY) ? 1 : 0;//(sp16->sprites[0]->Attribute & SPR_ATTR_VFLIP_ON) >> 7;
    SpriteSetPosLT(sp16->sprites[h | v << 1], x, y);
    SpriteSetPosLT(sp16->sprites[!h | v << 1], x + 8, y);
    SpriteSetPosLT(sp16->sprites[h | !v << 1], x, y + 8);
    SpriteSetPosLT(sp16->sprites[!h | !v << 1], x + 8, y + 8);
}
void Sprite16SetPosRT(Sprite16* sp16, const uint8_t x, const uint8_t y) { Sprite16SetPosLT(sp16, x - 16, y); }
void Sprite16SetPosLB(Sprite16* sp16, const uint8_t x, const uint8_t y) { Sprite16SetPosLT(sp16, x, y - 16); }
void Sprite16SetPosRB(Sprite16* sp16, const uint8_t x, const uint8_t y) { Sprite16SetPosLT(sp16, x - 16, y - 16); }
void Sprite16SetPosCC(Sprite16* sp16, const uint8_t x, const uint8_t y) { Sprite16SetPosLT(sp16, x - 8, y - 8); }
