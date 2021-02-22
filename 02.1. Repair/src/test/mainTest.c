#include "../main/main.h"
#include <math.h>
#include <assert.h>

#define DELTA 0.01

void testCalculateWallpaperAreaShouldCalculateWhenCorrectApplied() {
    double actual = calculateWallpaperArea(2.0, 3.0, 1, 1);

    assert(fabs(actual - 10.53) <= DELTA);
}

void testCalculateWallpaperAreaShouldReturnNegativeWhenIncorrectApplied() {
    double actual = calculateWallpaperArea(-2.0, 3.0, 1, 1);

    assert(actual < 0);
}

void testCalculateWallpaperTubeNumberShouldCalculateWhenCorrectApplied() {
    int actual = calculateWallpaperTubeNumber(6.5, 2.0);

    assert(actual == 7);
}

void testCalculateWallpaperTubeNumberShouldReturnNegativeWhenIncorrectApplied() {
    int actual = calculateWallpaperTubeNumber(-6.5, 2.0);

    assert(actual < 0);
}

void testCalculateTotalCostShouldCalculateWhenCorrectApplied() {
    double actual = calculateTotalCost(7, 3.0);

    assert(fabs(actual - 26) <= DELTA);
}

void testCalculateTotalCostShouldReturnNegativeWhenIncorrectApplied() {
    double actual = calculateTotalCost(-7, 3.0);

    assert(actual < 0);
}

#undef main
int main() {
    testCalculateWallpaperAreaShouldCalculateWhenCorrectApplied();
    testCalculateWallpaperAreaShouldReturnNegativeWhenIncorrectApplied();

    testCalculateWallpaperTubeNumberShouldCalculateWhenCorrectApplied();
    testCalculateWallpaperTubeNumberShouldReturnNegativeWhenIncorrectApplied();

    testCalculateTotalCostShouldCalculateWhenCorrectApplied();
    testCalculateTotalCostShouldReturnNegativeWhenIncorrectApplied();
}
