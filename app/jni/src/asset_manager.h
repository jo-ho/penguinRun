//
// Created by User on 2020-01-27.
//

#ifndef GAME1_ASSET_MANAGER_H
#define GAME1_ASSET_MANAGER_H


class AssetManager {
public:

    static AssetManager * Get();



private:
    static AssetManager * instance;
    AssetManager();
    ~AssetManager();
};


#endif //GAME1_ASSET_MANAGER_H
