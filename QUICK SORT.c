#include<stdio.h>
#include<time.h>
#include <sys/time.h>
#include<stdlib.h>

#define SIZE 100000
#define SIZE1 10

void quickSort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
     quickSort(number,first,j-1);
      quickSort(number,j+1,last);

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

    quickSort(a1,0,SIZE1-1);

    tm=localtime(&time_v.tv_sec);
    printf(" 10 input  to do the sorting took %d m sec \n",tm->tm_sec);

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

   quickSort(a,0,SIZE-1);

    end = clock();
    fptr=fopen("out.txt","w");


    for (i=0;i<SIZE;i++)
    {
        fprintf(fptr,"%d\n",a[i]);
    }
    fclose(fptr);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\n For 1M input time took %d m sec\n",total);


    int tt=total-tm->tm_sec;
    printf("\nTime difference: %d m sec\n",tt);

    return 0;
}
