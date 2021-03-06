#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "Constants.h"

using namespace std;

static const int NUM_NOTES = 12;
static const char* NOTE_FILE_NAMES[] = {"./audio/C.ogg", "./audio/Db.ogg", "./audio/D.ogg", "./audio/Eb.ogg", "./audio/E.ogg", "./audio/F.ogg", "./audio/Gb.ogg", "./audio/G.ogg", "./audio/Ab.ogg", "./audio/A.ogg", "./audio/Bb.ogg", "./audio/B.ogg"};
static const char* PLAYER_SPRITE_NAME = "./images/player.png";
static const char* BACKGROUND_IMAGE_NAME = "./images/plains.jpg";
static const char* INVALID_IMAGE_NAME = "./images/invalid_image.jpg";

class ResourceManager
{

    public:
        ResourceManager(SDL_Renderer* gRenderer);
        void Load();
        void Unload();
        Sound GetNote(int index) { return m_vNotes[index]; }
        vector<Sound> GetAllNotes() { return m_vNotes; }
        Sprite* GetSprite(const char* key)
        {
            Sprite* ret = m_mSprites[key];
            if (!ret)
            {
                ret = m_mSprites["INVALID"];
            }
            return ret;
        }

    private:
        SDL_Renderer* m_gRenderer;  // reference to renderer
        vector<Sound> m_vNotes;
        map<const char*, Sprite*> m_mSprites;
};

#endif 
