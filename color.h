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
const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
}; 
const int MAX_COLORPAIR_NAME_CHARS = 16;
int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
} 
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
} 
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}
#endif /* COLOR_H */
