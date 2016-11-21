#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <vector>

#include "Sound.h"

using namespace std;

static const int NUM_NOTES = 10;
static const char* NOTE_FILE_NAMES[] = {"./audio/C.wav", "./audio/C#.wav", "./audio/D.wav", "./audio/Eb.wav", "./audio/E.wav", "./audio/F.wav", "./audio/Gb.wav", "./audio/G.wav", "./audio/A.wav", "./audio/Bb.wav"};

class ResourceManager
{

    public:
        ResourceManager();
        void Load();
        void Unload();
        Sound GetNote(int index) { return m_vNotes[index]; }

    private:
        vector<Sound> m_vNotes;
};

#endif 
