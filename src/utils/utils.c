#include "utils.h"

#include <stdlib.h>

int get_random_number(int min, int max) { return rand() % (max - min + 1) + min; }

int calculate_lcm(int a, int b) {
    int gcd = calculate_gcd(a, b);
    return (a * b) / gcd;
}

int calculate_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}