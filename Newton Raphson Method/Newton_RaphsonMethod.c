/* Code for the Newton-Raphson method */
#include <stdio.h>
#include <math.h>

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
    double a, r, tol, error;
    int i = 0, max_iter;

    printf("Enter initial guess: ");
    scanf("%lf", &a);

    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    printf("Enter max iterations: ");
    scanf("%d", &max_iter);

    error = 1;

    while (error >= tol && i <= max_iter)
    {
        if (df(a) == 0)
        {
            printf("Derivative zero. Method fails.\n");
            return 0;
        }

        r = a - f(a) / df(a);
        error = fabs((r - a) / r);
        a = r;
        i++;
    }

    if (i > max_iter)
        printf("Root not found\n");
    else
    {
        printf("Root = %.6lf\n", r);
        printf("Iterations = %d\n", i);
    }

    return 0;
}

/*
OUTPUT-
Enter initial guess: 0
Enter tolerance: 0.001
Enter max iterations: 1000
Root = 0.517757
Iterations = 5
*/
