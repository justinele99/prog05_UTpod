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
Song::Song(string title, string artist, int size) {
    this->title = title;
    this->artist = artist;
    if(size > 0)
        this->size = size;
    else
        this->size = 1;
}
void Song::swap(Song &p) {

    Song temp = p;
    p.title = title;
    p.artist = artist;
    p.size = size;
    title = temp.title;
    artist = temp.artist;
    size = temp.size;
}
bool Song::operator  >(Song const &rhs) {

    if(getArtist() > rhs.getArtist())
        return true;
    if(getArtist() < rhs.getArtist())
        return false;
    if(getTitle() > rhs.getTitle())
        return true;
    if(getTitle() < rhs.getTitle())
        return false;
    return getSize() > rhs.getSize();
}
bool Song::operator  <(Song const &rhs) {

    if(getArtist() < rhs.getArtist())
        return true;
    if(getArtist() > rhs.getArtist())
        return false;
    if(getTitle() < rhs.getTitle())
        return true;
    if(getTitle() > rhs.getTitle())
        return false;
    return getSize() < rhs.getSize();
}
bool Song::operator ==(Song const &rhs) {

    return ( (rhs.getTitle()==getTitle()) && (rhs.getArtist()==getArtist()) && (rhs.getSize()==getSize()));
}
ostream& operator << (ostream& out, const Song &s) {

    out << s.getTitle() << ", " << s.getArtist() << ", " << s.getSize();
    return out;
}
