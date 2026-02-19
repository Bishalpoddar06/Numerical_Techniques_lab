/* Different tolerance limit */
#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x)
{
    return cos(x) - x * exp(x);
}

double df(double x)
{
    return -sin(x) - exp(x) - x * exp(x);
}

int main()
{
    double tolerances[] = {1e-2, 1e-4, 1e-5, 1e-6, 1e-8, 1e-10};
    int n = 6;

    double x0 = 0.5, x1, tol, error;
    int i, iter;
    clock_t start, end;
    double time_taken;

    printf("Newton-Raphson: cos(x) - x*e^x = 0\n\n");
    printf("Tolerance\tRoot\t\tIterations\tTime(s)\n");

    for (i = 0; i < n; i++)
    {
        tol = tolerances[i];
        x0 = 0.5;
        iter = 0;
        error = 1;

        start = clock();

        while (error >= tol && iter < 1000)
        {
            x1 = x0 - f(x0) / df(x0);
            error = fabs((x1 - x0) / x1);
            x0 = x1;
            iter++;
        }

        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%e\t%.6lf\t%d\t\t%lf\n", tol, x1, iter, time_taken);
    }

    return 0;
}

/*
OUTPUT-
Newton-Raphson: cos(x) - x*e^x = 0

Tolerance       Root            Iterations      Time(s)
1.000000e-02    0.517757        2               0.000004
1.000000e-04    0.517757        3               0.000001
1.000000e-05    0.517757        3               0.000002
1.000000e-06    0.517757        3               0.000000
1.000000e-08    0.517757        4               0.000001
1.000000e-10    0.517757        4               0.000001
*/
