#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/func.h"

#include "../thirdparty/ctest.h"

CTEST(arithmetic_suite, perimeters)
{
    const float r = 1;


    const float result = perimeters(r);

    const float expected = 6.28;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, areas)
{
    const float r = 1;


    const float result = areas(r);

    const float expected = 3.14;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, figure)
{
	int num=0;
	float A[5][10];
	float Arr[5][10];
	Arr[0][1]=1;
	Arr[0][2]=1;
	Arr[0][3]=2;
	Arr[0][4]=3;
	char fig[20]="circle(1 2, 3)";
	figure(fig,num,A);
	ASSERT_EQUAL(Arr[0][1], A[0][1]);
	ASSERT_EQUAL(Arr[0][2], A[0][2]);
	ASSERT_EQUAL(Arr[0][3], A[0][3]);
	ASSERT_EQUAL(Arr[0][4], A[0][4]);
}
	
CTEST(arithmetic_suite, intersect)
{
	int expintersects[5][5];
	expintersects[0][0]=0;
	expintersects[0][1]=0;
	expintersects[0][2]=0;
	expintersects[1][0]=0;
	expintersects[1][1]=0;
	expintersects[1][2]=1;
	expintersects[2][0]=0;
	expintersects[2][1]=1;
	expintersects[2][2]=0;
	int intersects[5][5];
	float A[5][10];
	A[0][2]=1;
	A[0][3]=1;
	A[0][4]=1;
	A[1][2]=5;
	A[1][3]=5;
	A[1][4]=3;
	A[2][2]=6;
	A[2][3]=6;
	A[2][4]=2;
	intersect(3,intersects,A);
    ASSERT_EQUAL(expintersects[0][0], intersects[0][0]);
    ASSERT_EQUAL(expintersects[0][1], intersects[0][1]);
    ASSERT_EQUAL(expintersects[0][2], intersects[0][2]);
    ASSERT_EQUAL(expintersects[1][0], intersects[1][0]);
    ASSERT_EQUAL(expintersects[1][1], intersects[1][1]);
    ASSERT_EQUAL(expintersects[1][2], intersects[1][2]);
    ASSERT_EQUAL(expintersects[2][0], intersects[2][0]);
    ASSERT_EQUAL(expintersects[2][1], intersects[2][1]);
    ASSERT_EQUAL(expintersects[2][2], intersects[2][2]);
    
}

