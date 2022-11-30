#include <iostream>

class Money {
private:
    int dollars_;
    int cents_;
public:

    Money(int dollars, int cents) : dollars_(dollars), cents_(cents) {}

    int dollars() const { return dollars_; }
    int cents() const { return cents_; }

    Money operator+(const Money& rhs) const {
        return Money(dollars_ + rhs.dollars_, cents_ + rhs.cents_);
    }

    Money operator-(const Money& rhs) const {
        return Money(dollars_ - rhs.dollars_, cents_ - rhs.cents_);
    }

    Money operator*(const Money& rhs) const {
        return Money(dollars_ * rhs.dollars_, cents_ * rhs.cents_);
    }

    Money& operator+=(const Money& rhs) {
        dollars_ += rhs.dollars_;
        cents_ += rhs.cents_;
        return *this;
    }

    Money& operator-=(const Money& rhs) {
        dollars_ -= rhs.dollars_;
        cents_ -= rhs.cents_;
        return *this;
    }

    Money& operator*=(const Money& rhs) {
        dollars_ *= rhs.dollars_;
        cents_ *= rhs.cents_;
        return *this;
    }

    bool operator==(const Money& rhs) const {
        return dollars_ == rhs.dollars_ && cents_ == rhs.cents_;
    }

    bool operator!=(const Money& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Money& rhs) const {
        return dollars_ < rhs.dollars_ || (dollars_ == rhs.dollars_ && cents_ < rhs.cents_);
    }

    bool operator>(const Money& rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Money& rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Money& rhs) const {
        return !(*this < rhs);
    }

friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << money.dollars_ << "." << money.cents_;
        return os;
    }
};

int main() {
    Money m1(10, 50);
    Money m2(5, 25);

    std::cout << m1 << " + " << m2 << " = " << m1 + m2 << std::endl;
    return 0;
}