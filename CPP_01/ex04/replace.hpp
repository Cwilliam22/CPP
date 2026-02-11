#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <algorithm>
#include <string>
#include <cctype>

#include <iostream>
#include <fstream>

#include <fstream>

class Replace 
{
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
        std::string _fileContent;

    public:
	    Replace(const std::string& filename, const std::string& s1, const std::string& s2);
	    ~Replace();

        bool    readFileContent();
        bool    replaceContent();
        bool    writeFileContent();

};

bool fichierExiste(const std::string& nomFichier);

#endif