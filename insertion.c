#include<stdio.h>
#include<time.h>
#include <sys/time.h>
#include<stdlib.h>

#define SIZE 100000
#define SIZE1 10

void insertion_sort(int a[],int n)
{
    int i,j;
    int key;
    for (i=1;i<=n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    struct timeval value ,value1;
    struct timezone time_z,tz1;
    struct tm *tm;
    clock_t start,end;
    int i,n,a1[SIZE1],total;
    long int a[SIZE];
    FILE *fptr;


    for (i=0;i<SIZE1;i++)
    {
        a1[i]=rand()%100000+1;
    }
    gettimeofday(&value , &time_z);

    insertion_sort(a1,SIZE1);

    tm=localtime(&value.tv_sec);
    printf(" To sort 10 input it took %d m sec \n",tm->tm_sec);

    fptr = fopen("program1.txt","w");


    for (i=0;i<SIZE;i++)
    {
      fprintf(fptr,"%d\n",rand()%100000+1);
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

    insertion_sort(a,SIZE);

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
