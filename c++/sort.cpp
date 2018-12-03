#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 1E6;
int arr[MAXN];
int cop[MAXN];
int tmpCop[MAXN];

void InsertSortW(int* arr, int len)//直接插入排序带监视哨
{
	int i, j;
	for (i = 2; i < len; i++)
	{
		if (arr[i] >= arr[i - 1])
			continue;
		arr[0] = arr[i];
		j = i - 1;
		while (arr[j] > arr[0])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = arr[0];
		/*
		do
		{
		arr[j + 1] = arr[j];
		j--;
		} while (arr[j] > arr[0]);
		arr[j + 1] = arr[0];*/
	}
}

void InsertSort(int* arr, int len)//直接插入排序不带监视哨
{
	int i, j, tmp;
	for (i = 2; i < len; i++)
	{
		if (arr[i] >= arr[i - 1])
			continue;
		tmp = arr[i];
		j = i - 1;
		while (j >= 1 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}

void ShellInsertW(int* arr, int len, int h)
{
	int i, j;
	for (i = 1 + h; i < len; i++)
	{
		if (arr[i] >= arr[i - h])
			continue;
		arr[0] = arr[i];
		j = i - h;
		while (arr[j] > arr[0])
		{
			arr[j + h] = arr[j];
			j -= h;
		}
		arr[j + h] = arr[0];
	}
}

void ShellSortW(int* arr, int len)
{
	int h[100] = { 0 };
	h[1] = floor(len / 2);
	int t = log(len) / log(2);
	h[t] = 1;
	for (int i = 2; i < t; i++)
	{
		h[i] = floor(h[i - 1] / 2);
	}

	int j = 1;
	while (h[j])
	{
		ShellInsertW(arr, len, arr[j]);
		j++;
	}
}


void ShellInsert(int* arr, int len, int h)
{
	int i, j, tmp;
	for (i = 1 + h; i < len; i++)
	{
		if (arr[i] >= arr[i - h])
			continue;
		tmp = arr[i];
		j = i - h;
		while (j >= 1 && arr[j] > tmp)
		{
			arr[j + h] = arr[j];
			j -= h;
		}
		arr[j + h] = tmp;
	}
}

void ShellSort(int* arr, int len)
{
	int h[100] = { 0 };
	h[1] = floor(len / 2);
	int t = log(len) / log(2);
	h[t] = 1;
	for (int i = 2; i < t; i++)
	{
		h[i] = floor(h[i - 1] / 2);
	}

	int j = 1;
	while (h[j])
	{
		ShellInsert(arr, len, h[j]);
		j++;
	}
}

void BubbleSort(int* arr, int len) //下沉
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		int flag = 0;
		for (j = 2; j < len - i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				flag = 1;
				arr[0] = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = arr[0];
			}
		}
		if (!flag)
			break;
	}
}

void BubbleSortR(int* arr, int len) //上升
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		int flag = 0;
		for (j = len - 1; j > i + 1; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				flag = 1;
				arr[0] = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = arr[0];
			}
		}
		if (!flag)
			break;
	}
}

int Partition(int* arr, int p, int q)
{
	int i, j;
	i = p;
	j = q;
	arr[0] = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] > arr[0])
			j--;
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (i < j && arr[i] < arr[0])
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
		arr[i] = arr[0];
	}
	return i;
}

void QuickSort(int* arr, int s, int t)
{
	if (s >= t)
		return;
	int i = Partition(arr, s, t);
	QuickSort(arr, s, i - 1);
	QuickSort(arr, i + 1, t);
}

void SelectSort(int* arr, int len)
{
	int i, j, k;
	for (i = 1; i < len - 1; i++)
	{
		k = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[k])
				k = j;
		}
		if (k != i)
		{
			arr[0] = arr[i];
			arr[i] = arr[k];
			arr[k] = arr[0];
		}
	}
}

void Sift(int* arr, int p, int q)
{
	int i, j;
	arr[0] = arr[p];
	i = p;
	j = 2 * i;
	while (j <= q)
	{
		if (j < q && arr[j] < arr[j + 1])
			j++;
		if (arr[0] > arr[j])
			break;
		arr[i] = arr[j];
		i = j;
		j = 2 * i;
	}
	arr[i] = arr[0];
}

