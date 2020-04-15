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

// Thuật toán này phức tạp hơn thuật toán InterchangeSort một chút vì nó cải tiến ở chỗ với mỗi vòng lặp khi tìm được phần tử lớn (nhỏ) nhất
// thì nó mới Swap() dẫn đến số lượng Swap() giảm
void SelectionSort(int* A, int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = A[i], pos = i;// cài min=A[i] và vị trí swap pos=i
		for (int j = i + 1; j < length; j++)
		{
			if (min > A[j])// nếu tìm được phần tử nhỏ hơn thì cập nhật lại min và vị trí của phần tử cần swap()
			{
				min = A[j];
				pos = j;
			}
		}
		Swap(&A[i], &A[pos]);// sau khi tìm được phần tử nhỏ nhất (trong phần còn lại) thì swap()
	}
}

// Thuật toán về ý tưởng giống như xếp bài khi nhận được từng là bài một, tìm vị trí chèn vào thích hợp
// Thuật toán này thích hợp cho các trường hợp dữ liệu chưa đầy đủ đang truyền tới.
void InsertionSort(int* A, int length)
{
	for (int i = 1; i < length; i++)// xét từ phần tử vị trí 1 (xem phần tử 0 như là dãy đã sắp xếp)
	{
		int pos = i;
		for (int j = 0; j < i; j++)// duyệt trong mảng từ 0 đến vị trí đang xét để tìm vị trí chèn
		{
			if ((j == 0 && A[i] < A[j]))// nếu nhỏ hơn phần tử đầu tiên thì chèn vào vị trí A[0]
			{
				pos = 0;
				break;
			}
			if (A[i]<A[j] && A[i]>A[j - 1])// nếu tìm được vị trí mà nó nằm giữa thì cũng chèn vào vị trí đó
			{
				pos = j;
				break;
			}
		}
		if (pos != i)
		{
			int tmp = A[i];
			for (int x = i; x >= pos; x--)// thực hiện dịch chuyển đoạn từ i đến pos sang phải 1 đơn vị để cho A[i] vào vị trí pos
			{
				A[x] = A[x - 1];
			}
			A[pos] = tmp;
		}
	}
}