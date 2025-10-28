#include <stdio.h>
#include <string.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to print the Longest Common Subsequence
void printLCS(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];

    // Build the LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Length of LCS
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Null terminate the string

    // Backtrack to find the LCS string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLongest Common Subsequence: %s\n", lcs);
}

// Function to print all common subsequences (brute-force)
void printAllCommonSubsequences(char X[], char Y[]) {
    printf("\nAll Common Subsequences:\n");

    int lenX = strlen(X);
    int lenY = strlen(Y);

    printf("(These may include duplicates for repeated characters)\n");
    for (int i = 0; i < lenX; i++) {
        for (int j = 0; j < lenY; j++) {
            if (X[i] == Y[j])
                printf("%c ", X[i]);
        }
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    printLCS(str1, str2, m, n);
    printAllCommonSubsequences(str1, str2);

    return 0;
}
