#include <stdio.h>
#include <math.h>
#include <time.h>

/* Define the function */
double f(double x)
{
    return cos(x) - x * exp(x);
}

int main()
{
    double a, b, c, tol;
    int iterations = 0;
    clock_t start, end;
    double time_taken;

    /* Input section */
    printf("Enter the initial interval a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the tolerance value: ");
    scanf("%lf", &tol);

    /* Check for valid interval */
    if (f(a) * f(b) >= 0)
    {
        printf("Invalid interval! f(a) and f(b) must have opposite signs.\n");
        return 0;
    }

    start = clock();

    /* Bisection Method */
    do
    {
        c = (a + b) / 2.0;
        iterations++;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(b - a) >= tol);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    /* Output section */
    printf("\nRoot of the equation = %.6f\n", c);
    printf("Number of iterations = %d\n", iterations);
    printf("Execution time = %lf seconds\n", time_taken);

    return 0;
}