#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(-x) * cos(x);
}

int main() {
    int n, i;
    double a, b, h, sum = 0;

    printf("Enter lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter upper limit (b): ");
    scanf("%lf", &b);

    printf("Enter number of intervals (n): ");
    scanf("%d", &n);

    h = (b - a) / n;

    for (i = 0; i <= n; i++) {
        if (i == 0 || i == n)
            sum += f(a + i * h);
        else
            sum += 2 * f(a + i * h);
    }

    sum = (h * sum) / 2;

    printf("Integral value = %.5lf\n", sum);

    return 0;
}

/*
OUTPUT-
Enter lower limit (a): 0
Enter upper limit (b): 1.57
Enter number of intervals (n): 12
Integral value = 0.60507
*/