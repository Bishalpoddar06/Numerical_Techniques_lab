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

    // Construct forward difference table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Print table EXACT like your output
    printf("\nForward Difference Table:\n");

    for (i = 0; i < n; i++) {
        printf("%0.2f\t", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("%0.2f\t", y[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the value to find (x): ");
    scanf("%f", &value);

    h = x[1] - x[0];
    p = (value - x[0]) / h;

    sum = y[0][0];
    term = 1;

    for (i = 1; i < n; i++) {
        term = term * (p - i + 1) / i;
        sum = sum + term * y[0][i];
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

Forward Difference Table:
-1.00   -637.00   540.50   -444.00   444.00   0.00
-0.50   -96.50    96.50    444.00    0.00
0.00    0.00      96.50    444.00
0.50    96.50     540.50
1.00    637.00

Enter the value to find (x): -0.75
Interpolated value = -283.500000
*/