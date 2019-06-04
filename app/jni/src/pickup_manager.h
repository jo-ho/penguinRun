#ifndef PICKUPSPAWNMANAGER_H
#define PICKUPSPAWNMANAGER_H


#include "video.h"
#include "pickup.h"
#include "timer.h"
#include "player.h"
#include "pickup_factory.h"
#include <vector>
#include <memory>

class PickupManager {
    public:
        PickupManager();

        void spawn(Video & video, void * code);
        void update();
        void render(Video & video);
        void checkCollisions(std::unique_ptr<Player> &player);
        void createTimers(Video & video);
    private:
        std::vector<std::shared_ptr<Pickup>> pickups;
        static Uint32 pushEventToQueue(Uint32 interval, void * param);
        void spawnPickup(Video & video, PickupFactory::PickupType pickupType);

};


#endif
