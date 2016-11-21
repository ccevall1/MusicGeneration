#include "ResourceManager.h"

ResourceManager::ResourceManager()
{}

void ResourceManager::Load()
{
    for (int i = 0; i < NUM_NOTES; i++)
    {
        Sound sound = Sound(NOTE_FILE_NAMES[i]);
        m_vNotes.push_back(sound);
    }

}

void ResourceManager::Unload()
{
    for (Sound sound : m_vNotes)
    {
        sound.CleanSound();
    }
}
