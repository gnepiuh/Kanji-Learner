#pragma once

#include "KanjiDatabase.hpp"

class KanjiStudy
{
public:
    KanjiStudy(KanjiDatabase& database);
    void startStudy();
    void displayKanji(const Kanji& kanji);
private:
    KanjiDatabase& database;
};

