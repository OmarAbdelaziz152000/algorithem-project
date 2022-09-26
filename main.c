#include <stdio.h>
#include <stdlib.h>
void print(int colors[],int n);
void mergeSort(int arr[],int l,int r);
void merge(int arr[], int l, int m, int r);

int main()
{
    int n;
    printf("Enter the number of colors :\n");
    scanf("%d",&n);
    if(n<=300 && n>=1);
    else
    {
        printf("Invalid size :(\n");
        return 0;
    }
    int colors[n];
    printf("Enter the colors :\n");

    for(int i=0; i<n; i++)
        scanf("%d",&colors[i]);

    for(int i=0; i<n; i++)
    {
        if(colors[i]!= 0 && colors[i]!= 1 && colors[i]!= 2 )
        {
            printf("Invalid color number :(\n");
            return 0;
        }
    }

 int arr_size = sizeof(colors) / sizeof(colors[0]);
    mergeSort(colors,0,arr_size -1);
    print(colors,n);

    return 0;
}

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void print(int colors[],int n)
{
    printf("\n\nSorted Colors :\n");
    for(int i=0; i<n; i++)
        printf("%d \n", colors[i]);

}
