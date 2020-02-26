#include "background.h"
#include "asset_manager.h"

ScrollableBackground::ScrollableBackground(const char * name) {
    sprite = AssetManager::Get()->GetSprite(name);
    offset = 0;
}

void ScrollableBackground::render(Video & video) {
    sprite->renderStretchToBackground(video, offset, 0);
    sprite->renderStretchToBackground(video, offset + video.getScreenSizeW(), 0);
}

void ScrollableBackground::update(int screenSizeW) {
    --offset;
    if (offset < -screenSizeW) {
        offset = 0;
    }

}
