// Test for generating rhythms and playing them using CFugue library

#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>

#include "ResourceManager.h"
#include "MusicPlayer.h"
#include "EuclideanRhythm.h"

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
        ResourceManager* m_ResourceManager;
        MusicPlayer* m_MusicPlayer;

};
