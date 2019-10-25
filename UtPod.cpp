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
    numSongs = 0;
}
UtPod::UtPod(int size) {
    if (size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else
        memSize = size;
    songs = NULL;
    numSongs = 0;
}
int UtPod::addSong(Song const &s) {

    if(getRemainingMemory() >= s.getSize()) {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        numSongs++;
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
            numSongs--;
            return SUCCESS;
        }
        else if (p != NULL) {
            prev->next = p->next;
            free(p);
            numSongs--;
            return SUCCESS;
        }
    }
    return NO_MEMORY;
}
void UtPod::showSongList() {
    SongNode *p = songs;
    while(p != NULL) {
        cout << p->s << endl;
        p = p->next;
    }
}
void UtPod::sortSongList() {

    if(getTotalMemory() == -2) {
        //printf("less than 2 songs\n");
        return;
    }

    SongNode *head = songs;
    while(head != NULL) {
        Song temp2 = head->s;
        SongNode *smallest = head;
        SongNode *temp = head->next;
        while(temp != NULL) {
            if(temp2 > temp->s) {
                smallest = temp;
                temp2 = temp->s;
            }
            temp = temp->next;
        }
        head->s.swap(smallest->s);
        head = head->next;
    }
}
void UtPod::shuffle() {


}
void UtPod::clearMemory() {

    while(songs != NULL) {
        SongNode *temp = songs;
        songs = temp->next;
        free(temp);
        numSongs--;
    }
}
int UtPod::getRemainingMemory() {
    int result = 0;
    SongNode *p = songs;
    while(p != NULL) {
        result = result + p->s.getSize();
        p = p->next;
    }
    return memSize - result;
}
UtPod::~UtPod() {
    clearMemory();
    delete songs;
}