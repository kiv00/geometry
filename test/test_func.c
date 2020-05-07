#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#include "../thirdparty/ctest.h"

CTEST(arithmetic_suite, perimeter)
{
    const float r = 1;


    const float result = perimeters(r);

    const float expected = 6.28;
    ASSERT_EQUAL(expected, result);
}
