#ifndef fraction_h
#define fraction_h

#include <iostream>
using namespace std;

class fraction {
    friend ostream& operator<<(ostream& os, const fraction& f);

private:
    int n;
    int d;
    int gcd(int a, int b);
    void sim();

public:
    fraction();
    fraction(int nn, int dd);

    fraction operator+(const fraction& other) const;
    fraction operator-(const fraction& other) const;
    fraction operator*(const fraction& other) const;
    fraction operator/(const fraction& other) const;

    fraction operator++();
    fraction operator++(int);
    fraction operator--();
    fraction operator--(int);

    bool operator==(const fraction& other) const;
    bool operator!=(const fraction& other) const;
    bool operator<(const fraction& other) const;
    bool operator>(const fraction& other) const;
    bool operator<=(const fraction& other) const;
    bool operator>=(const fraction& other) const;
};

#endif