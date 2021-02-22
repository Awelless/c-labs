#include "main.h"
#include <stdio.h>
#include <math.h>

double factorial(unsigned short x) {
    double ans = 1;

    unsigned short i;
    for (i = 1; i <= x; ++i) {
        ans *= i;
    }

    return ans;
}

void readDouble(double *x) {
    double value;
    char c;

    while (scanf("%lf%c", &value, &c) != 2 || c != '\n') {
        printf("Wrong input\nTry again\n");
        while (getchar() != '\n') {}
    }

    *x = value;
}

int main() {
    printf("Enter x: ");
    double x;
    readDouble(&x);

    printf("Enter epsilon: ");
    double e;
    readDouble(&e);

    double sinX = sin(x);

    unsigned int n = 0;
    while (1) {
        double curValue = 0;

        size_t i;
        for (i = 0; i <= n; ++i) {
            double num = pow(x, 2.0 * i + 1);
            double den = factorial(2 * i + 1);

            double toAdd = num / den;

            if (i % 2 == 0) {
                curValue += toAdd;
            } else {
                curValue -= toAdd;
            }
        }

        if (fabs(sinX - curValue) <= e) {
            break;
        }

        n++;
    }

    printf("N: %d\n", n);

    return 0;
}