void HeapSort(int* arr, int len)
{
	for (int i = (len - 1) / 2; i >= 1; i--)
		Sift(arr, i, len - 1);
	for (int i = len - 1; i >= 2; i--)
	{
		arr[0] = arr[1];
		arr[1] = arr[i];
		arr[i] = arr[0];
		Sift(arr, 1, i - 1);
	}
}

void merge(int* arr, int* ans, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
            ans[k++] = arr[i++];
        else
            ans[k++] = arr[j++];
        while(i <= mid)
            ans[k++] = arr[i++];
        while(j <= high)
            ans[k++] = arr[j++];
    }
}

void mergePass(int* arr, int* ans, int n, int len)
{
    int i = 1, j;
    while(i + 2 * len - 1 <= n)
    {
        merge(arr, ans, i, i+len-1, i+2*len-1);
        i = i + 2 * len;
    }
    if(i + len - 1 < n)
        merge(arr, ans, i, i + len - 1, n);
    else
    {
        for(j = i; j <= n; j++)
            ans[j] = arr[j];
    }
}

void MergeSort(int* arr, int* ans, int n)
{
    int len = 1;
    while(len < n)
    {
        mergePass(arr, ans, n, len);
        len *= 2;
        mergePass(ans, arr, n, len);
        len *= 2;
    }
}

void check(int* arr, int n)
{   
	int i, error = 0;
	cout << "数组排序后输出的内容:" << endl;
	for (i = 1; i < n; i++)
	{
			cout << arr[i] << " ";
			if (i >= 2 && arr[i] < arr[i - 1])
				error = 1;
	}
	cout << endl;
	if (error)  
		cout << "Error!\n";
	else
		cout << "Correct! " << endl;
}

void makeArr(int len)
{
	int i = 1;
	arr[0] = 0;
	cout << "你生成的乱序数组内容为:" << endl;
	while (i <= len)
	{
		arr[i] = 2*rand() - rand() + rand();
		cout << arr[i] << " ";
			i++;
	}
	cout << endl;
}

void Copy(int* from, int* to, int len)
{
	for (int i = 0; i < len; i++)
		to[i] = from[i];
}
int main()
{
	int n, num, len;

	cout << "请输入你要生成的乱序数组的长度(小于1000000个)" << endl;
	cin >> num;
	makeArr(num);
	len = num + 1;

	do
	{
		cout << endl;
		cout << "请选择功能" << endl;
		cout << "1.直接插入排序带监视哨" << endl;
		cout << "2.直接插入排序不带监视哨" << endl;
		cout << "3.希尔排序" << endl;
		cout << "4.冒泡排序上升法" << endl;
		cout << "5.冒泡排序下沉法" << endl;
		cout << "6.快速排序" << endl;
		cout << "7.直接选择排序" << endl;
		cout << "8.堆排序" << endl;
		cout << "9.归并排序" << endl;
		cout << "0.退出" << endl;
		cin >> n;
		if (n < 0 || n > 9) cout << "输入不合法，请重新输入" << endl;
		switch (n)
		{
		case 0: return 0;
		case 1:
			Copy(arr, cop, len);
			InsertSortW(cop, len);
			check(cop, len);
			break;
		case 2:
			Copy(arr, cop, len);
			InsertSort(cop, len);
			check(cop, len);
			break;
		case 3:
			Copy(arr, cop, len);
			ShellSort(cop, len);
			check(cop, len);
			break;
		case 4:
			Copy(arr, cop, len);
			BubbleSortR(cop, len);
			check(cop, len);
			break;
		case 5:
			Copy(arr, cop, len);
			BubbleSort(cop, len);
			check(cop, len);
			break;
		case 6:
			Copy(arr, cop, len);
			QuickSort(cop, 1, len - 1);
			check(cop, len);
			break;
		case 7:
			Copy(arr, cop, len);
			SelectSort(cop, len);
			check(cop, len);
			break;
		case 8:
			Copy(arr, cop, len);
			HeapSort(cop, len);
			check(cop, len);
			break;
		case 9:
			Copy(arr, cop, len);
            MergeSort(cop, tmpCop,len - 1);
            check(cop, len);
			break;
		}
	} while (1);
	return 0;
}
