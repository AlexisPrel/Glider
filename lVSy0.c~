/*
* This program calls the main function do to the computations 
* and simply prints l(y0) in the output file.

* for this one, we also add the variation dx between two adjacents value in order to find more easily in the data file where l changes rapidly
*/

#include <stdio.h>
double glider (double v, double th, double x, double y);

int
main (void)
{
    double y0, lafter;
    double lbefore = 0., dx = 0.;
    for (y0 = .1; y0 <= 2; y0 += .05)
    {
        lafter = glider (y0, 0., 0., 2.);
        dx = lafter - lbefore;
        printf ("%f %f %f\n", y0, lafter, dx);
        lbefore = lafter;
    }
    for (y0 = .1574195; y0 <= .1574197; y0 += .000000005)
    {                           //we draw more points in this region where l changes rapidly
        lafter = glider (y0, 0., 0., 2.);
        dx = lafter - lbefore;
        printf ("%f %f %f\n", y0, lafter, dx);
        lbefore = lafter;
    }
    return 0;
}
