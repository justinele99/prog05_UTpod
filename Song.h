//
// Created by justi on 10/20/2019.
//

#ifndef PROG5_SONG_H
#define PROG5_SONG_H
#include <string>
#include <utility>
using namespace std;

class Song {
    private:
        string title;
        string artist;
        int size;

    public:
        Song();
        Song(string inTitle, string inArtist, int inSize);

        string getTitle() const
        {   return title;   }
        string getArtist() const
        {   return artist;  }
        int getSize() const
        {   return size;    }

        void swap(Song &p);

        bool operator  >(Song const &rhs);
        bool operator  <(Song const &rhs);
        bool operator ==(Song const &rhs);

        ~Song() {

        }
};

ostream& operator << (ostream& out, const Song &s);

#endif //PROG5_SONG_H
