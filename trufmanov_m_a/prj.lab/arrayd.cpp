#include "include/arrayd/arrayd.hpp"
#include <stdexcept>

Arrayd::Arrayd(const Arrayd& rhs){
    ssize_ = rhs.ssize_;
    data_ = rhs.data_;
}


Arrayd::Arrayd(std::ptrdiff_t size){
    if(ssize_ < 0){
        throw std::invalid_argument("ssize need be positive");
    }else{
        ssize_ = size;
        double* data_ = new double[ssize_];
    
    }
    
}


Arrayd& Arrayd::operator=(const Arrayd& rhs){
    ssize_ = rhs.ssize_;
    data_ = rhs.data_;
    return *this;
}

ptrdiff_t Arrayd::ssize() const{
	//throw std::overflow_error("Index out of range");
	return ssize_;
}

void Arrayd::resize(std::ptrdiff_t new_size){
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

double& Arrayd::operator[](const std::ptrdiff_t indx){
    if(indx < 0 || indx >= ssize_){
        std::invalid_argument("index out of range");
    }else{
        return data_[ssize_];
    }
}

const double& Arrayd::operator[](const std::ptrdiff_t indx) const{
    if(indx < 0 || indx >= ssize_){
        std::invalid_argument("index out of range");
    }else{
        return data_[ssize_];
    }
}


