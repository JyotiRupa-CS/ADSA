#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // maximum number of variables and constraints

void print_tableau(float tableau[MAX][MAX], int m, int n) {
    printf("\nCurrent Simplex Tableau:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%8.2f ", tableau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int m, n;
    float tableau[MAX][MAX];
    int i, j, pivot_col, pivot_row;
    float ratio[MAX], pivot, min_ratio;
    
    printf("Enter number of constraints: ");
    scanf("%d", &m);
    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("\nEnter the coefficients of constraints (A matrix):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &tableau[i][j]);
        }
    }

    printf("\nEnter the RHS values (b):\n");
    for (i = 0; i < m; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%f", &tableau[i][n]);
    }

    printf("\nEnter the coefficients of the objective function (c):\n");
    for (j = 0; j < n; j++) {
        printf("c[%d]: ", j + 1);
        scanf("%f", &tableau[m][j]);
        tableau[m][j] = -tableau[m][j]; // for maximization
    }
    tableau[m][n] = 0;

    // Simplex iterations
    while (1) {
        print_tableau(tableau, m, n);

        // Step 1: Find pivot column (most negative entry in last row)
        pivot_col = 0;
        for (j = 1; j < n; j++)
            if (tableau[m][j] < tableau[m][pivot_col])
                pivot_col = j;

        if (tableau[m][pivot_col] >= 0)
            break; // optimal solution found

        // Step 2: Find pivot row (minimum positive ratio)
        min_ratio = 99999;
        pivot_row = -1;
        for (i = 0; i < m; i++) {
            if (tableau[i][pivot_col] > 0) {
                ratio[i] = tableau[i][n] / tableau[i][pivot_col];
                if (ratio[i] < min_ratio) {
                    min_ratio = ratio[i];
                    pivot_row = i;
                }
            }
        }

        if (pivot_row == -1) {
            printf("Unbounded solution.\n");
            return 0;
        }

        // Step 3: Pivot operation
        pivot = tableau[pivot_row][pivot_col];
        for (j = 0; j <= n; j++)
            tableau[pivot_row][j] /= pivot;

        for (i = 0; i <= m; i++) {
            if (i != pivot_row) {
                float factor = tableau[i][pivot_col];
                for (j = 0; j <= n; j++)
                    tableau[i][j] -= factor * tableau[pivot_row][j];
            }
        }
    }

    // Print optimal result
    printf("\nOptimal Solution Found!\n");
    printf("Zmax = %.2f\n", tableau[m][n]);
    for (j = 0; j < n; j++) {
        int is_basic = 0, basic_row = -1;
        for (i = 0; i < m; i++) {
            if (tableau[i][j] == 1) {
                is_basic++;
                basic_row = i;
            } else if (tableau[i][j] != 0) {
                is_basic = -1;
                break;
            }
        }
        if (is_basic == 1)
            printf("x%d = %.2f\n", j + 1, tableau[basic_row][n]);
        else
            printf("x%d = 0.00\n", j + 1);
    }

    return 0;
}
