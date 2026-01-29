#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 4 * pow(x, 3) - 6 * pow(x, 2) + 7 * x - 2.3;
}

int main()
{
    int i = 0, n;
    float a, b, x, er, r, toll;

    printf("Enter a: ");
    scanf("%f", &a);

    printf("Enter b: ");
    scanf("%f", &b);

    printf("Enter Tolerance: ");
    scanf("%f", &toll);

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    if (f(a) * f(b) >= 0)
    {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return 0;
    }

    r = (a + b) / 2;
    er = 1;

    while (er >= toll && i < n)
    {
        if (f(r) * f(a) < 0)
            b = r;
        else
            a = r;

        x = r;
        r = (a + b) / 2;

        if (x != 0)
            er = fabs((r - x) / x);

        i++;
    }

    if (i == n)

        printf("Root not found within %d iterations.\n");
    else
        printf("The root is = %f\n", r);

    return 0;
}
/*
OUTPUT-
Enter a: 0
Enter b: 1
Enter Tolerance: 0.001
Enter number of iterations: 15
The root is = 0.449951
*/
