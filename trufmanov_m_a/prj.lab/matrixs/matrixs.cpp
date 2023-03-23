#include <matrixs/matrixs.hpp>
#include <cstddef>
#include <stdexcept>
#include "iosfwd"
#include "utility"

MatrixS::MatrixS(int new_rows, int new_cols):row(new_rows),
col(new_cols){
	data = new int[row * col];
	for(int i = 0; i < row * col; i++){
		data[i] = 0;
	}
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
	delete[] data;
	row = other.rows();
	col = other.cols();
	data = new int[row * col];
	for (int i = 0; i < row * col; i++) {
		data[i] = other.at(i / col, i % col);
	}
}

const int MatrixS::cols() const{
	return col;
}

const int MatrixS::rows() const{
	return row;
}