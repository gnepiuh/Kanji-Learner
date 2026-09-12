#ifndef KANJI_DATABASE_HPP
#define KANJI_DATABASE_HPP

#include "Kanji.hpp"
#include <string>
#include <vector>

class KanjiDatabase
{
public:
    bool loadKanjiFile(const std::string &fn);
    Kanji &getKanji(int index);
    size_t getSize();

private:
    std::vector<Kanji> kanjiList;
};

#endif