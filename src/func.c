
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

float perimeters(float r){
	if(r<0) r*=-1;
	float perimetr=3.14*r*2;
	return perimetr;
}

float areas(float r){
	if(r<0) r*=-1;
	float ar=3.14*r*r;
	return ar;
}

void figure(char* fig,int num, float (*A)[10])
{
    int k = 0, yes = 0;
    float metka = 1;
    for (int i = 0; fig[i] != '('; i++) {
        k = i + 1;
    }
    char check[k];
    for (int i = 0; i < k; i++) { //check figure
        check[i] = fig[i];
    }
    if (strstr(check, "circle") != 0) {
        A[num][1] = 1;
    } else {
        A[num][1] = 5;
    }
    if ((int)A[num][1] == 1) { //parameters figure
        A[num][2] = 0;
        A[num][3] = 0;
        A[num][4] = 0;
        yes = 0;
        metka = 1;
        for (int i = k + 1; (float)fig[i] > 45 && (float)fig[i] < 58; i++) { //x
            k = i + 1;
            if (fig[i] > 47) {
                A[num][2] = A[num][2] * 10 + (float)fig[i] - 48;
                metka /= 10;
            } else {
                yes = 1;
                metka = 1;
            }
        }
        if (yes == 1) {
            A[num][2] = A[num][2] * metka;
        }
        yes = 0;
        metka = 1;
        for (int i = k + 1; (float)fig[i] > 45 && (float)fig[i] < 58; i++) { //y
            k = i + 1;
            if (fig[i] > 47) {
                A[num][3] = A[num][3] * 10 + (float)fig[i] - 48;
                metka *= 10;
            } else {
                yes = 1;
                metka = 1;
            }
        }
        if (yes == 1) {
            A[num][3] = A[num][3] / metka;
        }
        yes = 0;
        metka = 1;
        for (int i = k + 2; (float)fig[i] > 45 && (float)fig[i] < 58; i++) { //r
            k = i + 1;
            if (fig[i] > 47) {
                A[num][4] = A[num][4] * 10 + (float)fig[i] - 48;
                metka *= 10;
            } else {
                yes = 1;
                metka = 1;
            }
        }
        if (yes == 1) {
            A[num][4] = A[num][4] / metka;
        }
        yes = 0;
        metka = 1;
    }
}

void intersect(int num, int (*intersects)[5], float (*A)[10])
{
    float sum, ras;
    for (int i = 0; i < num - 1; i++) {  
        for (int j = i + 1; j < num; j++) {
            sum = A[i][4] + A[j][4];
            ras
                    = sqrt((A[j][2] - A[i][2]) * (A[j][2] - A[i][2])
                           + (A[j][3] - A[i][3]) * (A[j][3] - A[i][3]));
            if (ras < sum) {
                intersects[i][j] = 1;
                intersects[j][i] = 1;
            }
        }
    }
}


