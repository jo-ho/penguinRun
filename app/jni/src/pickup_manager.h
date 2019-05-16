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

        void spawn(Video & video);
        void update();
        void render(Video & video);
        void checkCollisions(std::shared_ptr<Player> player);
    private:
        std::vector<std::shared_ptr<Pickup>> pickups;
        Timer scorePickupTimer;
        Timer speedPickupTimer;
        Timer slowPickupTimer;
        template <class Class> void spawnPickup(Video & video);



};


#endif
