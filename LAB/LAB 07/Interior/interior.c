#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPS 1e-6
#define STEP 0.01     // small gradient step

// Objective: maximize cᵀx - barrier * Σ log(b - A x)
double objective(double x[], double A[MAX][MAX], double b[],
                 double c[], int m, int n, double barrier)
{
    double val = 0.0;
    for (int i = 0; i < n; i++)
        val += c[i] * x[i];

    for (int i = 0; i < m; i++) {
        double s = b[i];
        for (int j = 0; j < n; j++)
            s -= A[i][j] * x[j];
        if (s <= 0) return -1e9; // infeasible
        val -= barrier * log(s);
    }
    return val;
}

int main()
{
    int m, n;
    double A[MAX][MAX], b[MAX], c[MAX], x[MAX];
    double barrier = 1.0;

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

    printf("\nEnter objective function coefficients c:\n");
    for (int j = 0; j < n; j++)
        scanf("%lf", &c[j]);

    // start feasible point x = (0.1, 0.1, ...)
    for (int j = 0; j < n; j++)
        x[j] = 0.1;

    // interior-point iterations
    for (int iter = 0; iter < 5000; iter++) {
        for (int j = 0; j < n; j++) {
            double grad = -c[j]; // ascent → negative gradient

            for (int i = 0; i < m; i++) {
                double s = b[i];
                for (int k = 0; k < n; k++)
                    s -= A[i][k] * x[k];
                grad += barrier * (A[i][j] / s);
            }

            x[j] += STEP * grad;  // gradient ascent
            if (x[j] < 0) x[j] = EPS;
        }

        barrier *= 0.999; // reduce barrier
    }

    printf("\nOptimal Solution (Interior Point Method):\n");
    for (int j = 0; j < n; j++)
        printf("x%d = %.4f\n", j + 1, x[j]);

    double Z = 0;
    for (int j = 0; j < n; j++)
        Z += c[j] * x[j];
    printf("Max Z = %.4f\n", Z);

    return 0;
}
