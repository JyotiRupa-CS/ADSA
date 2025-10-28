#include <stdio.h>
#include <stdlib.h>

#define MAX 8 // Maximum matrix size (must be a power of 2)

// Function to add two matrices
void add(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// Function to subtract two matrices
void subtract(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] - b[i][j];
}

// Strassen’s recursive matrix multiplication function
void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;
    int a11[MAX][MAX], a12[MAX][MAX], a21[MAX][MAX], a22[MAX][MAX];
    int b11[MAX][MAX], b12[MAX][MAX], b21[MAX][MAX], b22[MAX][MAX];
    int c11[MAX][MAX], c12[MAX][MAX], c21[MAX][MAX], c22[MAX][MAX];
    int p1[MAX][MAX], p2[MAX][MAX], p3[MAX][MAX], p4[MAX][MAX], p5[MAX][MAX], p6[MAX][MAX], p7[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];

    // Divide matrices into quadrants
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + mid];
            a21[i][j] = A[i + mid][j];
            a22[i][j] = A[i + mid][j + mid];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + mid];
            b21[i][j] = B[i + mid][j];
            b22[i][j] = B[i + mid][j + mid];
        }
    }

    // P1 = (A11 + A22)(B11 + B22)
    add(a11, a22, temp1, mid);
    add(b11, b22, temp2, mid);
    strassen(temp1, temp2, p1, mid);

    // P2 = (A21 + A22)B11
    add(a21, a22, temp1, mid);
    strassen(temp1, b11, p2, mid);

    // P3 = A11(B12 - B22)
    subtract(b12, b22, temp2, mid);
    strassen(a11, temp2, p3, mid);

    // P4 = A22(B21 - B11)
    subtract(b21, b11, temp2, mid);
    strassen(a22, temp2, p4, mid);

    // P5 = (A11 + A12)B22
    add(a11, a12, temp1, mid);
    strassen(temp1, b22, p5, mid);

    // P6 = (A21 - A11)(B11 + B12)
    subtract(a21, a11, temp1, mid);
    add(b11, b12, temp2, mid);
    strassen(temp1, temp2, p6, mid);

    // P7 = (A12 - A22)(B21 + B22)
    subtract(a12, a22, temp1, mid);
    add(b21, b22, temp2, mid);
    strassen(temp1, temp2, p7, mid);

    // Compute C quadrants
    // C11 = P1 + P4 - P5 + P7
    add(p1, p4, temp1, mid);
    subtract(temp1, p5, temp2, mid);
    add(temp2, p7, c11, mid);

    // C12 = P3 + P5
    add(p3, p5, c12, mid);

    // C21 = P2 + P4
    add(p2, p4, c21, mid);

    // C22 = P1 - P2 + P3 + P6
    subtract(p1, p2, temp1, mid);
    add(temp1, p3, temp2, mid);
    add(temp2, p6, c22, mid);

    // Combine results into C
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = c11[i][j];
            C[i][j + mid] = c12[i][j];
            C[i + mid][j] = c21[i][j];
            C[i + mid][j + mid] = c22[i][j];
        }
    }
}

int main() {
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};

    printf("Enter the size of the matrix (must be power of 2): ");
    scanf("%d", &n);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("\nResultant Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
