#pragma once

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
