/* THIRD PROBLEM */
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return cos(x) - x * exp(x);
}

int main()
{
    double a = 0.0, b = 1.0;
    double fa, fb, fr, r, y, error;
    double tol = 5e-5;   // 4 significant digits
    int iter = 0, N = 1000;

    fa = f(a);
    fb = f(b);

    y = b;
    r = a - (a - b) * fa / (fa - fb);
    error = fabs((y - r) / r);

    while (error > tol && iter <= N)
    {
        fr = f(r);

        if (fa * fr < 0)
        {
            b = r;
            fb = fr;
        }
        else
        {
            a = r;
            fa = fr;
        }

        y = r;
        r = a - (a - b) * fa / (fa - fb);
        error = fabs((y - r) / r);

        iter++;
    }

    printf("Root (4 significant digits) = %.4lf\n", r);
    printf("Iterations = %d\n", iter);

    return 0;
}