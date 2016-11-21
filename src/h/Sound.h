#ifndef SOUND_H
#define SOUND_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class Sound
{
    public:
        Sound(const char* filename);
        void CleanSound();
        void PlaySound(int channel = -1);

    private:
        Mix_Chunk* m_Note;
        const char* m_sName;

    friend std::ostream& operator<<(std::ostream& os, const Sound& s);
};

#endif
