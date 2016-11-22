#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <vector>

#include "Sound.h"

using namespace std;

static const int NUM_NOTES = 7;
static const char* NOTE_FILE_NAMES[] = {"./audio/C.ogg", "./audio/C#.ogg", "./audio/D.ogg", "./audio/Eb.ogg", "./audio/E.ogg", "./audio/F.ogg", "./audio/Gb.ogg", "./audio/G.ogg", "./audio/A.ogg", "./audio/Bb.ogg", "./audio/B.ogg"};

class ResourceManager
{

    public:
        ResourceManager();
        void Load();
        void Unload();
        Sound GetNote(int index) { return m_vNotes[index]; }
        vector<Sound> GetAllNotes() { return m_vNotes; }

    private:
        vector<Sound> m_vNotes;
};

#endif 
