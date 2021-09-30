/******************************
*Name: Tasfiah Tahsin Ahsan   *
*Id: 2012020258               *
*Lab Task - 1                 *
******************************/

#include <stdio.h>

void quicksort(int number[25],int first,int last){
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
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

Quick()
{
    int i, count, number[25];

   printf("\nEnter Array Size: ");
   scanf("%d", &count);

   printf("Array Values: ");
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

    quicksort(number,0,count-1);

    printf("\nAccording to Quick Sort, sorted data is: ");
    for(i=0;i<count;i++)
      printf("%d ", number[i]);
      printf("\n\n");
}
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

void mergesort(int a[],int i,int j)
{
	int mid;

	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);
		mergesort(a,mid+1,j);
		merge(a,i,mid,mid+1,j);
	}
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];
	int i,j,k;
	i=i1;
	j=i2;
	k=0;

	while(i<=j1 && j<=j2)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}

	while(i<=j1)
		temp[k++]=a[i++];

	while(j<=j2)
		temp[k++]=a[j++];

	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}


Merge()
{
    int a[30],n,i;
	printf("\nEnter Array Size: ");
	scanf("%d", &n);
	printf("Array Values: ");

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

    mergesort(a,0,n-1);

	printf("\nAccording to Merge Sort, sorted data is: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

     printf("\n\n");

}
Insertion()
{
    int n, i,k ,j,pos,num, arr[1000];

    printf("\nEnter Array Size: ");
    scanf("%d", &n);

    printf("Array Values: ");

    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1 ; i <= n - 1; i++) {
    k = arr[i];

    for (j = i - 1 ; j >= 0; j--) {
      if (arr[j] > k) {
        arr[j+1] = arr[j];
        pos = 1;
      }
      else
        break;
     }
     if (pos)
       arr[j+1] = k;
  }

   printf("\nAccording to Insertion Sort, sorted data is: ");

   for (int i = 0; i <= n - 1; i++) {
     printf("%d ", arr[i]);
  }
    printf("\n\n");
}

int main()
{
    int num;
    do
    {
        printf("Press 1: Insertion Sort\n");
        printf("Press 2: Merge Sort\n");
        printf("Press 3: Quick Sort\n");
        printf("Press 4: Exit\n\n");

        printf("Choose your option :");
        scanf("%d", &num);

        switch(num){
        case 1:
            Insertion();
            break;
        case 2:
            Merge();
            break;
        case 3:
            Quick();
            break;
        case 4:
            printf("\nProgram terminated.\n");
            break;
        default:
            printf("\nWrong input !!\n\n");
        }
    }
    while( num != 4);
    return 0;
}


