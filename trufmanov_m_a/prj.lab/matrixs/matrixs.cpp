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
const int& MatrixS::at(int index_row, int index_col) const{
	if (!outOfRangeCheck) {
		throw std::invalid_argument("Index out of range");
	}
	else {
		return data[col * index_col + index_row];
	}
}

int& MatrixS::at(int index_row, int index_col) {
	if (!outOfRangeCheck) {
		throw std::invalid_argument("Index out of range");
	}
	else {
		return data[col * index_col + index_row];
	}
}

const int MatrixS::cols() const{
	return col;
}

const int MatrixS::rows() const{
	return row;
}

bool outOfRangeCheck(int index_row, int index_col, int row, int col) {
	if (index_row * index_col <= 0 || index_row > row 
		|| index_col > col || index_col < 0) {
		return false;
	
	}
	return true;


}