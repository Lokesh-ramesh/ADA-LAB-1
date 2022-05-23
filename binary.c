#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int a[1000],t;
    time_t st,ed;
    int beg=0,end = 9;
    int mid;
    int ele,flag = 0;

    for(int i = 0;i<1000;i++)
    {
        a[i] = rand()%1000 + 1;
    }

    st = time(NULL);
    for(int p=0;p<1000;p++)
    {
        for(int q = 0;q<1001;q++)
        {
            if(a[q]>a[q+1])
            {
                t = a[q];
                a[q] = a[q+1];
                a[q+1] = t;
            }
        }
    }
    for(int k = 0;k<1000;k++)
    {
        printf("%d,",a[k]);
    }



    printf("\n");
    printf("ENTER ELEMENT TO SEARCH \n");
    scanf("%d",&ele);


    while(beg<=end)
    {
        mid = (beg+end)/2;
        if(a[mid] == ele)
        {
            printf("\n ELEMENT FOUND");
            flag = 1;
            break;
        }
        if(ele > a[mid])
        {
            beg = mid+1;
        }
        if(ele < a[mid])
        {
            end = mid-1;
        }
    }

    if(flag == 0)
    {
        printf("\n ELEMENT NOT FOUND");
    }
ed = time(NULL);

    printf("\n TIME TAKEN = %f", difftime(ed,st));
    return 0;
}

