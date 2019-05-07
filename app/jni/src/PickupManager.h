#ifndef PICKUPSPAWNMANAGER_H
#define PICKUPSPAWNMANAGER_H


#include "Video.h"
#include "Pickup.h"
#include "Timer.h"
#include "Player.h"
#include <vector>
#include <memory>

class PickupManager {
    public:
        PickupManager(Video &video);

    void spawn();
        void update();
        void render();
        void checkCollisions(std::shared_ptr<Player> player);
    private:
        std::vector<std::shared_ptr<Pickup>> pickups;
        Timer scorePickupTimer;
        Timer speedPickupTimer;
        Timer slowPickupTimer;
        Video video;
        template <class Class> void spawnPickup();



};


#endif