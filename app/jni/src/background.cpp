#include "background.h"

ScrollableBackground::ScrollableBackground(Video &video, const char *fileName, int imgWidth, int imgHeight) {
    sprite = std::unique_ptr<Sprite>(new Sprite(video, fileName, 0, 0, imgWidth, imgHeight, 0,0 , false));
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
