//
// Created by justi on 10/20/2019.
//
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Bartist", "Asong", 3);
    int result = t.addSong(s1);//cout << "result = " << result << endl;
    Song s2("Bartist", "Bsong", 4);
    t.addSong(s2);
    Song s3("Aartist", "Bsong", 2);
    t.addSong(s3);
    Song s4("Aartist", "Asong", 1);
    t.addSong(s4);
    Song s5("Cartist", "Csong", 5);
    t.addSong(s5);
    Song s6("Cartist", "Csong", 6);
    t.addSong(s6);

    printf("----------------\n");
    t.showSongList();
    printf("----------------\n");
    t.sortSongList();
    printf("----------------\n");
    t.showSongList();

}
