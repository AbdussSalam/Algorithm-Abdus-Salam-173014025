#include<stdio.h>
#include<time.h>
#include <sys/time.h>
#include<stdlib.h>

#define SIZE 100000
#define SIZE1 10

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void marge_sort(int arr[], int l, int r)
{
    if(l < r)
    {

        int m = l+(r-l)/2;


        marge_sort(arr, l, m);
        marge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    struct timeval time_v,time_v1;
    struct timezone time_z,tz1;
    struct tm *tm;
    clock_t start,end;
    int i,n,a1[SIZE1],total;
    long int a[SIZE];
    FILE *fptr;


    for (i=0;i<SIZE1;i++)
    {
        a1[i]=rand()%1000+1;
    }
    gettimeofday(&time_v, &time_z);

    marge_sort(a1,0,SIZE1-1);

    tm=localtime(&time_v.tv_sec);
    printf(" To sort 10 input  it took %d m sec \n",tm->tm_sec);

    fptr = fopen("program1.txt","w");


    for (i=0;i<SIZE;i++)
    {
      fprintf(fptr,"%d\n",rand()%1000+1);
    }

    fflush(fptr);
    fclose(fptr);
    fptr = fopen("program1.txt","r");
    start = clock();


    for(i=0;i<SIZE;i++)
    {
       fscanf(fptr,"%d",&a[i]);

    }
    fclose(fptr);

    marge_sort(a,0,SIZE-1);

    end = clock();
    fptr=fopen("out.txt","w");


    for (i=0;i<SIZE;i++)
    {
        fprintf(fptr,"%d\n",a[i]);
    }
    fclose(fptr);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\n To sort 1M input it took %d m sec\n",total);


    int tt=total-tm->tm_sec;
    printf("\nTime difference: %d m sec\n",tt);

    return 0;
}
