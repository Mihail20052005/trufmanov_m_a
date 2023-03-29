#include <cstddef>
#include "iosfwd"

class MatrixS {
private:
	MatrixS();
	MatrixS(int rows, int cols);
	MatrixS(const MatrixS& rhs);
	~MatrixS() = default;


	MatrixS& operator=(const MatrixS& rhs);
	const int& at(int index_row, int index_col) const;
	int& at(int index_row, int index_col);

	const int cols() const;
	const int rows() const;

	void resize(int rows, int cols);

private:
	int* data = nullptr;
	int col = 0;
	int row = 0;
};
