#ifndef PICKUPSPAWNMANAGER_H
#define PICKUPSPAWNMANAGER_H


#include "video.h"
#include "pickup.h"
#include "timer.h"
#include "player.h"
#include <vector>
#include <memory>

class PickupManager {
    public:
        PickupManager();

        void spawn(Video & video, void * code);
        void update();
        void render(Video & video);
        void checkCollisions(std::shared_ptr<Player> player);
        void createTimers(Video & video);
    private:
        std::vector<std::shared_ptr<Pickup>> pickups;
        enum Code {SCORE_PICKUP,SLOW_PICKUP, SPEED_PICKUP, DEATH_PICKUP };
        static Uint32 pushEventToQueue(Uint32 interval, void * param);
        template <class Class> void spawnPickup(Video & video);

};


#endif
