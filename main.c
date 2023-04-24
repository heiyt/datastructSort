#include "main.h"

int a[] = {688,24,525,747,2526,754,8875,45,34,678,31};

int guoqiHeLan[3] = {2,1,3};

int main()
{
    int n;
    n = sizeof(a)/sizeof(a[0]);

    showList(a,n);
    //DoubleBubbleSort(a,n);
    //BubbleSort(a,n);
    //FastSort(a,0,n-1);
    //JishuAheadOushu(a,n);
    //InsertSort(a,n);
    SelectSort(a,n);
    //SortFlagOfHeLan(a);

    //printf("%d ",FindMidSelf(a,n));
    showList(a,n);
    return 0;
}
