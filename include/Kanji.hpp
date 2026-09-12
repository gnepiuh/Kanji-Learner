#ifndef KANJI_HPP
#define KANJI_HPP

#include <string>
#include <vector>

struct Kanji
{
    std::string character;
    std::vector<std::string> reading;
    std::vector<std::string> romaji;
    std::string meaning;
};

#endif