/* Real root for upto 4 decimal digits */
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
    double x0, x1, tol, error;
    int i = 0, max_iter;

    printf("Solve: cos(x) - x*e^x = 0\n");
    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    printf("Enter max iterations: ");
    scanf("%d", &max_iter);

    error = 1;

    while (error >= tol && i < max_iter)
    {
        if (df(x0) == 0)
        {
            printf("Derivative zero. Method fails.\n");
            return 0;
        }

        x1 = x0 - f(x0) / df(x0);
        error = fabs((x1 - x0) / x1);

        x0 = x1;
        i++;
    }

    printf("\nRoot = %.4lf\n", x1);   
    printf("Iterations = %d\n", i);

    return 0;
}

/*
OUTPUT-
Solve: cos(x) - x*e^x = 0
Enter initial guess: 0.5
Enter tolerance: 0.001
Enter max iterations: 12

Root = 0.5178
Iterations = 2
*/