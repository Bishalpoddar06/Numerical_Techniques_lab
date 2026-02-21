/* FOURTH PROBLEM */
#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x)
{
    return cos(x) - x * exp(x);
}

int main()
{
    double tol_list[] = {1e-2, 1e-4, 1e-5, 1e-6, 1e-8, 1e-10};
    int n = 6;

    double a0 = 0.0, b0 = 1.0;
    int N = 1000;

    for (int k = 0; k < n; k++)
    {
        double a = a0, b = b0;
        double fa, fb, fr, r, y, error;
        int iter = 0;

        clock_t start = clock();

        fa = f(a);
        fb = f(b);

        y = b;
        r = a - (a - b) * fa / (fa - fb);
        error = fabs((y - r) / r);

        while (error > tol_list[k] && iter <= N)
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

        clock_t end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Tolerance = %.0e\n", tol_list[k]);
        printf("Root = %.10lf\n", r);
        printf("Iterations = %d\n", iter);
        printf("Time = %lf sec\n\n", time);
    }

    return 0;
}