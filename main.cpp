#include <iostream>
#include <cstring>
#include <cctype>

constexpr int ALPH_BEG = 65;
constexpr int ALPH_NUM = 26;

inline void decode_cipher(std::string & cipher, int offset)
{
    if(offset < 1 || offset > 10)
        throw std::logic_error("offset num must be from 1 to 10");
    for(auto & i : cipher)
    {
        if(i == ' ')
            continue;
        i = (i - offset - ALPH_BEG + ALPH_NUM) % ALPH_NUM + ALPH_BEG;
    }
}

inline void upper_str(std::string & cipher)
{
    for(auto & i : cipher)
    {
        if(i != ' ' && !std::isalpha(i))
            throw std::logic_error("Incorrect char in str");
        if(islower(i))
            i = std::toupper(i);
    }
}

int main(int argc, char **argv)
{
    std::string cipher;
    int offset;
    try
    {
        std::cout << "Enter encoded text:\n";
        std::getline(std::cin, cipher);
        std::cout << "Enter offset:\n";
        std::cin >> offset;
        upper_str(cipher);
        decode_cipher(cipher, offset);
        std::cout << "Decoded cipher: " + cipher << "\n";
    }
    catch(const std::exception & except)
    {
        std::cout << "ERROR: " << except.what() << "\n";
    }
    return 0;
}