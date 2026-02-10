#include "replace.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <char to replace> <char to replace with>" << std::endl;
        return (1);
    }
    Replace replace(argv[1], argv[2], argv[3]);

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::cout << "File Successfully Created: " << filename + "replace.txt" << std::endl;
    if (!replace.readFileContent())
        return (1);
    if (!replace.replaceContent())
        return (1);
    if (!replace.writeFileContent())
        return (1);
    return (0);
}