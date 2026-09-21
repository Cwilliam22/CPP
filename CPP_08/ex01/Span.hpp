#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

class Span 
{
    private:
        std::vector<int> _numbers;
        unsigned int     _maxSize;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        void addNumber(int num);
        double shortestSpan();
        double longestSpan();

        template <typename InputIterator>
        void addRange(InputIterator begin, InputIterator end) {
            while (begin != end)
            {
                addNumber(*begin);
                begin++;
            }
        }
        
        class TooMuchNumException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return ("Too much Span!");
                }
        };

        class NeedMoreNumException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return ("Need more Span!");
                }
        };

        class OverflowException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return ("The longest or the shortest span is bigger than INT_MAX!");
                }
        };

};

#endif