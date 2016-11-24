// Test for generating rhythms and playing them using CFugue library

#include "Game.h"
#include "Constants.h"


// Empty constructor for compiler
Game::Game()
: m_gWindow(NULL),
  m_gRenderer(NULL),
  m_MusicGenerator(NULL),
  m_MusicPlayer(NULL),
  m_Player(NULL),
  m_ResourceManager(NULL)
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
    bool bPlay = false;

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
                        cout << "Goodbye!" << endl;
                        bQuit = true;
                        close();
                        break;
                    case SDLK_p:
                        cout << "Setting bPlay to " << bPlay << endl;
                        bPlay = !bPlay;
                        break;
                    case SDLK_n:
                        cout << "Generating new melody" << endl;
                        m_MusicGenerator->GenerateMusic();
                        m_MusicPlayer->SetRhythmBuffer(m_MusicGenerator->GetRhythm()->GetRhythm(), m_MusicGenerator->GetRhythm()->GetLength());
                        m_MusicPlayer->SetNoteBuffer(m_MusicGenerator->GetMelody(), m_MusicGenerator->GetMelodyLength());
                        break;
                }
            }
            m_Player->HandleEvent(e);
        }
        // Update state
        deltaTime = (SDL_GetTicks() / 1000.0) - fLastTime;

        if (bPlay)
            m_MusicPlayer->Run(deltaTime);
        m_Player->Update(deltaTime);

        fLastTime = SDL_GetTicks() / 1000.0;

        // Draw
        SDL_SetRenderDrawColor(m_gRenderer,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderClear(m_gRenderer);

        //BG
        SDL_RenderCopy(m_gRenderer, m_ResourceManager->GetSprite("BACKGROUND_SPRITE")->m_tTexture, NULL, NULL);

        m_Player->Draw();

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
    m_gWindow = SDL_CreateWindow("SDL Music Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,Constants::SCREEN_WIDTH,Constants::SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
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
    m_ResourceManager = new ResourceManager(m_gRenderer);
    m_ResourceManager->Load();

    // Other
    m_MusicPlayer = new MusicPlayer();
    m_MusicGenerator = new MusicGenerator(m_ResourceManager->GetAllNotes());

    m_MusicGenerator->GenerateMusic();

    m_MusicPlayer->SetBPM(200);
    m_MusicPlayer->SetNoteBuffer(m_MusicGenerator->GetMelody(), m_MusicGenerator->GetMelodyLength());
    m_MusicPlayer->SetRhythmBuffer(m_MusicGenerator->GetRhythm()->GetRhythm(),m_MusicGenerator->GetRhythm()->GetLength());

    // Initialize Player
    vector<float> vInitPosition = {0,Constants::SCREEN_HEIGHT-64};
    vector<float> vInitRotation = {0,0};
    m_Player = new Player(m_gRenderer, m_ResourceManager->GetSprite("PLAYER_SPRITE"), vInitPosition, vInitRotation, Constants::PLAYER_SPEED, Constants::PLAYER_ACCEL);

    return true;
}

void Game::close()
{
    m_gWindow = NULL;
    m_gRenderer = NULL;

    SDL_DestroyRenderer(m_gRenderer);
    SDL_DestroyWindow(m_gWindow);

    Mix_CloseAudio();

    IMG_Quit();
    SDL_Quit();

    delete m_ResourceManager;
    delete m_MusicPlayer;
    delete m_MusicGenerator;
}
