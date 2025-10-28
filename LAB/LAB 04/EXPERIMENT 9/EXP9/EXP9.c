#include <stdio.h>
#include <string.h>
#define d 256     // number of characters in input alphabet

#define q 101     // a prime number for Rabin-Karp

// ======================== KMP ALGORITHM ==========================
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    int found = 0;

    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("KMP Match found at index %d\n", i - j);
            j = lps[j - 1];
            found = 1;
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        printf("KMP: No match found.\n");
}

// ===================== RABIN-KARP ALGORITHM ======================
void RabinKarpSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;
    int found = 0;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == M) {
                printf("Rabin-Karp Match found at index %d\n", i);
                found = 1;
            }
        }

        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = (t + q);
        }
    }

    if (!found)
        printf("Rabin-Karp: No match found.\n");
}

// ========================= MAIN FUNCTION =========================
int main() {
    char text[500], pattern[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // remove newline

    printf("\n==== Knuth-Morris-Pratt (KMP) Algorithm ====\n");
    KMPSearch(pattern, text);

    printf("\n==== Rabin-Karp Fingerprinting Algorithm ====\n");
    RabinKarpSearch(pattern, text);

    return 0;
}
