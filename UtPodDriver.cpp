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

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    int result2 = t.getRemainingMemory();
    cout << "result = " << result << " result2 = " << result2 << endl;

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    result2 = t.getRemainingMemory();
    cout << "result = " << result << " result2 = " << result2 << endl;

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("The Misfits", "Last Caress", 5);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("The Replacements", "Androgynous", 2);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    Song s8("Vashti Bunyan", "Train Song", 19);
    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    Song s9("Glinksadg", "fjfjfjf", 5);
    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    printf("\n----------------\n");
    t.showSongList();
    printf("\n----------------\n");

    t.sortSongList();
    t.showSongList();
    printf("\n----------------\n");

}
