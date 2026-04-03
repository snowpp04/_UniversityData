#include <iostream>
using namespace std;

int main() {
	cout << "입력할 정수의 개수는?";
	int n;
	cin >> n; // 정수의 개수 입력
	if (n <= 0) return 0;

	int* p = new int[n];
	if (!p) {
		cout << "메모리 할당 실패" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 정수 : ";
		cin >> p[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
	cout << "평균 = " << (double)sum / n << endl;
}