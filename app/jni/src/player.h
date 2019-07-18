
#ifndef PLAYER_H
#define PLAYER_H


#include "animated_sprite.h"
#include <map>

const static int DEFAULT_VELOCITY = 10;
const static int SLOW_VELOCITY = 5;
const static int FAST_VELOCITY = 20;

enum MoveState { MOVING_UP, STOPPED, MOVING_DOWN };
enum SpeedState {NORMAL, SLOWED, SPED_UP};
enum DamagedState {UNHURT ,SHIELDED, DEAD};


class Player  {
public:
    Player(Video &video);

    const static int TILE_WIDTH;
    const static int TILE_HEIGHT;

    void setMoveState(MoveState newState);
    void setSpeedState(SpeedState newState);
    void setDamagedState(DamagedState newState);
    SpeedState getSpeedState();
    DamagedState getDamagedState();

    void increaseScore(int num);
    int getScore();

    SDL_Rect getCollider();
    bool checkCollision(SDL_Rect collider);

    void initSprites(Video & video);
    void render(Video & video);
    void update(int screenSizeY, int elapsedTime);

    int getX();
    int getY();

private:
    const static int NUM_FRAMES;
    const static int TARGET_FPS;
    const static char * SPRITE_FILE_NAME;


    std::map<MoveState, std::unique_ptr<AnimatedSprite>> sprites;
    std::unique_ptr<Sprite> shieldSprite;
    MoveState moveState;
    SpeedState speedState;
    DamagedState damagedState;

    int x;
    int y;
    int playerVelY;
    int score;




};


#endif
