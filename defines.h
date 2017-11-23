#ifndef DEFINES_H
#define DEFINES_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D/Box2D.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



static const int SCALE = 30;


static const float DEGTORAD = 0.01745;


static const int FRAME_PER_SEK = 60;

static const int JUMP_MAX_POSITION = 150;
static const int PLAYER_HEIGHT = 100;
static const int PLAYER_WIDTH = 50;


static const bool PAL_RIGHT_HENDED = true;
static const bool PAL_LEFT_HENDED = false;


static const bool  FORHAND = true;
static const bool  BACKHAND = false;


#endif // DEFINES_H

