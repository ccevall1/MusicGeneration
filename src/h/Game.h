// Test for generating rhythms and playing them using CFugue library

#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

#include "MusicGenerator.h"
#include "MusicPlayer.h"
#include "ResourceManager.h"
#include "Player.h"

class Game
{
    public:
        Game();
        bool init();
        bool loadMedia();
        void close();
        void runGame();

    private:
        SDL_Window* m_gWindow;
        SDL_Renderer* m_gRenderer;

        MusicGenerator* m_MusicGenerator;
        MusicPlayer* m_MusicPlayer;

        Player* m_Player;

        ResourceManager* m_ResourceManager;

};
