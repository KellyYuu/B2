#include "Header.h"
int main()
{
	CL m;
	CL m1, m2;
	init(m);
	/*insert(m, 0, 20);
	insert(m, m.n, 50);
	insert(m, m.n / 2, 30);
	createCL(m);
	cout << endl;
	output(m);
	cout << endl;
	remove(m, m.n / 2);
	output(m);
	cout << endl;
	sort(m);
	output(m);*/
	createCL(m);
	cout << endl;
	//exchangeSort(m);
	//bubbleSort(m);
	//output(m);
	/*if (increment(m))
		cout << "Mang tang dan.";
	else cout << "Mang khong tang dan.";
	cout << endl;*/
	if (incrementFlag(m))
		cout << "Mang tang dan.";
	else cout << "Mang khong tang dan.";
	cout << endl;
	/*split(m, m1, m2);
	output(m1);
	cout << endl;
	output(m2);
	cout << endl;*/
	splitOE(m, m1, m2);
	output(m1);
	cout << endl;
	output(m2);
	cout << endl;
	/*join(m, m1, m2);
	output(m);
	cout << endl;*/
	joinOEI(m, m1, m2);
	output(m);
	cout << endl;
	return 0;
}