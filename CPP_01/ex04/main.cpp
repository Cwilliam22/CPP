#include "replace.hpp"

bool fichierExiste(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier.c_str());
    return (fichier.good());
}

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

    if (!fichierExiste(filename))
    {
        std::cerr << "Error: File " << filename << " does not exist." << std::endl;
        return (1);
    }
    std::cout << "File Successfully Created: " << filename + "replace.txt" << std::endl;
    if (!replace.readFileContent())
        return (1);
    if (!replace.replaceContent())
        return (1);
    if (!replace.writeFileContent())
        return (1);
    return (0);
}