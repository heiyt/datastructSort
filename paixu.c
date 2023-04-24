#include "main.h"

void InsertSort(int list[],int n)//直接插入排序（因为要与其他排序方法共用同一个被排列的数组，所以这个不用哨兵）
{
    static int i,j;
    int temp;
    for(i = 1;i < n;i++){
        if(list[i]<list[i-1]){
            temp = list[i];
            for(j = i-1;temp<list[j];j--){
                list[j+1] = list[j];
            }
            list[j+1] = temp;
        }
    }
}

void BubbleSort(int list[],int n)//冒泡排序
{
    static int i,j;static int temp;bool flag;
    flag = true;
    for(i = 1;flag && i<n-1;i++){
        flag = false;
        for(j = 0;j<n-i;j++){
            if(list[j]>list[j+1]){
                flag = true;
                swap(&list[j],&list[j+1]);
            }
        }
    }
}

void DoubleBubbleSort(int list[],int n)//双冒泡排序
{
    static int i,j,high,low;static int temp;bool flag;
    high = n-1;low = 0;flag = true;
    while(high>low&&flag){
        for(i = low;i<high;i++){
            if(list[i]>list[i+1]){
                flag = true;
                swap(&list[i],&list[i+1]);
            }
        }
        high--;
        for(j = high;j>low;j--){
            if(list[j]<list[j-1]){
                flag = true;
                swap(&list[j],&list[j-1]);
            }
        }
        low++;
    }
}

void JishuAheadOushu(int list[],int n)//奇数在前偶数在后
{
    static int i,j;
    i = 0;j = n-1;
    while (i<j)
    {
        while(i<j&&list[i]%2!=0){
            i++;
        }
        while(i<j&&list[j]%2==0){
            j--;
        }
        swap(&list[i],&list[j]);
        i++;j--;
        /* code */
    }
}

int Partition(int list[],int low,int high)
{
    int pivot;
    pivot = list[low];
    while(high>low){
        while(list[high] > pivot && low < high){
            high--;
        }
        list[low] = list[high];
        while (list[low] < pivot && low <high){
            low++;
        }
        list[high] = list[low];
    }
    list[low] = pivot;
    return low;
}

int Partition2(int list[],int low,int high)
{
    int pivot;
    int i,j;
    pivot = list[low];
    j = low;
    for(i = low+1;i<=high;i++){
        if(list[i]<pivot){
            swap(&list[++j],&list[i]);
        }
    }
    swap(&list[low],&list[j]);
    return j;
}

int PartitionRandom(int list[],int low,int high)//每次随即选取pivot
{
    int pivot;
    int random;
    random = low + rand()%(high - low);
    swap(&list[low],&list[random]);
    pivot = list[low];
    while(high>low){
        while(list[high] > pivot && low < high){
            high--;
        }
        list[low] = list[high];
        while (list[low] < pivot && low <high){
            low++;
        }
        list[high] = list[low];
    }
    list[low] = pivot;
    return low;
}

void FastSort(int list[],int low,int high)//快速排序
{
    int pivotpos;
    if(low<high){
        pivotpos = Partition2(list,low,high);
        //pivotpos = Partition(list,low,high);
        //pivotpos = PartitionRandom(list,low,high);
        FastSort(list,low,pivotpos-1);
        FastSort(list,pivotpos+1,high);
    }
}

void SortFlagOfHeLan(int list[])
{
    static int i;
    for(i = 0;i<3;i++){
        switch (list[i])
        {
            case 1:swap(&list[i],&list[0]);break;
            case 2:swap(&list[i],&list[1]);break;
            case 3:swap(&list[i],&list[2]);break;
            default:break;
        }
    }
}

void SelectSort(int list[],int n)//简单选择排序
{
    int i,j;
    int min;
    i = j = min = 0;
    for(i = 0;i < n-1;i++){
        min = i;
        for(j = i;j<n;j++){
            if(list[min] > list[j]){
                min = j;
            }
        }
        swap(&list[i],&list[min]);
    }
}

int FindMid(int list[],int n)
{
    bool flag;
    int low0,high0,low,high,k,i;
    int pivot;int s1,s2;
    s1 = s2 = 0;//有时候不是默认为0,需要自己赋值初值
    high = n - 1;high0 = n - 1;
    low = low0 = 0;
    flag = true;
    k = n/2;
    while(flag){
        pivot = list[low]; 
        while(low < high){        
            while(low < high && list[high] >= pivot){
                --high;
            }
            if(low!=high)list[low] = list[high];
            while(low < high && list[low] <= pivot){
                ++low;
            }
            if(low!=high)list[high] = list[low];
        }
        list[low] = pivot;
        if(low == k - 1){
            flag = false;
        }else{
            if(low < k - 1){
                low0 = ++low;
                high = high0;
            }else{
                high0 = --high;
                low = low0;
            }
        }
    }
    for(i = 0;i<k;i++){
        s1+=list[i];
    }
    for(i = k;i<n;i++){
        s2+=list[i];
    }
    return s2-s1;
}

int FindMidSelf(int list[],int n)//自己重新写一遍
{
    int high,low,high0,low0,k,i;
    int s1,s2;
    bool flag;
    int pivot;

    k = n/2 - 1;
    s1 = s2 = 0;
    high = high0 = n - 1;
    low = low0 = 0;
    flag = true;
    while(flag){
        pivot = list[low];
        while(low < high){
            while(low < high && list[high] > pivot){
                --high;
            }
            list[low] = list[high];
            while(low < high && list[low] < pivot){
                ++low;
            }
            list[high] = list[low];
        }
        list[low] = pivot;
        if(pivot = k){
            flag = false;
        }else{
            if(pivot < k){
                low0 = ++low;
                high = high0;
            }else{
                high0 = --high;
                low = low0;
            }
        }
    }
    for(i = 0;i<k+1;i++){
        s1 = s1 + list[i];
    }
    for(i = k+1;i<n;i++){
        s2 = s2 + list[i];
    }
    return s2 - s1;
}