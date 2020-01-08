//
// Created by Admin on 2019-12-16.
//

#include "score_manager.h"

ScoreManager * ScoreManager::instance = nullptr;

ScoreManager::ScoreManager() {}

void ScoreManager::addScore(int score) {



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
