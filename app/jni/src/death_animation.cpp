
#include "death_animation.h"
#include "player.h"

const int DeathAnimation::TARGET_FPS = 5;
const int DeathAnimation::NUM_FRAMES = 6;

DeathAnimation::DeathAnimation(Video &video) :
        AnimatedSprite(video, "death.png", 0, 0, Player::TILE_WIDTH, Player::TILE_HEIGHT, 0, 0,
                       NUM_FRAMES, TARGET_FPS) {
}
