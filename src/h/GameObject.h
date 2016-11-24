#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include <vector>
#include <algorithm>

#include "Constants.h"

class GameObject
{

    public:
        GameObject(SDL_Renderer* gRenderer, Sprite* sprite, std::vector<float> pos, std::vector<float> rot)
        : m_gRenderer(NULL), m_Sprite(NULL), m_vPosition(pos), m_vOrientation(rot)
        {
            if (sprite)
                m_Sprite = sprite;
            if (gRenderer)
                m_gRenderer = gRenderer;
        }
        virtual void Update(float deltaTime) = 0;
        virtual void Draw() = 0;
        virtual void HandleEvent(SDL_Event e) = 0;

    protected:
        SDL_Renderer* m_gRenderer;
        Sprite* m_Sprite;
        std::vector<float> m_vPosition;
        std::vector<float> m_vOrientation;

};

#endif
