#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// LU decomposition without pivoting
void LUDecomposition(int n, float A[n][n], float L[n][n], float U[n][n]) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            L[i][j] = (i == j) ? 1 : 0;
            U[i][j] = A[i][j];
        }
    }

    for (k = 0; k < n - 1; k++) {
        if (U[k][k] == 0) {
            printf("Error: Zero pivot element detected.\n");
            exit(1);
        }
        for (i = k + 1; i < n; i++) {
            L[i][k] = U[i][k] / U[k][k];
            for (j = k; j < n; j++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
    }
}

// Forward substitution solve Ly = b
void forwardSubstitution(int n, float L[n][n], float b[n], float y[n]) {
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        // L[i][i] is 1 in this case
    }
}

// Backward substitution solve Ux = y
void backwardSubstitution(int n, float U[n][n], float y[n], float x[n]) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        if (U[i][i] == 0) {
            printf("Error: Zero pivot element detected during back substitution.\n");
            exit(1);
        }
        x[i] /= U[i][i];
    }
}


void printMatrix(int n, float M[n][n], const char *name) {
    printf("\n%s Matrix:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.3f ", M[i][j]);
        }
        printf("\n");
    }
}


void printVector(int n, float v[n], const char *name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < n; i++) {
        printf("%8.3f\n", v[i]);
    }
}

int main() {
    int n;

    printf("Enter the order of the square matrix (n): ");
    scanf("%d", &n);

    float A[n][n], L[n][n], U[n][n], b[n], y[n], x[n];

    printf("Enter the elements of matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter the elements of vector b (%d entries):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    LUDecomposition(n, A, L, U);
    printMatrix(n, L, "L");
    printMatrix(n, U, "U");

    forwardSubstitution(n, L, b, y);
    backwardSubstitution(n, U, y, x);

    printVector(n, x, "Solution x");

    return 0;
}
