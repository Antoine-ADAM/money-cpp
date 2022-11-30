//
// Created by antoine on 30/11/22.
//

#include "Money.hpp"


    void Money::setMoney(long long cents) {
        if (cents > MAX || cents < -MAX) {
            throw Money::CapacityOverflowException();
        }
        cents_ = cents;
    }

    Money::Money(int dollars, int cents) {
        if(cents > 99 || cents < -99 || (dollars < 0) == (cents < 0)){
            throw Money::InvalidDecimalException();
        }
        cents_ = dollars * 100 + cents;
    }

    int Money::dollars() const {
        return cents_ / 100;
    }
    int Money::cents() const {
        return cents_ % 100;
    }

    Money Money::operator+(const Money& rhs) const {
        Money res(0, 0);
        res.setMoney(cents_ + rhs.cents_);
        return res;
    }

    Money Money::operator-(const Money& rhs) const {
        Money res(0, 0);
        res.setMoney(cents_ - rhs.cents_);
        return res;
    }

    Money Money::operator*(const Money& rhs) const {
        Money res(0, 0);
        res.setMoney(cents_ * rhs.cents_);
        return res;
    }

    Money& Money::operator+=(const Money& rhs) {
        setMoney(cents_ + rhs.cents_);
        return *this;
    }

    Money& Money::operator-=(const Money& rhs) {
        setMoney(cents_ - rhs.cents_);
        return *this;
    }

    Money& Money::operator*=(const Money& rhs) {
        setMoney(cents_ * rhs.cents_);
        return *this;
    }

    bool Money::operator==(const Money& rhs) const {
        return cents_ == rhs.cents_;
    }

    bool Money::operator!=(const Money& rhs) const {
        return !(*this == rhs);
    }

    bool Money::operator<(const Money& rhs) const {
        return cents_ < rhs.cents_;
    }

    bool Money::operator>(const Money& rhs) const {
        return rhs < *this;
    }

    bool Money::operator<=(const Money& rhs) const {
        return !(rhs < *this);
    }

    bool Money::operator>=(const Money& rhs) const {
        return !(*this < rhs);
    }

    std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << money.dollars() << "." << money.cents();
        return os;
    }
