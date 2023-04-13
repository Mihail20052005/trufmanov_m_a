#include <arrayd/arrayd.hpp>

#include <stdexcept>
#include <cstring>


ArrayD::ArrayD(const std::ptrdiff_t size)
    : ssize_(size)
{
    if(size < 0){
        throw std::invalid_argument("size must be more 0");
    }else{
        ArrayD::resize(size);
    }
}

ArrayD::ArrayD(const ArrayD& lhs){
    ssize_ = lhs.ssize_;
    caparcity = lhs.caparcity;

    if(caparcity > 0){
        data_ = new double[caparcity];
        for(std::ptrdiff_t i = 0; i < ssize_; ++i){
            data_[i] = lhs.data_[i];
        }
    
    }else{
        data_ = nullptr;
    }
}

ArrayD::~ArrayD(){
    delete data_;
}


void ArrayD::insert(const std::ptrdiff_t index, const double value){
    if(index < 0 || index >= ssize_){
        throw std::invalid_argument("index out of range");
    }

    if(ssize_ == caparcity){
        resize(ssize_ + 1);
    }

    if(ssize_ == 0){
        data_[0] = value;
    }
    else {

        for (std::ptrdiff_t i = ssize_; i > index; i--) {
            data_[i] = data_[i - 1];
        }

        data_[index] = value;
    }
    ssize_ += 1;
}

void ArrayD::resize(const std::ptrdiff_t new_size){
    if(new_size <= 0){
        throw std::invalid_argument("index out of range");
    }
    if(new_size <= ssize_){
        ssize_ = new_size;
        return;
    }

    if(new_size > ssize_){
        double* new_data = new double[new_size]();
        for(size_t i = 0; i < ssize_; ++i){
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        ssize_ = new_size;
        caparcity = new_size * 2;
        return;
    
    }

    if(new_size <= caparcity){
        ssize_ = new_size;
    
    }



}

void ArrayD::remove(const ptrdiff_t index) {
    if (index < 0 || index >= ssize_){
        throw std::invalid_argument("index must be in size range");
    }

    if(ssize_ == caparcity){
        resize(ssize_ + 1);
    
    }
    for (ptrdiff_t i = index; i < ssize_; i++) {
        data_[i] = data_[i + 1];
    }
    ssize_--;

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

ArrayD& ArrayD::operator=(const ArrayD& other) {
    if (this != &other) {
        delete[] data_;
        data_ = nullptr;
        ssize_ = 0;
        caparcity = 0;

        if (other.caparcity > 0) {
            data_ = new double[other.caparcity];
            caparcity = other.caparcity;
            for (std::ptrdiff_t i = 0; i < other.ssize_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        ssize_ = other.ssize_;
    }
    return *this;
}


std::ptrdiff_t ArrayD::ssize() const noexcept {
    return ssize_;
}
