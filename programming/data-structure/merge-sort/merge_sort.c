#include <stdio.h>
#include <stdlib.h>



TopDownMergeSort(int A[], int B[], int n)
{
    TopDownSplitMerge(A, 0, n, B);
}

void TopDownSplitMerge(int A[], int iBegin, int iEnd, int B[])
{
    if(iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
    // recursively split runs into two halves until run size == 1,
    // then merge them and return back up the call chain
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // split / merge left  half
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // split / merge right half
    TopDownMerge(A, iBegin, iMiddle, iEnd, B);  // merge the two half runs
    CopyArray(B, iBegin, iEnd, A);              // copy the merged runs back to A
}


void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle;
	int k;

 for (k = iBegin; k < iEnd; k++) {

if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    } 
}

void CopyArray(int B[], int iBegin, int iEnd, int A[])
{
	int k;
    	for(k = iBegin; k < iEnd; k++)
        	A[k] = B[k];
}

int main (void) {
 	int xx[10], yy[10];
	int i;

 	initstate(100,xx,10);
	for ( i = 0; i < 10; i++) {
		printf("%d \n ", xx[i]);
	}

	printf("after sorting \n");

	TopDownMergeSort(xx,yy,10);
	for ( i = 0; i < 10; i++) {
		printf("%d \n ", xx[i]);
	}
	printf("\n");

	return 0;
}

	

	
