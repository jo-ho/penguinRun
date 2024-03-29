#ifndef PICKUPSPAWNMANAGER_H
#define PICKUPSPAWNMANAGER_H


#include "video.h"
#include "pickup.h"
#include "timer.h"
#include "player.h"
#include "pickup_factory.h"
#include <vector>
#include <memory>
#include <map>

class PickupManager {
    public:
        PickupManager();
        ~PickupManager();

        void spawn(Video & video, void * code, int spawnAreaHeight);
        void update(int screenHeight, int elapsedTime);
        void render(Video & video);
        void checkCollisions(std::unique_ptr<Player> &player);
        void resumeTimers();
        void stopTimers();
    private:
        const int DIFF_INCREASE_TIME_MS = 15000;
        const int DIFF_SCALING_FACTOR = 20;
        const int DIFF_CAP_MS = 700;
        std::vector<std::shared_ptr<Pickup>> pickups;
        std::map<PickupFactory::PickupType, SDL_TimerID> timerIDs;
        Timer diffIncreaseTimer;
        static Uint32 pushEventToQueue(Uint32 interval, void * param);
        void spawnPickup(Video & video, PickupFactory::PickupType pickupType, int spawnAreaHeight);
        void changeSpawnDelay(PickupFactory::PickupType pickupType, const int delay);
};


#endif
