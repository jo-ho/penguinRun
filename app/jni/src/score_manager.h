//
// Created by Admin on 2019-12-16.
//

#ifndef GAME1_SCORE_MANAGER_H
#define GAME1_SCORE_MANAGER_H
#include <vector>

const static   char * SCORES_FILE = "scores.txt";


class ScoreManager {
public:

    static ScoreManager * Get();
    void addScore(int score);
    std::vector<int> getScores();

private:
    static ScoreManager * instance;
    ScoreManager();
    ~ScoreManager();
};


#endif //GAME1_SCORE_MANAGER_H
