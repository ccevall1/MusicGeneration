// Test for generating rhythms and playing them using CFugue library

#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>

#include "MusicGenerator.h"
#include "MusicPlayer.h"
#include "ResourceManager.h"

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
        ResourceManager* m_ResourceManager;

};
