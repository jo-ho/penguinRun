//
// Created by User on 2019-10-28.
//

#ifndef GAME1_COLLISION_H
#define GAME1_COLLISION_H

#include <SDL.h>

class Collision {
public:
    static bool PointInRect(float x, float y, SDL_Rect rect) {
        return (x >= rect.x && x <= (rect.x + rect.w)) &&
               (y >= rect.y && y <= (rect.y + rect.h));;
    }
};

#endif //GAME1_COLLISION_H
