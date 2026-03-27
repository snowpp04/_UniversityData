#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; cout << "생성자 실행" << endl; }
	Circle(int r) { radius = r; }
	double getArea();
	~Circle() { cout << "소멸자 실행" << endl; }
	void setRadius(int r) { radius = r; }

};
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle c[3];

	c[0].setRadius(10);
	c[1].setRadius(20);
	c[2].setRadius(30);

	for (int i = 0; i < 3; i++)
		cout << "c의 원소[" << i << "]의 면적 : " << c[i].getArea() << endl;

	Circle* p;
	p = c;

	for (int i = 0; i < 3; i++) {
		cout << "c의 원소[" << i << "]의 면적 : " << p->getArea() << endl;
		p++;
	}

}