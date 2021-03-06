#pragma once

enum EdgeBits { EDGE_TOP = IG::bit(0), EDGE_RIGHT = IG::bit(1), EDGE_BOTTOM = IG::bit(2), EDGE_LEFT = IG::bit(3),
	 EDGE_TOPRIGHT = IG::bit(4), EDGE_BOTTOMRIGHT = IG::bit(5), EDGE_BOTTOMLEFT = IG::bit(6), EDGE_TOPLEFT = IG::bit(7) };

#define EDGE_T EDGE_TOP
#define EDGE_R EDGE_RIGHT
#define EDGE_B EDGE_BOTTOM
#define EDGE_L EDGE_LEFT
#define EDGE_TR EDGE_TOPRIGHT
#define EDGE_BR EDGE_BOTTOMRIGHT
#define EDGE_BL EDGE_BOTTOMLEFT
#define EDGE_TL EDGE_TOPLEFT

#define EDGE_ALL (EDGE_T | EDGE_R | EDGE_B | EDGE_L | EDGE_TR | EDGE_BR | EDGE_BL | EDGE_TL)
#define EDGE_A EDGE_ALL
#define EDGE_ALL_CARDINAL (EDGE_T | EDGE_R | EDGE_B | EDGE_L)
#define EDGE_AC EDGE_ALL_CARDINAL
#define EDGE_ALL_INTERMEDIATE (EDGE_TR | EDGE_BR | EDGE_BL | EDGE_TL)
#define EDGE_AI EDGE_ALL_INTERMEDIATE
