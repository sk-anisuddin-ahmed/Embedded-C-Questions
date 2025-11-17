/*
5. Find the intersection of two unsorted arrays
Return common elements between two arrays without using additional space, or 
use a hash-set for optimized solution.

Example: Input: A = [1, 2, 4, 5], B = [2, 3, 5, 7]
Output: [2, 5]
*/

#include <stdio.h>

int intersection(int A[], int nA, int B[], int nB, int out[])
{
    int k = 0;
    for (int i = 0; i < nA; ++i)
    {
        for (int j = 0; j < nB; ++j)
        {
            if (A[i] == B[j]) 
            { 
                out[k++] = A[i];
            }
        }
    }
    return k;
}

int main(void)
{
    int A[] = {1,2,4,5};
    int B[] = {2,3,5,7};
    int Alen = sizeof(A)/sizeof(A[0]);
    int Blen = sizeof(B)/sizeof(B[0]);
    int out[Alen < Blen ? Alen : Blen];
    int cnt = intersection(A, Alen, B, Blen, out);
    
    for (int i = 0; i < cnt; ++i)
    {
        printf("%d ", out[i]);
    }

    return 0;
}
