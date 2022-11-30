//
// Created by antoine on 30/11/22.
//

#ifndef TEST_MONEY_HPP
#define TEST_MONEY_HPP

#include <iostream>


class Money{
    private:
        static constexpr long long  MAX = 214748364898;
        long long cents_;
        void setMoney(long long cents);
    public:
    //header
        class CapacityOverflowException: std::runtime_error{
            public:
                CapacityOverflowException(): std::runtime_error("CapacityOverflowException"){}
                ~CapacityOverflowException() = default;
        };
        class InvalidDecimalException: std::runtime_error{
            public:
                InvalidDecimalException(): std::runtime_error("InvalidDecimalException"){}
                ~InvalidDecimalException() = default;
        };
        Money(int dollars, int cents);
        int dollars() const;
        int cents() const;
        Money operator+(const Money& rhs) const;
        Money operator-(const Money& rhs) const;
        Money operator*(const Money& rhs) const;
        Money& operator+=(const Money& rhs);
        Money& operator-=(const Money& rhs);
        Money& operator*=(const Money& rhs);
        bool operator==(const Money& rhs) const;
        bool operator!=(const Money& rhs) const;
        bool operator<(const Money& rhs) const;
        bool operator>(const Money& rhs) const;
        bool operator<=(const Money& rhs) const;
        bool operator>=(const Money& rhs) const;


};


#endif //TEST_MONEY_HPP
