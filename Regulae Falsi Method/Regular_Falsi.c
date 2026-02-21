/* MAIN CODE FOR REGULAR FALSI METHOD */
#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x)
{
    return cos(x) - x * exp(x);
}

int main()
{
    double a, b, r, y, fa, fb, fr, tol, error;
    int iter = 0, N = 1000;
    clock_t start, end;

    printf("Enter a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    fa = f(a);
    fb = f(b);

    if (fa * fb > 0)
    {
        printf("Invalid interval\n");
        return 0;
    }

    start = clock();

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

    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    if (iter > N)
        printf("ERROR: Iteration limit exceeded\n");
    else
    {
        printf("Root = %.6lf\n", r);
        printf("Iterations = %d\n", iter);
        printf("Execution Time = %lf sec\n", time);
    }

    return 0;
}
