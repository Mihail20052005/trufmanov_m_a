#include <stdexcept>
#include <cstddef>
#include <vector>
#include <utility>
#include <tuple>

class MatrixS {
public:
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

public:
    explicit MatrixS(const SizeType& size = { 0, 0 });
    MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n);
    ~MatrixS();
    MatrixS(const MatrixS& other);
    MatrixS& operator=(const MatrixS& other);
    int& at(const SizeType& elem);
    const int& at(const SizeType& elem) const;
    int& at(const std::ptrdiff_t i, const std::ptrdiff_t j);
    const int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) const;
    void resize(const SizeType& new_size);
    void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);
    const SizeType& ssize() const noexcept;

    /**
     * \return количество строк в матрице (m)
     */
    std::ptrdiff_t nRows() const noexcept;

    /**
     * \return количество столбцов в матрице (n)
     */
    std::ptrdiff_t nCols() const noexcept;

private:
    std::ptrdiff_t m_{};
    std::ptrdiff_t n_{};
    std::vector<int> data_{};
};