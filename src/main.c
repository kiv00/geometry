#include "func.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float A[5][10];
    int intersects[5][5];
    int num = 0, stop = 0;
    float area, perimeter;
    char fig[20];
    do {
        for (int i = 0; fig[i - 1] != 41; i++) {
            scanf("%c", &fig[i]);
            if (fig[i] == '0') {
                stop = 1;
                break;
            }
        }
        figure(fig, num, A);
        num++;
    } while (stop == 0);
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - 1; j++) {
            intersects[i][j] = 0;
        }
    }
    intersect(num - 1, intersects, A);
    for (int i = 0; i < num - 1; i++) {
        if ((int)A[i][1] == 1) {
            printf("%d. circle(%.2f %.2f, %.2f)\n",
                   i + 1,
                   A[i][2],
                   A[i][3],
                   A[i][4]);
            area = areas(A[i][4]);
            perimeter = perimeters(A[i][4]);
            printf("perimeter = %.3f\narea = %.3f\nintersects:\n",
                   perimeter,
                   area);
            for (int j = 0; j < num - 1; j++) {
                if (intersects[i][j] == 1) {
                    if (A[j][1] == 1) {
                        printf("%d. circle\n", j + 1);
                    }
                }
            }
            printf("\n");
        } else {
            printf("error figure\n");
        }
    }
    system("PAUSE");
    return 1;
}
