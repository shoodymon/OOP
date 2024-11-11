#pragma once
#include "Matrix.hpp"

template <typename T>
T findMin(Matrix<T>& matrix) {
	T minElement = matrix[0][0];
	for (size_t i = 0; i < matrix.getRows(); i++) {
		for (size_t j = 0; j < matrix.getColumns(); j++) {
			if (matrix[i][j] < minElement) {
				minElement = matrix[i][j];
			}
		}
	}
	return minElement;
}

//template int findMin(const Matrix<int>& matrix);
//template double findMin(const Matrix<double>& matrix);