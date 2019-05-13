#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include "video.h"

class Text {
public:
    Text(int size);
    ~Text();
    void render(Video & video, const char * text, SDL_Color color, int destX, int destY);
private:
    TTF_Font * font;
};


#endif
