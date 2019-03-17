

#ifndef SCOREPICKUP_H
#define SCOREPICKUP_H


#include "pickup.h"

class ScorePickup : public Pickup {
    public:
        const static int SPAWN_DELAY_MS;
        const static int PICKUP_WIDTH;
        const static int PICKUP_HEIGHT;
        ScorePickup(Video& video,
                       int initX,
                       int initY);
        SDL_Rect getCollider();


};


#endif
