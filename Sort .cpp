#include<iostream>
using namespace std;

void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


// Thuật toán này đơn giản nhất nhưng về chi phí tính toán khá cao vì với mỗi vị trí đều phải so sánh với tất cả các số còn lại
// hơn nữa mỗi khi so sánh nếu gặp được cặp nghịch thế (tức là sai thứ tự) thì swap ngay
void InterchangeSort(int* A, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (A[i] > A[j])
			{
				Swap(&A[i], &A[j]);
			}
		}
	}
}
