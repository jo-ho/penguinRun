//
// Created by Admin on 2019-12-16.
//

#include <string>
#include "score_manager.h"
#include "file_manager.h"
#include <SDL.h>

ScoreManager * ScoreManager::instance = nullptr;

ScoreManager::ScoreManager() {}

void ScoreManager::addScore(int score) {
    FileManager * fm = FileManager::Get();
    fm->appendInt(SCORES_FILE, score);
}

ScoreManager * ScoreManager::Get() {
    if (!instance) {
        instance = new ScoreManager();
    }
    return instance;
}

ScoreManager::~ScoreManager() {
    delete instance;

}

std::vector<int> ScoreManager::getScores() {
    std::vector<int> scores;
    FileManager * fm = FileManager::Get();
    const char * scoresFromFile = fm->readFile(SCORES_FILE);
    if (!scoresFromFile) return scores;
    std::string scoresList(scoresFromFile);

    std::string delimiter = "\n";

    size_t pos = 0;
    std::string token;
    while ((pos = scoresList.find(delimiter)) != std::string::npos) {
        token = scoresList.substr(0, pos);
        scores.push_back(std::stoi(token));
        scoresList.erase(0, pos + delimiter.length());
    }
    return scores;
}
