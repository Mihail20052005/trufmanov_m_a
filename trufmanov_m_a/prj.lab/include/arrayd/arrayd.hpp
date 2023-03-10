#include <cstddef>
class Arrayd {

public:
	Arrayd() = default;
	Arrayd(const Arrayd&);
	Arrayd(const std::ptrdiff_t size);
	~Arrayd() = default;

    Arrayd& operator=(const Arrayd& rhs);
    double& operator[] (const std::ptrdiff_t indx);
    const double& operator[](const std::ptrdiff_t indx) const;

    ptrdiff_t ssize() const;
    void resize(const std::ptrdiff_t new_size);

private:
    ptrdiff_t ssize_{ 0 };
    double* data_ = nullptr;
};

