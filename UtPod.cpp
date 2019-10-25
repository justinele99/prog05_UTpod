//
// Created by justi on 10/20/2019.
//
#include "UtPod.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
    numSongs = 0;
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
}
UtPod::UtPod(int size) {
    if (size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else
        memSize = size;
    songs = NULL;
    numSongs = 0;
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
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

    if(getTotalMemory() == NOT_FOUND) {
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

    if(getTotalMemory() == NOT_FOUND) {
        //printf("less than 2 songs\n");
        return;
    }

    for(int numShuffles = 0; numShuffles < (this->getNumSongs())*100; numShuffles++) {

        time_t timer = time(NULL);

        int song1_Index = rand() % (this->getNumSongs()+1);
        int song2_Index = rand() % (this->getNumSongs()+1);
        if(song1_Index == song2_Index){
            song1_Index++;
        }

        SongNode *song1 = songs; // song1 is first in list
        SongNode *song2 = songs;

        //making song1 point to first song to swtich
        for(int i =0; i < song1_Index; i++){
            if(song1->next != NULL) {
                song1 = song1->next;
            }
        }
        // making song2 point to second song to switch
        for (int j = 0; j < song2_Index; j++) {
            if(song2->next != NULL) {
                song2 = song2->next;
            }
        }

        // swapping songs
        song1->s.swap(song2->s);

    }
}
int UtPod::getNumSongs() {

    int numSongs = 0;
    SongNode *temp = songs;
    while(temp->next != NULL){
        numSongs++;
        temp = temp->next;
    }
    numSongs++;
    return numSongs;
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