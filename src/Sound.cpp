#include "Sound.h"

using namespace std;

Sound::Sound(const char* filename)
: m_Note(NULL)
{
    m_sName = filename;
    m_Note = Mix_LoadWAV(filename);
    if (!m_Note)
    {
        cout << "SDL_Mixer could not load sound " << filename << "\nError: " << Mix_GetError() << endl;
    }
}

void Sound::CleanSound()
{
    Mix_FreeChunk(m_Note);
}

void Sound::PlaySound(int channel)
{
    Mix_PlayChannel(channel, m_Note, 0);
}

ostream& operator<<(ostream& os, const Sound& s)
{
    os << s.m_sName;
    return os;
}
