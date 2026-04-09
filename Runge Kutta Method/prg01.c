#include <stdio.h>
float f(float x, float y)
{
    return (y*y - x*x) / (y*y + x*x);
}
int main()
{
    float x0, y0, xn, h;
    int n, i;
    printf("Enter initial value of x0: ");
    scanf("%f", &x0);
    printf("Enter initial value of y0: ");
    scanf("%f", &y0);
    printf("Enter value of xn: ");
    scanf("%f", &xn);
    printf("Enter number of steps n: ");
    scanf("%d", &n);
    h = (xn - x0) / n;
    printf("\nStep\t x\t\t y\n");
    printf("---------------------------------\n");
    printf("0\t %.4f\t %.4f\n", x0, y0);
    for(i = 1; i <= n; i++)
    {
        float k1, k2, k3, k4;
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);
        y0 = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;
        x0 = x0 + h;
        printf("%d\t %.4f\t %.4f\n", i, x0, y0);
    }
    return 0;
}

/*
OUTPUT-
Enter initial value of x0: 0
Enter initial value of y0: 1
Enter value of xn: 1
Enter number of steps n: 10

Step     x               y
---------------------------------
0        0.0000  1.0000
1        0.1000  1.0994
2        0.2000  1.1960
3        0.3000  1.2882
4        0.4000  1.3753
5        0.5000  1.4569
6        0.6000  1.5331
7        0.7000  1.6038
8        0.8000  1.6691
9        0.9000  1.7291
10       1.0000  1.7839
*/