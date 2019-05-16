

#ifndef SCOREPICKUP_H
#define SCOREPICKUP_H


#include "pickup.h"

class ScorePickup : public Pickup {
    public:
        const static int SPAWN_DELAY_MS;
        ScorePickup(Video& video,
                       int initX,
                       int initY);
        void activateAction(std::shared_ptr<Player> player);


};


#endif
