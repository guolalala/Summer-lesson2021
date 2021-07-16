#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
int arr[100000];
int main()
{
    // srand(time(0));
    // freopen("in1.txt","w",stdout);
    // int n=50000;
    // printf("%d\n",n);
    // for(int i=0;i<n;i++)
    // printf("%d ",rand()%200000);

    //bubble-sort
    freopen("in1.txt","r",stdin);
    
    clock_t start,finish;
    double total_time;
    start=clock();

    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=arr[j];
            }
        }
    }
    for(int i=0;i<10;i++)printf("%d ",arr[i]);
    puts("");

    finish=clock();
    total_time=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("%.3f s\n",total_time);

}