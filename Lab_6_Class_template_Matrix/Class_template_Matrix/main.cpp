#include "Matrix.hpp"
#include "template_find.hpp"

int main() {
	system("chcp1251");
	system("cls");
	setlocale(0, "");

	Matrix<int> m1(2, 3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;

	std::cout << "Матрица m1:\n";
	m1.print();

	Matrix<int> m2(2, 3);
	m2[0][0] = 1; m2[0][1] = 1; m2[0][2] = 1;
	m2[1][0] = 1; m2[1][1] = 1; m2[1][2] = 1;

	std::cout << "\nМатрица m2:\n";
	m2.print();

	std::cout << "\nm1 + m2:\n";
	auto m3 = m1 + m2;
	m3.print();

	std::cout << "\nm1 - m2:\n";
	auto m4 = m1 - m2;
	m4.print();

	Matrix<int> m5(3, 2);  
	m5[0][0] = 1; m5[0][1] = 2;
	m5[1][0] = 3; m5[1][1] = 4;
	m5[2][0] = 5; m5[2][1] = 6;

	std::cout << "\nМатрица m5 для умножения:\n";
	m5.print();

	std::cout << "\nm1 * m5:\n";
	auto m6 = m1 * m5;
	m6.print();

	std::cout << "\nТранспонированная m1:\n";
	auto m7 = m1.transpose();
	m7.print();

	std::cout << "\nМинимальный элемент в m1: " << findMin(m1) << "\n";

	Matrix<double> d1(2, 2);
	d1[0][0] = 1.5; d1[0][1] = 2.7;
	d1[1][0] = 3.2; d1[1][1] = 4.9;

	std::cout << "\nМатрица double d1:\n";
	d1.print();

	return 0;
}