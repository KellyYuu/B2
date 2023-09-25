#include "Header.h"
//Khoi tao
void init(CL& m)
{
	m.n = 0;
}
//Kiem tra mang rong
bool isEmpty(CL m)
{
	return m.n == 0;//return true or false
}
//Kiem tra mang day
bool isFull(CL m)
{
	return m.n > MAX;//return true or false
}
//Them phan tu vao mang
int insert(CL& m,int idx, int k)
{
	if (isFull(m) || idx<0 || idx>m.n)
		throw"Error";//Xuat error dung chuong trinh
	for (int i = m.n; i > idx; i--)
		m.list[i] = m.list[i - 1];//Chep phan tu qua phai
	m.list[idx] = k;//Gan gia tri vao vi tri idx
	m.n += 1;
	return 1;
}
//Dem so luong cac phan tu da them
void createCL(CL& m)
{
	int x, i = 0, count = 0;
	cout << "Enter 0 when you want to exit.\n";
	do 
	{
		cout << "Enter a number: ";
		cin >> x;
		if (x == 0)
			break;
		count += insert(m, i++, x);
	} while (true);
	cout << "It etem insert is " << count;
}
//Xuat mang
void output(CL m)
{
	for(int i = 0; i < m.n; i++)
	{
		cout << m.list[i] << "\t";
	}
}
//Xoa 1 phan tu cua mang
int remove(CL& m, int idx)
{
	if (isEmpty(m) || idx<0 || idx>m.n)
		throw"Error";//Xuat error dung chuong trinh
	for (int i = idx; i <m.n-1; i++)
		m.list[i] = m.list[i + 1];//Chep chong phan tu qua trai
	m.n -= 1;
	return 1;
}
//Tim vi tri phan tu lon nhat
int max(CL m)
{
	int mx = 0;
	for (int i = 1; i < m.n-1; i++)
		if (m.list[mx] < m.list[i])
			mx = i;
	return mx;  
}
//Thuat toan sap xep
void sort(CL& m)
{
	for (int j = 0; j < m.n-1; j++)
	{
		int mx = j;
		for (int i = j+1; i < m.n; i++)
			if (m.list[mx] < m.list[i])
				mx = i;
		int tem = m.list[mx];
		m.list[mx] = m.list[j];
		m.list[j] = tem;
	}
}
//Giam dan tuong tu chi doi dau
//Ham tra ve hoac gan do dai mang(ham tham bien)
int& size(CL& m)
{
	return m.n;
}
//exchangeSort
void exchangeSort(CL& m)
{
	for (int i = 0; i < size(m)-1; i++)
	{
		for (int j = i + 1; j < size(m); j++)
		{
			if (m.list[j] > m.list[i])
				swap(m.list[j], m.list[i]);
		}
	}
}
//bubbleSort
void bubbleSort(CL& m)
{
	for (int i = 0; i < size(m); i++)
	{
		for (int j = size(m); j > i; j--)
		{
			if (m.list[j] > m.list[j-1])
				swap(m.list[j], m.list[j-1]);
		}
	}
}
//Kiem tra mang tang dan
bool increment(CL m)
{
	int count = 0;
	for (int i = 0; i < size(m) - 1; i++)
	{
		if (m.list[i] < m.list[i + 1])
			count++;//Trong Python khong co ++ nen thay bang +=1.
	}
	return count == size(m) - 1;
}
bool incrementFlag(CL m)
{
	bool flag = true;
	for (int i = 0; i < size(m) - 1; i++)
		if (m.list[i] > m.list[i + 1])
		{
			flag = false;
			break;
		}
	return flag;
}
//split and join
void split(CL m, CL& m1, CL& m2)
{
	//Ham gia tri tham chieu
	size(m1) = 0;
	size(m2) = 0;
	for (int i = 0; i < size(m) / 2; i++)
	{
		m1.list[size(m1)++] = m.list[i];
	}
	for (int i = size(m) / 2; i < size(m); i++)
	{
		m2.list[size(m2)++] = m.list[i];
	}
}
void splitOE(CL m, CL& mOdd, CL& mEven)
{
	init(mOdd);
	init(mEven);
	for (int i = 0; i < size(m); i++)
	{
		if (m.list[i] % 2 != 0)
			//insert(mOdd, 0, m.list[i]);
			mOdd.list[size(mOdd)++] = m.list[i];
		else 
			mEven.list[size(mEven)++] = m.list[i];
			//insert(mEven, 0, m.list[i]);
	}
}
void join(CL& m, CL m1, CL m2)
{
	init(m);
	for (int i = 0; i < size(m1); i++)
	{
		insert(m, size(m), m1.list[i]);
	}
	for (int i = 0; i < size(m2); i++)
	{
		insert(m, size(m), m2.list[i]);
	}
}
void joinOEI(CL& m, CL m1, CL m2)
{
	init(m);
	int i = 0, j = 0;
	while (i < size(m1) && j < size(m2))
	{
		if (size(m) % 2 == 0)
			m.list[size(m)++] = m1.list[i++];
		else m.list[size(m)++] = m2.list[j++];
	}
	while (i < size(m1))
		m.list[size(m)++] = m1.list[i++];
	while (j < size(m2))
		m.list[size(m)++] = m2.list[j++];
}