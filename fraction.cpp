#include "fraction.h"
#include <cmath>
#include <iostream>

int fraction::gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void fraction::sim() {
    if (d == 0) {
        d = 1;
        return;
    }
    if (d < 0) {
        n = -n;
        d = -d;
    }
    int c = gcd(abs(n), abs(d));
    n /= c;
    d /= c;
}

fraction::fraction() : n(0), d(1) {}

fraction::fraction(int nn, int dd) : n(nn), d(dd) {
    sim();
}

ostream& operator<<(ostream& os, const fraction& f) {
    os << f.n << "/" << f.d;
    return os;
}

fraction fraction::operator+(const fraction& other) const {
    int new_n = (n * other.d) + (other.n * d);
    int new_d = d * other.d;
    return fraction(new_n, new_d);
}

fraction fraction::operator-(const fraction& other) const {
    int new_n = (n * other.d) - (other.n * d);
    int new_d = d * other.d;
    return fraction(new_n, new_d);
}

fraction fraction::operator*(const fraction& other) const {
    return fraction(n * other.n, d * other.d);
}

fraction fraction::operator/(const fraction& other) const {
    return fraction(n * other.d, d * other.n);
}

fraction fraction::operator++() {
    n += d;
    sim();
    return *this;
}

fraction fraction::operator++(int) {
    fraction temp = *this;
    n += d;
    sim();
    return temp;
}

fraction fraction::operator--() {
    n -= d;
    sim();
    return *this;
}

fraction fraction::operator--(int) {
    fraction temp = *this;
    n -= d;
    sim();
    return temp;
}

bool fraction::operator==(const fraction& other) const {
    return (n == other.n) && (d == other.d);
}

bool fraction::operator!=(const fraction& other) const {
    return !(*this == other);
}

bool fraction::operator<(const fraction& other) const {
    return (n * other.d) < (other.n * d);
}

bool fraction::operator>(const fraction& other) const {
    return (n * other.d) > (other.n * d);
}

bool fraction::operator<=(const fraction& other) const {
    return !(*this > other);
}

bool fraction::operator>=(const fraction& other) const {
    return !(*this < other);
}