// Test for generating rhythms and playing them using CFugue library

#include "Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Empty constructor for compiler
Game::Game()
: m_gWindow(NULL),
  m_gRenderer(NULL),
  m_ResourceManager(NULL),
  m_MusicPlayer(NULL)
{
}

// Game loop
void Game::runGame()
{
    if (!init())
    {
        return;
    }

    bool bQuit = false;
    SDL_Event e;
    float deltaTime = 0;
    float fLastTime = SDL_GetTicks() / 1000.0;

    while (!bQuit)
    {
        // Handle Input
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                bQuit = true;
                printf("Goodbye!\n");
                close();
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch(e.key.keysym.sym)
                {
                    case SDLK_q:
                        bQuit = true;
                        printf("Goodbye!\n");
                        close();
                        break;
                }
            }
        }
        // Update state
        deltaTime = (SDL_GetTicks() / 1000.0) - fLastTime;
        m_MusicPlayer->Run(deltaTime);
        fLastTime = SDL_GetTicks() / 1000.0;

        // Draw
        SDL_SetRenderDrawColor(m_gRenderer,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderClear(m_gRenderer);
        SDL_RenderPresent(m_gRenderer);

    }

}

bool Game::init()
{
    //The window we'll be rendering to
    m_gWindow = NULL;
	
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
    	printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    //Create window
    m_gWindow = SDL_CreateWindow("SDL Music Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if( m_gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    // Init renderer
    m_gRenderer = SDL_CreateRenderer(m_gWindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Init audio
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_mixer could not initialize! Error: " << Mix_GetError() << endl;
    }

    // Load music files
    m_ResourceManager = new ResourceManager();
    m_ResourceManager->Load();

    // Other
    m_MusicPlayer = new MusicPlayer();
    vector<Sound> temp;
    temp.push_back(m_ResourceManager->GetNote(0));
    temp.push_back(m_ResourceManager->GetNote(0));
    temp.push_back(m_ResourceManager->GetNote(0));
    temp.push_back(m_ResourceManager->GetNote(0));
    temp.push_back(m_ResourceManager->GetNote(0));
    temp.push_back(m_ResourceManager->GetNote(0));

    EuclideanRhythm rhythm = EuclideanRhythm(3,8);

    m_MusicPlayer->SetBPM(200);
    m_MusicPlayer->SetNoteBuffer(temp, 6);
    m_MusicPlayer->SetRhythmBuffer(rhythm.GetRhythm(),8);

    return true;
}

void Game::close()
{
    m_gWindow = NULL;
    m_gRenderer = NULL;

    SDL_DestroyRenderer(m_gRenderer);
    SDL_DestroyWindow(m_gWindow);

    Mix_CloseAudio();

    SDL_Quit();

    delete m_ResourceManager;
    delete m_MusicPlayer;
}
