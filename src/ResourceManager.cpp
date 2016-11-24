#include "ResourceManager.h"
#include "Static.h"

ResourceManager::ResourceManager(SDL_Renderer* gRenderer)
: m_gRenderer(gRenderer)
{}

void ResourceManager::Load()
{
    for (int i = 0; i < NUM_NOTES; i++)
    {
        Sound sound = Sound(NOTE_FILE_NAMES[i]);
        m_vNotes.push_back(sound);
    }

    SDL_Surface* surface = IMG_Load(PLAYER_SPRITE_NAME);
    Sprite* sPlayerSprite = new Sprite(SDL_CreateTextureFromSurface(m_gRenderer, surface), 64, 64);
    m_mSprites["PLAYER_SPRITE"] = sPlayerSprite;

    surface = IMG_Load(BACKGROUND_IMAGE_NAME);
    Sprite* sBackground = new Sprite(SDL_CreateTextureFromSurface(m_gRenderer, surface), 704, 220);
    m_mSprites["BACKGROUND_SPRITE"] = sBackground;

    surface = IMG_Load(INVALID_IMAGE_NAME);
    Sprite* sInvalid = new Sprite(SDL_CreateTextureFromSurface(m_gRenderer, surface), 300, 300);
    m_mSprites["INVALID"] = sInvalid;

    if (surface != NULL)
        SDL_FreeSurface(surface);

}

void ResourceManager::Unload()
{
    for (Sound sound : m_vNotes)
    {
        sound.CleanSound();
    }

    m_mSprites.clear();
}
