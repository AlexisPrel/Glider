/*
* This program calls the main function do to the computations 
* and simply prints l(theta0) in the output file.
*/

#include <stdio.h>
#include <math.h>

double glider (double v, double th, double x, double y);

int
main (void)
{
    double theta0;
    for (theta0 = -M_PI / 3.; theta0 <= M_PI / 3.; theta0 += M_PI / 60.)
        printf ("%f %f\n", theta0, glider (2., theta0, 0., 2.));
    return 0;
}
