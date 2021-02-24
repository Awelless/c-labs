#ifndef MAIN_H
#define MAIN_H

double calculateWallpaperArea(double roomX, double roomY, int windowsNumber, int doorNumber);
int calculateWallpaperTubeNumber(double wallpaperArea, double wallpaperTubeLength);
double calculateTotalCost(int wallpaperTubeNumber, double wallpaperTubeCost);

#endif