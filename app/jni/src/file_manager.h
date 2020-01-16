//
// Created by Admin on 2019-12-16.
//

#ifndef GAME1_FILE_MANAGER_H
#define GAME1_FILE_MANAGER_H


class FileManager {
public:

    static FileManager * Get();
    void appendInt(const char * fileName, int value);
    char * readFile(const char * fileName);



private:
    static FileManager * instance;
    FileManager();
    ~FileManager();
};


#endif //GAME1_FILE_MANAGER_H
