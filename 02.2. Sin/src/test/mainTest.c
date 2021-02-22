#include "../main/main.h"
#include <math.h>
#include <assert.h>

#define DELTA 0.01

void testFactorialReturn2When2Applied() {
    double actual = factorial(2);

    assert(fabs(actual - 2) <= DELTA);
}

void testFactorialReturn120When5Applied() {
    double actual = factorial(5);

    assert(fabs(actual - 120) <= DELTA);
}

void testFactorialReturn3628800When10Applied() {
    double actual = factorial(10);

    assert(fabs(actual - 3628800) <= DELTA);
}

#undef main
int main() {
    testFactorialReturn2When2Applied();
    testFactorialReturn120When5Applied();
    testFactorialReturn3628800When10Applied();
}
