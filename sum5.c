#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int t = 20;
    const int lo = 1, hi = 10;
    int k1, k2, k3, k4, k5;
    if (argc > 1) {
        t = atoi(argv[1]);
    }
    printf("target = %d\n", t);
    for (k1 = lo; k1 <= hi; k1++) {
        for (k2 = k1 + 1; k2 <= hi; k2++) {
            for (k3 = k2 + 1; k3 <= hi; k3++) {
                for (k4 = k3 + 1; k4 <= hi; k4++) {
                    for (k5 = k4 + 1; k5 <= hi; k5++) {
                        if (k1 + k2 + k3 + k4 + k5 == t) {
                            printf("%d, %d, %d, %d, %d\n", k1, k2, k3, k4, k5);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
