#include <arrayd/arrayd.hpp>

#include <stdexcept>
#include <cstring>


ArrayD::ArrayD(const std::ptrdiff_t size)
    : ssize_(size)
{
    caparcity = size * 2;
    data_ = new double[ssize_];
}

ArrayD::~ArrayD(){
    delete data_;
}


void ArrayD::insert(std::ptrdiff_t index, const double value){
    if(!notError){
        throw std::invalid_argument("index out of range");
    }else{
        resize(ssize_ + 1);
        ssize_++;

        for (int i = ssize_; i > index; i--) {
            data_[i] = data_[i - 1];
        }
        data_[index] = value;
    }
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
    caparcity = new_size * 2;
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

bool notError(std::ptrdiff_t index, std::ptrdiff_t ssize) {
    return(index < 0 || index >= ssize ? false : true);
}