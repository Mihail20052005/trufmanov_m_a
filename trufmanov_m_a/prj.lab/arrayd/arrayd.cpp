#include <arrayd/arrayd.hpp>

#include <stdexcept>
#include <cstring>


ArrayD::ArrayD(const std::ptrdiff_t size)
    : ssize_(size)
{
    data_ = new double[ssize_];
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    if (new_size < 0) {
        throw std::invalid_argument("new_size must be positive");
    }
    if (new_size == 0) {
        data_ = nullptr;
        ssize_ = 0;
    }
    else {
        auto* new_data = new double[new_size] {};
        if (data_ != nullptr) {
            auto copy_size = std::min(ssize_, new_size) * sizeof(double);
            std::memcpy(new_data, data_, copy_size);
            delete[] data_;
        }
        data_ = new_data;
        ssize_ = new_size;
    }
}

double& ArrayD::operator[](const std::ptrdiff_t indx) {
    if (indx < 0 || indx >= ssize_) {
        throw std::invalid_argument("index must be in size range");
    }
    return data_[indx];
}

const double& ArrayD::operator[](const std::ptrdiff_t indx) const {
    if (indx < 0 || indx >= ssize_) {
        throw std::invalid_argument("index must be in size range");
    }
    return data_[indx];
}

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
    data_ = rhs.data_;
    ssize_ = rhs.ssize_;
    return *this;
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return ssize_;
}