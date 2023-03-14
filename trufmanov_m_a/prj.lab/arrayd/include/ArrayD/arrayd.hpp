#ifndef DYNAMIC_ARRAY_HPP_2023
#define DYNAMIC_ARRAY_HPP_2023

#include <cstddef>

class ArrayD {
public:
    ArrayD() = default;
    ArrayD(const std::ptrdiff_t size);
    ArrayD(const ArrayD&) = default;
    ~ArrayD();

    ArrayD& operator=(const ArrayD& rhs);
    double& operator[] (const std::ptrdiff_t indx);
    const double& operator[](const std::ptrdiff_t indx) const;

    ptrdiff_t ssize() const noexcept;
    void resize(const std::ptrdiff_t new_size);

private:
    ptrdiff_t ssize_{ 0 };
    double* data_ = nullptr;
};
#endif