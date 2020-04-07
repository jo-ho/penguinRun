#include "static_text.h"
#include "asset_manager.h"

StaticText::StaticText(Video &video, const char *fontName, const char *text, SDL_Color color) {
    texture = video.loadText(AssetManager::Get()->GetFont(fontName), text, color);

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    this->w = w;
    this->h = h;

}

StaticText::~StaticText() {
    if(texture) {
        SDL_DestroyTexture(texture);
    }

}

void StaticText::render(Video &video, int destX, int destY) {
    SDL_Rect destRect;
    destRect.x = destX;
    destRect.y = destY;
    destRect.w = w;
    destRect.h = h;
    video.renderTexture(texture, NULL, &destRect);
}
