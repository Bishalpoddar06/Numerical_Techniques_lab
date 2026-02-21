#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x)
{
    return cos(x) - x * exp(x);
}

int main()
{
    double a, b;
    int i;
    
    /* Given tolerance values */
    double tol[] = {1e-2, 1e-4, 1e-5, 1e-6, 1e-8, 1e-10};
    int total_tol = 6;

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    if (f(a) * f(b) >= 0)
    {
        printf("Invalid interval! f(a) and f(b) must have opposite signs.\n");
        return 0;
    }

    printf("\n--------------------------------------------------------------\n");
    printf("Tolerance\tIterations\tRoot\t\tExecution Time (s)\n");
    printf("--------------------------------------------------------------\n");

    for (int t = 0; t < total_tol; t++)
    {
        double tolerance = tol[t];
        double r, x, error;
        int iterations = 0;

        double left = a;
        double right = b;

        clock_t start = clock();

        r = (left + right) / 2.0;
        error = fabs(right - left);

        while (error > tolerance)
        {
            if (f(left) * f(r) < 0)
                right = r;
            else
                left = r;

            x = r;
            r = (left + right) / 2.0;
            error = fabs(r - x);

            iterations++;
        }

        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%e\t%d\t\t%.4f\t\t%f\n",
               tolerance, iterations, r, time_taken);
    }

    printf("--------------------------------------------------------------\n");

    printf("\nConclusion:\n");
    printf("As tolerance decreases (higher accuracy), the number of iterations\n");
    printf("increases, which slightly increases execution time.\n");
    printf("Thus, higher accuracy leads to higher computational cost.\n");

    return 0;
}
/*
OUPUT-
Enter a: 0
Enter b: 1

--------------------------------------------------------------
Tolerance       Iterations      Root            Execution Time (s)
--------------------------------------------------------------
1.000000e-02    6               0.5234          0.000007
1.000000e-04    13              0.5178          0.000004
1.000000e-05    16              0.5178          0.000003
1.000000e-06    19              0.5178          0.000004
1.000000e-08    26              0.5178          0.000005
1.000000e-10    33              0.5178          0.000006
--------------------------------------------------------------

Conclusion:
As tolerance decreases (higher accuracy), the number of iterations
increases, which slightly increases execution time.
Thus, higher accuracy leads to higher computational cost.
*/