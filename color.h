#ifndef COLOR_H
#define COLOR_H
 
#include <stdio.h>
#include <assert.h>
 
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};
 
extern const char* MajorColorNames[];
extern const char* MinorColorNames[];
 
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;
 
void ColorPairToString(const ColorPair* colorPair, char* buffer);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
 
#endif /* COLOR_H */
