#pragma once

void PrintArray(int* a, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void InsertSort(int* a, size_t n)
{
	assert(a);

	for (size_t i = 0; i < n-1;++i)
	{
		int end = i;
		int tmp	= a[end+1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end+1]=a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = {2,5,4,9,3,6,8,7,1,0};
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	InsertSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));
}

void ShellSort(int* a, size_t n)
{
	assert(a);

	// 1.预排序
	// 2.
	int gap = n;

	while (gap > 1)
	{
		gap = gap/3+1;
		for(size_t i = 0; i < n-gap; ++i)
		{
			int end = i;
			int tmp = a[end+gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end+gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end+gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[] = {2,5,4,9,3,6,8,7,1,0};
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	ShellSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));
}

void SelectSort(int* a, size_t n)
{
	assert(a);

	size_t left = 0, right = n-1;
	while (left < right)
	{
		size_t min = left, max= left;
		for (size_t i = left; i <= right; ++i)
		{
			if(a[min] > a[i])
				min = i;

			if (a[max] < a[i])
				max = i;
		}

		swap(a[min], a[left]);
		// 修正
		if (max == left)
			max = min;

		swap(a[max], a[right]);
		++left;
		--right;
	}
}

void TestSelectSort()
{
	int a[] = {9,5,4,9,3,6,8,7,1,0};
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	SelectSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));
}

//template<class T, class Compare>
//void InsertSort(T* a, size_t n)
//
//template<class Iterator, class Compare>
//void InsertSort(Iterator first, Iterator last)

void AdjustDwon(int* a, size_t root, size_t n)
{
	size_t parent = root;
	size_t child = parent*2+1;
	while (child < n)
	{
		if (child+1 < n && a[child+1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = 2*parent+1;
		}
		else
		{
			break;
		}
	}
}

// N*lgN
void HeapSort(int* a, size_t n)
{
	assert(a);
	for (int i = (n-2)/2; i >=0; --i)
	{
		AdjustDwon(a, i, n);
	}

	size_t end = n-1;
	while                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    (end > 0)
	{
		swap(a[0], a[end]);
		AdjustDwon(a, 0, end);
	}
}

void BubbleSort(int* a, size_t n)
{
	assert(a);

	int end = n;
	while (end > 0)
	{
		bool exchange = false;
		for (int i = 1; i < end; ++i)
		{
			if (a[i-1] > a[i])
			{
				swap(a[i-1], a[i]);
				exchange = true;
			}
		}
		
		if (exchange == false)
		{
			break;
		}

		--end;
	}
}

void TestBubbleSort()
{
	int a[] = {1,2,3,4,5,7,6};
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	BubbleSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right-left)/2;
	// left mid right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else // left > mid  right
	{
		if (a[mid] > a[right])
			return mid;
		else if(a[left] < a[right]) // right > mid
			return left;
		else
			return right;
	}
}

// 左右指针法
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	swap(a[mid], a[right]);

	int key = a[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		while (begin < end && a[end] >= key)
		{
			--end;
		}

		if (begin < end)
			swap(a[begin], a[end]);
	}

	swap(a[begin], a[right]);
	return begin;
}

// 挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[right];
	while (left < right)
	{
		// 找大
		while (left < right && a[left] <= key)
		{
			++left;
		}

		// 找到比key大的数据放到右边的坑
		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[left] = a[right];
	}

	a[left] = key;
	return left;
}

int PartSort3(int* a, int left, int right)
{
	int prev = left-1;
	int cur = left;
	int key = a[right];
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			swap(a[prev], a[cur]);
		}

		++cur;
	}

	swap(a[++prev], a[right]);

	return prev;
}

// [left, right]
void QuickSort(int* a, int left, int right)
{
	assert(a);
	
	if (left >= right)
		return;

	if (right - left < 5)
	{
		InsertSort(a+left, right-left+1);
	}
	else
	{
		int div = PartSort1(a, left, right);
		QuickSort(a, left, div-1);
		QuickSort(a, div+1, right);
	}
}

#include <stack>
void QuickSortNonR(int* a, int left, int right)
{
	assert(a);
	stack<int> s;
	if (left < right)
	{
		s.push(right);
		s.push(left);
	}

	while (!s.empty())
	{
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();

		int div = PartSort1(a, begin, end);
		if (begin < div-1)
		{
			s.push(div-1);
			s.push(begin);
		}

		if (div+1 < end)
		{
			s.push(end);
			s.push(div+1);
		}
	}
}

void TestQuickSort()
{
	int a[] = {9,5,4,9,3,6,8,7,1,9};
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	QuickSortNonR(a, 0, sizeof(a)/sizeof(a[0])-1);
	//QuickSort(a, 0, sizeof(a)/sizeof(a[0])-1);
	PrintArray(a,sizeof(a)/sizeof(a[0]));
}

// 快排
// 快排时间复杂度

void Merge(int* a, int* tmp, int begin1,int end1, int begin2, int end2)
{
	size_t pos = begin1;
	size_t index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a+pos, tmp+pos, sizeof(int)*(end2-pos+1));
}

void _MergeSort(int* a,int* tmp, int left, int right)
{
	if (left >= right)
		return;

	int mid = left+(right-left)/2;
	// 0 0 1 1
	// [left mid] [mid+1, right]

	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid+1, right);
	
	Merge(a, tmp, left, mid, mid+1, right);
}

void MergeSort(int* a,size_t n)
{
	assert(a);

	int* tmp = new int[n];
	_MergeSort(a,tmp, 0, n-1);
	delete[] tmp;
}

void TestMergeSort()
{
	int a[] = {9,5,4,9,3,6,8,7,1,9};
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	MergeSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));
}