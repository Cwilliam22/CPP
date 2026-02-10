#include "replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2)
{
    //std::cout << "Constructor called" << std::endl;
    _filename = filename;
    _s1 = s1;
    _s2 = s2;
    return ;
}

Replace::~Replace()
{
    //std::cout << "Destructor called" << std::endl;
    return ;
}

bool    Replace::readFileContent()
{
    std::string line;
    std::ifstream file;
    file.open(_filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << _filename << std::endl;
        return (false);
    }
    while (getline(file, line))
    {
        _fileContent += line;
        _fileContent += "\n";
    }
    file.close();
    if (file.is_open())
    {
        std::cerr << "Error: Could not close file " << _filename << std::endl;
        return (false);
    }
    return (true);
}

bool    Replace::replaceContent()
{
    size_t pos = 0;
    while ((pos = _fileContent.find(_s1, pos)) != std::string::npos)
    {
        _fileContent.erase(pos, _s1.length());
        _fileContent.insert(pos, _s2);
        pos += _s2.length();
    }
    return (true);
}

bool    Replace::writeFileContent()
{
    std::ofstream file;
    file.open(_filename + ".replace");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << _filename + ".replace" << std::endl;
        return (false);
    }
    file << _fileContent;
    file.close();
    if (file.is_open())
    {
        std::cerr << "Error: Could not close file " << _filename + ".replace" << std::endl;
        return (false);
    }
    return (true);
}