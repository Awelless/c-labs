#include "main.h"
#include <math.h>
#include <stdio.h>

#define WINDOW_HEIGHT 1.5
#define WINDOW_WIDTH 2.15

#define DOOR_HEIGHT 2.05
#define DOOR_WIDTH 0.9

#define CEIL_HEIGHT 2.6

#define WALLPAPER_TUBE_WIDTH 0.5

#define GLUE_COST 2.5
#define GLUE_EFFICIENCY 5

int readInt() {
    int value;
    char c;

    while (scanf("%d%c", &value, &c) != 2 || c != '\n') {
        printf("Wrong input\nTry again\n");
        while (getchar() != '\n') {}
    }

    return value;
}

double readDouble() {
    double value;
    char c;

    while (scanf("%lf%c", &value, &c) != 2 || c != '\n') {
        printf("Wrong input\nTry again\n");
        while (getchar() != '\n') {}
    }

    return value;
}

double calculateWallpaperArea(double roomX, double roomY, int windowsNumber, int doorNumber) {
    if (roomX < 0 || roomY < 0 || windowsNumber < 0 || doorNumber < 0) {
        return -1;
    }

    double windowsArea = WINDOW_HEIGHT * WINDOW_WIDTH * windowsNumber;
    double doorsArea = DOOR_HEIGHT * DOOR_WIDTH * doorNumber;
    double roomArea = roomX * roomY * CEIL_HEIGHT;

    return roomArea - windowsArea - doorsArea;
}

int calculateWallpaperTubeNumber(double wallpaperArea, double wallpaperTubeLength) {
    if (wallpaperArea < 0 || wallpaperTubeLength < 0) {
        return -1;
    }

    double wallpaperTubeArea = wallpaperTubeLength * WALLPAPER_TUBE_WIDTH;

    return ceil(wallpaperArea / wallpaperTubeArea);
}

double calculateTotalCost(int wallpaperTubeNumber, double wallpaperTubeCost) {
    if (wallpaperTubeNumber < 0 || wallpaperTubeCost < 0) {
        return -1;
    }

    double wallpaperCost = wallpaperTubeCost * wallpaperTubeNumber;
    int gluePacksNumber = wallpaperTubeNumber / GLUE_EFFICIENCY
            + (wallpaperTubeNumber % GLUE_EFFICIENCY > 0 ? 1 : 0);
    double glueCost = GLUE_COST * gluePacksNumber;

    return wallpaperCost + glueCost;
}

int main() {
    double roomX = -1;
    double roomY = -1;
    double wallpaperTubeLength = -1;
    double wallpaperTubeCost = -1;
    int windowsNumber = -1;
    int doorNumber = -1;

    while (1) {
        printf("--------------------------\n");
        printf("1 - Enter room size\n");
        printf("2 - Enter number of windows\n");
        printf("3 - Enter number of doors\n");
        printf("4 - Enter wallpaper tube info\n");
        printf("5 - Calculate total surface area\n");
        printf("6 - Calculate number of wallpaper tubes\n");
        printf("7 - Calculate total cost\n");
        printf("8 - Exit\n");
        printf("Enter number of operation: ");

        int operation = readInt();

        double wallpaperArea, totalCost;
        int wallpaperTubeNumber;

        switch (operation) {
            case 1:
                printf("Enter room width: ");
                roomX = readDouble();
                printf("Enter room length: ");
                roomY = readDouble();
                printf("Saved\n");
                break;
            case 2:
                printf("Enter number of windows: ");
                windowsNumber = readInt();
                printf("Saved\n");
                break;
            case 3:
                printf("Enter number of doors: ");
                doorNumber = readInt();
                printf("Saved\n");
                break;
            case 4:
                printf("Enter wallpaper tube length: ");
                wallpaperTubeLength = readDouble();
                printf("Enter wallpaper tube cost: ");
                wallpaperTubeCost = readDouble();
                printf("Saved\n");
                break;
            case 5:
                wallpaperArea = calculateWallpaperArea(roomX, roomY, windowsNumber, doorNumber);
                if (wallpaperArea < 0) {
                    printf("Impossible to calculate. Entered data is invalid\n");
                } else {
                    printf("Wallpaper area: %lf\n", wallpaperArea);
                }
                break;
            case 6:
                wallpaperArea = calculateWallpaperArea(roomX, roomY, windowsNumber, doorNumber);
                wallpaperTubeNumber = calculateWallpaperTubeNumber(wallpaperArea, wallpaperTubeLength);
                if (wallpaperTubeNumber < 0) {
                    printf("Impossible to calculate. Entered data is invalid\n");
                } else {
                    printf("Wallpaper tube number: %d\n", wallpaperTubeNumber);
                }
                break;
            case 7:
                wallpaperArea = calculateWallpaperArea(roomX, roomY, windowsNumber, doorNumber);
                wallpaperTubeNumber = calculateWallpaperTubeNumber(wallpaperArea, wallpaperTubeLength);
                totalCost = calculateTotalCost(wallpaperTubeNumber, wallpaperTubeCost);
                if (totalCost < 0) {
                    printf("Impossible to calculate. Entered data is invalid\n");
                } else {
                    printf("Total cost: %lf\n", totalCost);
                }
                break;
            case 8:
                printf("Shutting down\n");
                getchar();
                return 0;
            default:
                printf("Unknown operation\n");
        }

        printf("Press enter to continue\n");
        while (getchar() != '\n') {}
    }
}
