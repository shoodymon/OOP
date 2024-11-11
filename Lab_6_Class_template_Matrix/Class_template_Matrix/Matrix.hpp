#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
	std::vector<std::vector<T>> m_data;
	size_t m_rows;
	size_t m_columns;

public:
	Matrix(size_t r, size_t c) : m_rows(r), m_columns(c) {
		m_data.resize(m_rows, std::vector<T>(m_columns));
	}
	~Matrix() = default;

	std::vector<T>& operator[](size_t i) {
		return m_data[i];
	}

	size_t getRows() { return m_rows; }
	size_t getColumns() { return m_columns; }

	Matrix<T> transpose() const;
	
	Matrix<T> operator+(const Matrix<T>& other) const;
	Matrix<T> operator-(const Matrix<T>& other) const;
	Matrix<T> operator*(const Matrix<T>& other) const;

	void print() const;
};


template <typename T>
Matrix<T> Matrix<T>::transpose() const {
	Matrix result(m_columns, m_rows);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_columns; j++) {
			result.m_data[j][i] = m_data[i][j];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
	Matrix<T> result(m_rows, m_columns);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_columns; j++) {
			result.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
	Matrix<T> result(m_rows, m_columns);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_columns; j++) {
			result.m_data[i][j] = m_data[i][j] - other.m_data[i][j];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
	if (m_columns != other.m_rows) {
		throw std::invalid_argument("Количество столбцов первой матрицы должно быть равно количеству строк второй матрицы для умножения.");
	}
	Matrix<T> result(m_rows, other.m_columns);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < other.m_columns; j++) {
			result.m_data[i][j] = T();
			for (size_t k = 0; k < m_columns; k++) {
				result.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
			}
		}
	}
	return result;
}

template <typename T>
void Matrix<T>::print() const {
	for (size_t i = 0; i < m_rows; ++i) {
		for (size_t j = 0; j < m_columns; ++j) {
			std::cout << m_data[i][j] << ' ';
		}
		std::cout << '\n';
	}
}