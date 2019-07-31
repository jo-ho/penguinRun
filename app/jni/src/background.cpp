#include "background.h"

Background::Background(Video &video, const char *fileName) {
    texture = video.loadImage(fileName, false);
}

void Background::render(Video & video) {
    video.renderTexture(texture, NULL, NULL);
}
