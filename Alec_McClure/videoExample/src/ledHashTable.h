
// LED Display
#define LED_NO_OF_PANELS	8
#define LED_PANEL_WIDTH         32
#define LED_PANEL_HEIGHT        8
#define LED_DISPLAY_WIDTH	128
#define LED_DISPLAY_HEIGHT	32

//0, 128, 256, 384, 8, 136, 264, 392, 16, 144, 272, 400, 24, 152, 280, 408 //row 0
//32, 160, 288, 416,40, 168, 296, 424, 48, 176, 304, 432, 56, 184, 312, 440 //row 1
//64, 192, 320, 448, 72, 200, 328, 456, 80, 208, 336, 464, 88, 216, 344, 472 //row 2
//96, 224, 352, 480, 104, 232, 360, 488, 112, 240, 368, 496, 120, 248, 376, 504 //row 3

//top left, same column-except 4 down, same column-except 4 down,

// Defines 128  x  "8 pixel" chunks (buffer offsets) for each of 4 possible sets of led lines (1024 pixels per line)
// 16 chunks (8 pixels) per panel, 8 panels
// Enter numbers from paper lowest value first for each row, IE 67,68,69,70 etc
unsigned int indexes[4][16]={

					{0,128,256,384,8,136,264,392,16,144,272,400,24,152,280,408}, //row 0

					{32,160,288,416,40,168,296,424,48,176,304,432,56,184,312,440}, //row 1

					{64,192,320,448,72,200,328,456,80,208,336,464,88,216,344,472}, //row 2

					{96,224,352,480,104,232,360,488,112,240,368,496,120,248,376,504}}; //row 3


