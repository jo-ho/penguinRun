#ifndef SPEEDPICKUP_H
#define SPEEDPICKUP_H


#include "pickup.h"



class SpeedPickup : public Pickup {
    public:
        const static int SPAWN_DELAY_MS;
        SpeedPickup(Video & video,
                int initX,
                int initY);
        void activateAction(std::shared_ptr<Player> player);

};


#endif