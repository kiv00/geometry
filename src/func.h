
#ifndef PERIMETER_H
#define PERIMETER_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float perimeters(float r);

float areas(float r);

void figure(char* fig, int num, float (*A)[10]);

void intersect(int num, int (*intersects)[5], float (*A)[10]);

#endif
