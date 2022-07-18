#include<stdio.h>
void quicksort(int arr[25],int first,int last)
{
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(arr[i]<=arr[pivot]&&i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,first,j-1);
        quicksort(arr,j+1,last);
    }
}
int main()
{
    int i, n, arr[25];
    time_t st,ed;
    printf("ENTER ARRAY SIZE =");
    scanf("%d",&n);
    printf("ENTER ARRAY ELEMENTS = ");
    for (int j = 0; j < n; j++)
    {
        arr[j] = (rand() % 1000) + 1;
        printf("%4d", arr[j]);
    }
    printf("\n");
    st = time(NULL);
    quicksort(arr,0,n-1);
    ed = time();
    printf("\n TIME TAKEN = %f \n",difftime(ed,st));
    printf("\nSORTED ELEMNETS = ");
    for(i=0; i<n; i++)
        printf(" %d",arr[i]);
    return 0;
}
