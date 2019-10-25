//
// Created by justi on 10/20/2019.
//
#include "Song.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Song::Song() {
    title = "";
    artist = "";
    size = 1;
}
Song::Song(string artist, string title, int size) {
    this->title = title;
    this->artist = artist;
    if(size > 0)
        this->size = size;
    else
        this->size = 1;
}
void Song::swap(Song &p) {

    Song temp = p;
    p = *this;
    *this = temp;
}
bool Song::operator  >(Song const &rhs) {

    if(artist > rhs.artist)
        return true;
    if(artist < rhs.artist)
        return false;
    if(title > rhs.title)
        return true;
    if(title < rhs.title)
        return false;
    return size > rhs.size;
}
bool Song::operator  <(Song const &rhs) {

    if(artist < rhs.artist)
        return true;
    if(artist > rhs.artist)
        return false;
    if(title < rhs.title)
        return true;
    if(title > rhs.title)
        return false;
    return size < rhs.size;
}
bool Song::operator ==(Song const &rhs) {

    return ( (rhs.getTitle()==getTitle()) && (rhs.getArtist()==getArtist()) && (rhs.getSize()==getSize()));
}
ostream& operator << (ostream& out, const Song &s) {

    out << s.getTitle() << ", " << s.getArtist() << ", " << s.getSize();
    return out;
}
