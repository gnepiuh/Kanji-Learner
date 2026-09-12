#include "KanjiDatabase.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool KanjiDatabase::loadKanjiFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (!file)
    {
        return false;
    }
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream lineStream(line);
        Kanji kanji;

        // Character
        std::getline(lineStream, kanji.character, '\t');

        // Hiragana readings
        std::string hiraganaField;
        std::getline(lineStream, hiraganaField, '\t');

        std::stringstream hiraganaStream(hiraganaField);
        std::string hiragana;

        while (std::getline(hiraganaStream, hiragana, ','))
        {
            kanji.reading.push_back(hiragana);
        }

        // Romaji readings
        std::string romajiField;
        std::getline(lineStream, romajiField, '\t');

        std::stringstream romajiStream(romajiField);
        std::string romaji;

        while (std::getline(romajiStream, romaji, ','))
        {
            kanji.romaji.push_back(romaji);
        }

        // Meaning
        std::getline(lineStream, kanji.meaning, '\t');

        kanjiList.push_back(kanji);
    }

    return true;
}

Kanji &KanjiDatabase::getKanji(int index)
{
    return kanjiList[index];
}

size_t KanjiDatabase::getSize()
{
    return kanjiList.size();
}