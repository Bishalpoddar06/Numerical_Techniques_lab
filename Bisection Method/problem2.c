#include <stdio.h>
#include <math.h>

double f(double x)
{
    return cos(x) - x * exp(x);   
}

int main()
{
    double a, b, r, fa, fb, fr;
    double tol, error, y;
    int i = 0, N;

    /* Input section */
    printf("Enter initial values a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter tolerance (epsilon): ");
    scanf("%lf", &tol);

    printf("Enter maximum iterations N: ");
    scanf("%d", &N);


    fa = f(a);
    fb = f(b);

    if (fa * fb >= 0)
    {
        printf("Invalid interval! f(a) and f(b) must have opposite signs.\n");
        return 0;
    }


    r = (a + b) / 2.0;
    y = b;
    error = fabs(y - r) / fabs(r);

    while (error > tol && i <= N)
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
        r = (a + b) / 2.0;
        error = fabs(y - r) / fabs(r);

        i++;
    }


    if (i > N)
        printf("ERROR: Maximum iterations exceeded\n");
    else
        printf("Approximate root = %.6lf\n", r);

    printf("Iterations = %d\n", i);

    return 0;
}
