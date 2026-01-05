#include <iostream>
#include <string>

// concat all arguments in uppercase

int main(int argc, char **argv)
{
    int nb_arg;
    char *str;

    nb_arg = argc - 1;
    str = malloc(sizeof(char) * 1);
    str[0] = '\0';
    while (nb_arg > 0)
    {
        char *arg = argv[nb_arg];
        int i = 0;
        while (arg[i])
        {
            char c = arg[i];
            if (c >= 'a' && c <= 'z')
                c = c - ('a' - 'A');
            char *new_str = malloc(sizeof(char) * (strlen(str) + 2));
            strcpy(new_str, str);
            new_str[strlen(str)] = c;
            new_str[strlen(str) + 1] = '\0';
            free(str);
            str = new_str;
            i++;
        }
        if (nb_arg > 1)
        {
            char *new_str = malloc(sizeof(char) * (strlen(str) + 2));
            strcpy(new_str, str);
            new_str[strlen(str)] = ' ';
            new_str[strlen(str) + 1] = '\0';
            free(str);
            str = new_str;
        }
        nb_arg--;
    }
    std::cout << str << std::endl;
    return (0);
}
