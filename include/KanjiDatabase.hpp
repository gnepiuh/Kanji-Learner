#pragma once

#include "Kanji.hpp"
#include <string>
#include <vector>

class KanjiDatabase
{
public:
    bool loadKanjiFile(const std::string &fn);
    const Kanji &getKanji(int index);
    size_t getSize();
    void randomizeQuestion();

private:
    std::vector<Kanji> kanjiList;
};
