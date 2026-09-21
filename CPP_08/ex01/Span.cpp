#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& src) : _maxSize(src._maxSize) {
    (*this) = src;
}

Span& Span::operator=(const Span& src) {
    if (this != &src)
    {
        this->_numbers = src._numbers;
        this->_maxSize = src._maxSize;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize)
        throw TooMuchNumException();
    _numbers.push_back(num);
}

double Span::shortestSpan() {

    if (_numbers.size() == 1 || _numbers.size() == 0)
        throw NeedMoreNumException();

    Span temp(*this);
    double diff = INT_MAX;

    std::sort(temp._numbers.begin(), temp._numbers.end());
    for (size_t i = 0; i < _numbers.size(); i++)
    {
        long diff_sup = INT_MAX;
        long diff_inf = INT_MAX;
        if (i == 0)
        {
            diff_sup = static_cast<long>(temp._numbers[i + 1]) - static_cast<long>(temp._numbers[i]);
            if (diff_sup > INT_MAX && _numbers.size() == 2)
                throw OverflowException();
        }
        else if (i == _numbers.size() - 1)
            diff_inf = static_cast<long>(temp._numbers[i]) - static_cast<long>(temp._numbers[i - 1]);
        else
        {
            diff_inf = static_cast<long>(temp._numbers[i]) - static_cast<long>(temp._numbers[i - 1]);
            diff_sup = static_cast<long>(temp._numbers[i + 1]) - static_cast<long>(temp._numbers[i]);
        }
        if (diff_sup == diff_inf)
        {
            if (diff_sup < diff)
                diff = diff_sup;
        }
        else if (diff_sup > diff_inf)
        {
            if (diff_inf < diff)
                diff = diff_inf;
        }
        else // diff_sup < diff_inf
        {
            if (diff_sup < diff)
                diff = diff_sup;
        }
    }
    if (diff > INT_MAX)
            throw OverflowException();
    return (diff);
}

double Span::longestSpan() {

    if (_numbers.size() == 1 || _numbers.size() == 0)
        throw NeedMoreNumException();

    Span temp(*this);
    std::sort(temp._numbers.begin(), temp._numbers.end());
    double diff = static_cast<long>(temp._numbers[_numbers.size() - 1]) - static_cast<long>(temp._numbers[0]);
    if (diff > INT_MAX)
        throw OverflowException();
    return (diff);
}