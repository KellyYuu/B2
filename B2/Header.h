#include <iostream>
using namespace std;
const int MAX = 100;
typedef struct contiguousList
{
	int n;
	int list[MAX];
}CL;
void world();
void init(CL&);
bool isEmpty(CL);
bool isFull(CL);
int insert(CL&, int, int);
void createCL(CL&);
void output(CL);
int remove(CL&, int);
int max(CL);
void sort(CL&);
int& size(CL&);
void exchangeSort(CL&);
void bubbleSort(CL&);
bool increment(CL);
bool incrementFlag(CL);
void split(CL, CL&, CL&);
void splitOE(CL, CL&, CL&);
void join(CL& ,CL, CL);
void joinOEI(CL&, CL, CL);

