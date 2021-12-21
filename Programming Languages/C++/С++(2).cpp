#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

void print(int* x, int n) {                  //����� ������� �� �����
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
}

void quicksort(int* x, int L, int r, int n) { //������� ����������
	//L = 0; r = n - 1;                     //���������� ����� � ������ ������� �������
	int m = x[(L + r) / 2];               //�������� �� ������� ������� �������� �������
	int i = L, j = r;
	while (i <= j) {                      //� ����� ������ ������� �������� ���, ��� ����� �������� ��-�� ����� ������� ���,������ - �������
		while (x[i] < m) i++;
		while (x[j] > m) j--;
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	if (j - L > 0) quicksort(x, L, j, n);  //���� ����� ��������� �������� ������ 1 ��������, �� �������� ������� ��� ������� �� L �� j
	if (r - i > 0) quicksort(x, i, r, n); //���� ������ ��������� �������� ������ 1 ��������, �� �������� ������� ��� ������� �� i �� r 
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, L, r;                         //������ ����������� �������
	int s;
	cout << "�������� ����������� �������, �������: \n1 - 500, 2 - 1000, 3 - 5000, 4 - 10000, 5 - 15000\n";
	cin >> s;
	switch (s) {
	case 1: {n = 500; break; }
	case 2: {n = 1000; break; }
	case 3: {n = 5000; break; }
	case 4: {n = 10000; break; }
	case 5: {n = 15000; break; }
	default: cout << "����������� �������� ������";
	}
	int* x = new int[n];
	for (int i = 0; i < n; i++) x[i] = rand() % INT_MAX;         //������� ������
	L = 0; r = n - 1;                     //���������� ����� � ������ ������� �������
	unsigned int start_time = clock(); // ��������� �����
	quicksort(x, L, r, n);
	unsigned int end_time = clock(); // �������� �����
	unsigned int search_time = end_time - start_time; // ������� �����
	print(x, n);                  //������� �� �����
	cout << "\n����� ���������� ���������� " << search_time << " �� = " << search_time * 1.0 / 1000 << " ���\n";
	system("pause");
}