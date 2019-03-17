#ifndef VIDEO_H
#define VIDEO_H

#include <SDL.h>
#include <string>

class Video {
    public:
        Video();
        ~Video();
        void init();
        void clear();
        void present();
        void renderTexture(SDL_Texture * targetTexture, SDL_Rect * srcRect, SDL_Rect * destRect);

        int getScreenSizeW();
        int getScreenSizeH();

        SDL_Texture * loadImage(const char * fileName, bool colorKey );
    private:
        SDL_DisplayMode displayMode;
        SDL_Renderer * renderer;
        SDL_Window * window;
        SDL_Rect screenSize;
};


#endif
