#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(){ radius = 1; }
	~Circle() {};
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
class CircleManager {
	Circle* pArray = NULL;	// 동적할당될 기억공간 가리키는 포인터
	int size = 0;			// 동적할당될 배열의 크기
	void input();			// 원의 갯수만큼 반지름 입력받아서 각 원소객체의 radius 
	void decide();			
public:
	CircleManager();
	~CircleManager();
	void run();
};
CircleManager::CircleManager() {
	cout << "생성하고자 하는 원의 갯수 : ";
	cin >> size; 
	if (size <= 0) return;
	pArray = new Circle[size];
}
CircleManager::~CircleManager() {
	if (pArray != NULL) delete[] pArray;
}
void CircleManager::input() {
	int r;
	for (int i = 0; i < size; i++) {
		cout << "원" << i + 1 << ": ";
		cin >> r;
		pArray[i].setRadius(r);
	}
}
void CircleManager::decide() {
	double area;
	int count = 0;
	for (int i = 0; i < size; i++) {
		area = pArray[i].getArea();
		cout << area << "  ";
		if (area >= 100 && area <= 200) count++;
	}
	cout << endl << "면적이 100~200인 원의 개수 : " << count << endl;
}

void CircleManager::run() {
	input();
	decide();
}


int main() {
	CircleManager* pMan = new CircleManager();
	pMan->run();
	delete pMan;
}