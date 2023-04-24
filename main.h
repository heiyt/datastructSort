#ifndef __MAIN_H
#define __MAIN_H

#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//都为从小到大排序

//辅助函数
void showList(int list[],int n);
void swap(int *a,int *b);

//排序函数
void InsertSort(int list[],int n);          //直接插入排序
void BubbleSort(int list[],int n);          //冒泡排序
void DoubleBubbleSort(int list[],int n);    //双冒泡排序
void JishuAheadOushu(int list[],int n);     //奇数在前偶数在后
void SortFlagOfHeLan(int list[]);          //荷兰国旗排序

//快速排序
int Partition(int list[],int low,int high);
int Partition2(int list[],int low,int high);
int PartitionRandom(int list[],int low,int high);
void FastSort(int list[],int low,int high);

#endif
