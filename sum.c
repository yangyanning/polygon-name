#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 128

void foo(int depth, int lo, int hi, int s, int t, int* prev) {
    int i, j, k;
    if (depth == 0) {
        if (s == t) {
            i = 0;
            while (prev[i] > 0)
                printf("%d, ", prev[i++]);
            printf("\n");
        }
        return;
    }

    j = 0;
    while (prev[j] > 0)
        ++j;
    for (i = lo; i <= hi; ++i) {
        prev[j] = i;
        k = j + 1;
        while (prev[k] > 0)
            prev[k++] = 0;
        foo(depth - 1, i + 1, hi, s + i, t, &prev[0]);
    }
    return;
}


int main(int argc, char* argv[]) {
    int prev[MAX_DEPTH] = {0};
    int depth = 4, t = 12;
    if (argc > 1) {
        depth = atoi(argv[1]);
        t = atoi(argv[2]);
    }
    printf("depth = %d, target = %d\n", depth, t);
    foo(depth, 1, 2 * depth, 0, t, &prev[0]);
    return 0;
}
