#include "../main/main.h"
#include <assert.h>

void testIsValidReturn1WhenCorrectApplied() {
    char number[] = "123";

    char actual = isValid(number);

    assert(actual == 1);
}

void testIsValidReturn0WhenIncorrectApplied() {
    char number[] = "12xyz";

    char actual = isValid(number);

    assert(actual == 0);
}

#undef main
int main() {
    testIsValidReturn1WhenCorrectApplied();
    testIsValidReturn0WhenIncorrectApplied();
}
