#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>

bool InvalidDate(std::string date);
bool InvalidValue(std::string value);

bool lineCheck(std::string line);

#endif