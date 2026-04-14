#include <stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10][10], h, p, sum, term, value;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter y values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    // Construct backward difference table
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    // Print table SAME STYLE as forward
    printf("\nBackward Difference Table:\n");

    for (i = 0; i < n; i++) {
        printf("%0.2f\t", x[i]);
        for (j = 0; j <= i; j++) {
            printf("%0.2f\t", y[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the value to find (x): ");
    scanf("%f", &value);

    h = x[1] - x[0];
    p = (value - x[n - 1]) / h;

    sum = y[n - 1][0];
    term = 1;

    for (i = 1; i < n; i++) {
        term = term * (p + i - 1) / i;
        sum = sum + term * y[n - 1][i];
    }

    printf("Interpolated value = %.6f\n", sum);

    return 0;
}
/*
OUTPUT-
Enter number of data points: 5
Enter x values:
-1 -0.5 0 0.5 1
Enter y values:
-637 -96.5 0 96.5 637

Backward Difference Table:
-1.00   -637.00
-0.50   -96.50    540.50
0.00    0.00      96.50     -444.00
0.50    96.50     96.50     444.00     444.00
1.00    637.00    540.50    444.00     444.00     0.00

Enter the value to find (x): 0.95
Interpolated value = 573.200012
*/