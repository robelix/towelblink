#ifndef __BLINKENWALL_ANI_H
#define __BLINKENWALL_ANI_H
#include "BlinkenWall.h"

/* starter - bright spot */

static const char brightSpot[] = {
  1,
};

static const uint32_t green_spot[] = {
  0x55FF55,
};

static const uint32_t red_spot[] = {
  0xFF4444,
};

static const uint32_t blue_spot[] = {
  0x5555FF,
};

struct animation greenBrightSpot = {1, 1, 1, brightSpot, green_spot};
struct animation redBrightSpot = {1, 1, 1, brightSpot, red_spot};
struct animation blueBrightSpot = {1, 1, 1, brightSpot, blue_spot};

/* fade out and down */

static const char fadeDown[] = {
  128,
  192,
  224,
  240,
  248,
  252,
  254,
  255,
};

static const uint32_t green_fade[] = {
  0x001100,
  0x002200,
  0x003300,
  0x004400,
  0x005500,
  0x006600,
  0x007700,
  0x00FF00,
};
static const uint32_t red_fade[] = {
  0x110000,
  0x220000,
  0x330000,
  0x440000,
  0x550000,
  0x660000,
  0x770000,
  0xFF0000,
};
static const uint32_t blue_fade[] = {
  0x000011,
  0x000022,
  0x000033,
  0x000044,
  0x000055,
  0x000066,
  0x000077,
  0x0000FF,
};

struct animation greenFader = {8, 8, 1, fadeDown, green_fade};
struct animation redFader = {8, 8, 1, fadeDown, red_fade};
struct animation blueFader = {8, 8, 1, fadeDown, blue_fade};



#endif /*__BLINKENWALL_ANI_H*/
