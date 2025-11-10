/*
7. Merge two sorted arrays without using extra space
Merge two sorted arrays A[] and B[] such that A contains the first n elements and B the rest, and after merging both are still sorted.

Example: Input: A = [1, 3, 5], B = [2, 4, 6]
Output: A = [1, 2, 3], B = [4, 5, 6]
*/

#include <stdio.h>

void mergeNoExtra(int A[], int n, int B[], int m)
{
    int pA = n - 1;
    int pB = m - 1;

    for (; pA >= 0 && pB >= 0; )
    {
        if (A[pA] > B[pB])
        {
            int temp = A[pA];
            A[pA] = B[pB];
            B[pB] = temp;
            --pA;
        }
        else
        {
            --pB;
        }
    }
}

int main(void)
{
    int A[] = {1,3,5};
    int B[] = {2,4,6};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    mergeNoExtra(A, n, B, m);
    printf("After merging:\nA: ");
    for (int i = 0; i < n; ++i) printf("%d ", A[i]);
    printf("\nB: ");                
    for (int i = 0; i < m; ++i) printf("%d ", B[i]);
    printf("\n");
    return 0;
}
