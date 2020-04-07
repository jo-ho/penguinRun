#include "text.h"
#include "asset_manager.h"
#include <SDL.h>
#include <SDL_ttf.h>



Text::Text (const char * fontName) {
    font = AssetManager::Get()->GetFont(fontName);
}


void Text::render(Video  &video, const char * text, SDL_Color color, int destX, int destY) {
    SDL_Texture * texture = video.loadText(font, text, color);
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    this->w = w;
    this->h = h;
    SDL_Rect destRect;
    destRect.x = destX;
    destRect.y = destY;
    destRect.w = w;
    destRect.h = h;
    video.renderTexture(texture, NULL, &destRect);
    SDL_DestroyTexture(texture);

}




