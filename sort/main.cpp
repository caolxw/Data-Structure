#include <stdio.h>
#include <stdlib.h>

//打印数组
void PrintArr(int a[], int n)
{
    for(int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
//直接插入排序
void InserSort(int a[], int n){
    for(int i = 1; i < n; i ++){
        int tmp = a[i];
        int j = i - 1;
        for( ;j >= 0 && tmp < a[j]; j --)
                a[j + 1] = a[j];
        a[j + 1] = tmp;
//        PrintArr(a, 8);
    }

}

//折半插入排序
void BInserSort(int a[], int n)
{
    for(int i = 1; i < n; i++){
        int tmp = a[i];
        int s = 0;
        int t = i - 1;
        while(s <= t){
            int m = (s + t) / 2;
            if(tmp < a[m]) t = m - 1;
            else s = m + 1;
        }
        for(int j = i; j > t + 1; j --){
            a[j] = a[j - 1];
        }
        a[t + 1] = tmp;
    }
}

//对数组进行一趟絮儿排序
void ShellInsert(int a[], int n, int dk)
{
    //dk为增量
    for(int j = dk; j < n; j ++){
        if(a[j] < a[j - dk]){
            int tmp = a[j];
            int k = j - dk;
            for(; k >= 0 && a[k] > tmp; k -= dk)
                a[k + dk] = a[k];
            a[k + dk] = tmp;
        }
    }
}

//希尔排序
void ShellSort(int a[], int n, int dlta[], int t)
{
    //a[]为待排序数组，n为数组长度，dlta[]为增量序列，t为增量序列的长度
    for(int i = 0; i < t; i ++){
        //进行一趟增量为dlta[i]的排序
        ShellInsert(a, n, dlta[i]);
        //PrintArr(a, 8);
    }
}

//冒泡排序
void BubbleSort(int a[], int n)
{
    for(int i = 0; i < n; i ++){
        for(int j = n - 1; j >= i; j--){
            if(a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

//划分数组
int Partition(int a[], int low, int high)
{
    int tmp = a[low];
    while(low < high){
        while(low < high && a[high] >= tmp)
            high --;
        a[low] = a[high];
        while(low < high && a[low] < tmp)
            low ++;
        a[high] = a[low];
    }
    a[low] = tmp;
    return low;
}
//快速排序
 void QuickSort(int a[], int low, int high)
{
    if(low < high){
        int m = Partition(a, low, high);
        QuickSort(a, low, m - 1);
        QuickSort(a, m + 1, high);
    }
}

//调整数组，使其成为大顶堆
void HeapAjust(int a[], int s, int m)
{
    int rc = a[s];
    for(int j = 2 * s + 1; j < m; j = j * 2 + 1){
        if(j + 1 < m && a[j] < a[j + 1]) j ++;
        if(rc < a[j]){
            a[s] = a[j];
            s = j;
        }
    }
    a[s] = rc;
}
//堆排序
void HeadSort(int a[], int n)
{
    int i;
    for(i = (n-1) / 2; i >= 0; i --){
        HeapAjust(a, i, n);
    }
    for(i = n-1; i > 0; i --){
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        HeapAjust(a, 0, i-1);
    }
}

//数组合并
void Merge(int a[], int a2[], int i, int m, int s)
{
    int j,k;
    for(j = m + 1, k = i; i <= m && j <= s; k++)
    {
        if(a[i] < a[j]) a2[k] = a[i ++];
        else a2[k] = a[j ++];
    }

    while(i <= m){
        a2[k ++] = a[i ++];
    }
    while(j <= s) a2[k ++] = a[j ++];
}
//归并排序
void MergeSort(int a[], int a2[], int s, int t)
{
    if(s == t) a2[s] = a[s];
    else{
        int a3[8];
        int m = (s + t) / 2;
        MergeSort(a, a3, s, m);
        MergeSort(a, a3, m + 1, t);
        Merge(a3, a2, s, m, t);
    }
}

int main(){
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
    //InserSort(a, 8);
    //PrintArr(a, 8);

    //BInserSort(a, 8);
    //PrintArr(a, 8);

    /*
    int dlta[] = {3, 2, 1};
    ShellSort(a, 8, dlta, 3);
    PrintArr(a, 8);
    */

    //BubbleSort(a, 8);
    //PrintArr(a, 8);

    //QuickSort(a, 0, 7);
    //PrintArr(a, 8);

    HeadSort(a, 8);
    PrintArr(a, 8);

    //MergeSort(a, a, 0, 7);
    //PrintArr(a, 8);
}
