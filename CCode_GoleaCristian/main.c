#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "linked_list.h"
#include "menu.h"
#include <time.h>

int main()
{
    clock_t start = clock();
        meniu();
    clock_t stop = clock();
    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time elapsed in s: %f", elapsed);

    return 0;
}
