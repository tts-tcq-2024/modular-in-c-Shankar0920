#include <stdio.h>
#include <assert.h>
#include "color.h"
void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}
void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
} 
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
int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE); 
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    return 0;
}
