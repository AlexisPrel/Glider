/*
Alexis Prel
Phys 2200: Computationnal physics
HW08: Glider flight

Uses glider-ode.c to compute the trajectory with given initial conditions
Returns solely the flight distance l (x coordinate when glider touches ground)
*/


#include <stdio.h>
#include <math.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>

int func (double t, const double y[], double f[], void *params);

double
glider (double v0, double th0, double x0, double y0)
{
    size_t neqs = 4;            // number of equations 
    double eps_abs = 1.e-8, eps_rel = 0.;       // desired precision 
    double stepsize = 1e-6;     // initial integration step 
    double R = 10.;             // the aerodynamic efficiency 
    double t = 0., t1 = 120.;   // time interval 
    int status;

    double y[4] = { v0, th0, x0, y0 };  // Initial conditions

    //Explicit embedded Runge-Kutta-Fehlberg (4,5) method. 
    gsl_odeiv2_step *s = gsl_odeiv2_step_alloc (gsl_odeiv2_step_rkf45, neqs);
    gsl_odeiv2_control *c = gsl_odeiv2_control_y_new (eps_abs, eps_rel);
    gsl_odeiv2_evolve *e = gsl_odeiv2_evolve_alloc (neqs);
    gsl_odeiv2_system sys = { func, NULL, neqs, &R };

    // Evolution loop
    while ((t < t1) && (y[3] > 0))
    {
        status =
            gsl_odeiv2_evolve_apply (e, c, s, &sys, &t, t1, &stepsize, y);

        if (status != GSL_SUCCESS)
        {
            printf ("Troubles: % .5e  % .5e  % .5e  % .5e  % .5e\n", t, y[0],
                    y[1], y[2], y[3]);
            break;
        }
    }
    // if the glider is still in the air prints a warning message
    if (y[3] > 0)
        printf
            ("Execution stopped before the glider reaches ground because time was too long \n"
             "Init conds: % .5e  % .5e  % .5e  % .5e\n", v0, th0, x0, y0);

    // freeing memory
    gsl_odeiv2_evolve_free (e);
    gsl_odeiv2_control_free (c);
    gsl_odeiv2_step_free (s);

    // returning l
    return y[2];
}
