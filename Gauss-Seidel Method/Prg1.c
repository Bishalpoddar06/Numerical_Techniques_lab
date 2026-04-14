#include <stdio.h>
#include <math.h>

// Check diagonally dominant
int diagonally_dominant(double A[][10], int n) {
    for (int i = 0; i < n; i++) {
        double diag = fabs(A[i][i]);
        double sum = 0.0;

        for (int j = 0; j < n; j++) {
            if (j != i)
                sum += fabs(A[i][j]);
        }

        if (diag < sum)
            return 0;
    }
    return 1;
}

int main() {
    int i, j, k, n;

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    double A[10][10], b[10], x[10];

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the elements of b:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Initial guess
    for (i = 0; i < n; i++)
        x[i] = 1;

    if (!diagonally_dominant(A, n)) {
        printf("Gauss-Seidel may not converge.\n");
    } else {
        printf("Matrix is diagonally dominant\n");
    }

    printf("\nGauss-Seidel iterations:\n");

    for (k = 1; k <= 3; k++) {
        for (i = 0; i < n; i++) {
            double sum = b[i];

            for (j = 0; j < n; j++) {
                if (j != i)
                    sum -= A[i][j] * x[j];
            }

            x[i] = sum / A[i][i];
        }

        printf("Iteration %d: ", k);
        for (i = 0; i < n; i++) {
            printf("%.4lf ", x[i]);
        }
        printf("\n");
    }

    return 0;
}
/*
OUTPUT-
Enter the size of the matrix: 4

Enter the elements of A:
3 1 1 9
2 8 1 -4
5 1 7 0.8
1 1 -3 5

Enter the elements of b:
14 7 13.8 4

Gauss-Seidel may not converge.

Gauss-Seidel iterations:

Iteration 1: 1.0000 1.0000 1.0000 1.0000
Iteration 2: 1.0000 1.0000 1.0000 1.0000
Iteration 3: 1.0000 1.0000 1.0000 1.0000
*/