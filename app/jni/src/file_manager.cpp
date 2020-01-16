//
// Created by Admin on 2019-12-16.
//

#include <SDL_rwops.h>
#include <SDL.h>
#include "file_manager.h"
#include <iostream>
#include <fstream>

FileManager * FileManager::instance = nullptr;

FileManager::FileManager() {}

void FileManager::appendInt(const char *fileName, int value) {

    SDL_RWops *rw = SDL_RWFromFile(fileName, "ab");
    char buffer[sizeof(int)];

    SDL_itoa(value, buffer, 10);
    if(SDL_RWwrite(rw, buffer, 1, SDL_strlen(buffer))) {
        SDL_Log("append");
    }
    const char * newLine = "\n";
    if(SDL_RWwrite(rw, newLine, 1, SDL_strlen(newLine))) {
        SDL_Log("append newLine");
    }
    SDL_RWclose(rw);


}

char *FileManager::readFile(const char *fileName) {
    SDL_RWops *rw = SDL_RWFromFile(fileName, "rb");
    if (rw == NULL) return NULL;

    Sint64 res_size = SDL_RWsize(rw);
    char* res = (char*)malloc(res_size + 1);

    Sint64 nb_read_total = 0, nb_read = 1;
    char* buf = res;
    while (nb_read_total < res_size && nb_read != 0) {
        nb_read = SDL_RWread(rw, buf, 1, (res_size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }
    SDL_RWclose(rw);
    if (nb_read_total != res_size) {
        free(res);
        return NULL;
    }

    res[nb_read_total] = '\0';
    return res;
}

FileManager *FileManager::Get() {
    if (!instance) {
        instance = new FileManager();
    }
    return instance;
}

FileManager::~FileManager() {
    delete instance;
}


