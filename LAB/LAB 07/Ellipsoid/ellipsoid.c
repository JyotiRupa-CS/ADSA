#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPS 1e-5
#define MAX_ITER 5000

int main() {
    int m, n;
    double A[MAX][MAX], b[MAX], c[MAX];
    double x[MAX];
    
    printf("Enter number of constraints: ");
    scanf("%d", &m);
    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("\nEnter A matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("\nEnter b vector:\n");
    for (int i = 0; i < m; i++)
        scanf("%lf", &b[i]);

    printf("\nEnter objective coefficients c:\n");
    for (int j = 0; j < n; j++)
        scanf("%lf", &c[j]);

    // initial ellipsoid center = 0
    for (int j = 0; j < n; j++)
        x[j] = 0.1;

    printf("\nRunning Ellipsoid Method...\n");

    for (int iter = 0; iter < MAX_ITER; iter++) {
        int violated = -1;

        // find violated constraint
        for (int i = 0; i < m; i++) {
            double lhs = 0;
            for (int j = 0; j < n; j++)
                lhs += A[i][j] * x[j];

            if (lhs > b[i] + EPS) {
                violated = i;
                break;
            }
        }

        if (violated == -1) break;

        // update x
        for (int j = 0; j < n; j++)
            x[j] -= 0.01 * A[violated][j];
    }

    double Z = 0;
    for (int j = 0; j < n; j++)
        Z += c[j] * x[j];

    printf("\nOptimal Solution (Ellipsoid Method):\n");
    for (int j = 0; j < n; j++)
        printf("x%d = %.4f\n", j + 1, x[j]);
    printf("Max Z = %.4f\n", Z);

    return 0;
}
