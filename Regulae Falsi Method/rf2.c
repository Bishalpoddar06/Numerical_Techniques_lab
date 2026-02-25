#include <stdio.h>
#include <math.h>
double f(double x) {
    return cos(x) - x * exp(x);
}
double fprime(double x) {
    return -sin(x) - exp(x) - x * exp(x);
}
int main() {
    double x0 = 0.5; 
    double x1;
    double tol = 1e-6, er = 1.0;
    int iter = 0;
    while (er > tol) {
        x1 = x0 - f(x0)/fprime(x0); 
        er = fabs((x1 - x0) / x1); 
        x0 = x1;
        iter++;
    }
    printf("Root ≈ %.6f (found in %d iterations)\n", x1, iter);
    return 0;
}
/*
OUTPUT-
Root ≈ 0.517757 (found in 3 iterations)
*/