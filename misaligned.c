#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "misaligned.h"

void printColorMapTable(int pairNumber, const char *majorColor, const char *minorColor )
{
	printf("%d | %s | %s\n", pairNumber, majorColor, minorColor);
}

int pairNumberCalc(int majorIndex , int minorIndex)
{
	return (majorIndex * 5 + minorIndex);
}

int printColorMap()
 {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printColorMapTable( pairNumberCalc(i,j), majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}
void test_printColorMapTable(int expectedPairNumber, const char *expectedMajorColorName, const char *expectedMinorColorName, int majorColorIndex, int minorColorIndex )
{
	int pairNumber = pairNumberCalc(majorColorIndex, minorColorIndex);
	assert(pairNumber == expectedPairNumber);
	assert(majorColor[majorColorIndex] == expectedMajorColorName);
	assert(minorColor[minorColorIndex] == expectedMinorColorName);
}

void test_envPrintColorsConsole()
{
	test_printColorMapTable(0, "White", "Blue", 0 , 0 );
	test_printColorMapTable(1, "White", "Orange", 0 , 1 );
	test_printColorMapTable(2, "White", "Green", 0 , 2 );
	test_printColorMapTable(3, "White", "Brown", 0 , 3 );
	test_printColorMapTable(4, "White", "Slate", 0 , 4 );
	test_printColorMapTable(5, "Red", "Blue", 1 , 0 );
	test_printColorMapTable(6, "Red", "Orange", 1 , 1 );
	test_printColorMapTable(7, "Red", "Green", 1 , 2 );
	test_printColorMapTable(8, "Red", "Brown", 1 , 3 );
	test_printColorMapTable(9, "Red", "Slate", 1 , 4 );
	test_printColorMapTable(10, "Black", "Blue", 2 , 0 );
	test_printColorMapTable(11, "Black", "Orange", 2 , 1 );
	test_printColorMapTable(12, "Black", "Green", 2 , 2 );
	test_printColorMapTable(13, "Black", "Brown", 2 , 3 );
	test_printColorMapTable(14, "Black", "Slate", 2 , 4 );
	test_printColorMapTable(15, "Yellow", "Blue", 3 , 0 );
	test_printColorMapTable(16, "Yellow", "Orange", 3 , 1 );
	test_printColorMapTable(17, "Yellow", "Green", 3 , 2 );
	test_printColorMapTable(18, "Yellow", "Brown", 3 , 3 );
	test_printColorMapTable(19, "Yellow", "Slate", 3 , 4 );
	test_printColorMapTable(20, "Violet", "Blue", 4 , 0 );
	test_printColorMapTable(21, "Violet", "Orange", 4 , 1 );
	test_printColorMapTable(22, "Violet", "Green", 4 , 2 );
	test_printColorMapTable(23, "Violet", "Brown", 4 , 3 );
	test_printColorMapTable(24, "Violet", "Slate", 4 , 4 );
}

int main() {
    	int result = printColorMap();
	assert(result == 25); 
	test_envPrintColorsConsole();
	printf("All is well (maybe!)\n");
	return 0;
}