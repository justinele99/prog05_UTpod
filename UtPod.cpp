//
// Created by justi on 10/20/2019.
//
#include "UtPod.h"
#include <iostream>
#include <cstdlib>
using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
}
UtPod::UtPod(int size) {
    if (size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else
        memSize = size;
    songs = NULL;
}
int UtPod::addSong(Song const &s) {

    if(getRemainingMemory() >= s.getSize()) {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return SUCCESS;
    }
    return NO_MEMORY;
}
int UtPod::removeSong(Song const &s) {

    SongNode *p = songs;
    SongNode *prev = NULL;

    if(songs == NULL)
        return NO_MEMORY;
    else {
        while ((p != NULL) && !(p->s == s)) {
            prev = p;
            p = p->next;
        }
        if (prev == NULL) { //first in list
            songs = p->next;
            free(p);
            return SUCCESS;
        }
        else if (p != NULL) {
            prev->next = p->next;
            free(p);
            return SUCCESS;
        }
    }
    return NO_MEMORY;
}
void UtPod::shuffle() {

}

void UtPod::showSongList() {
    SongNode *p = songs;
    while(p != NULL) {
        cout << p->s << endl;
        p = p->next;
    }
}
void UtPod::sortSongList() {

}
void UtPod::clearMemory() {
    while(songs != NULL) {

    }
}
int UtPod::getRemainingMemory() {

    return MAX_MEMORY;
}