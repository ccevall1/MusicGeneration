#include "Player.h"

void Player::Update(float deltaTime)
{
    m_vPosition[0] += m_vCurrVelocity[0]*deltaTime;
    m_vPosition[1] += m_vCurrVelocity[1]*deltaTime;

    if (m_vPosition[0] < 0)
    {
        m_vPosition[0] = 0;
        m_vCurrVelocity[0] = 0;
    }
    else if (m_vPosition[0] > Constants::SCREEN_WIDTH - m_Sprite->width)
    {
        m_vPosition[0] = Constants::SCREEN_WIDTH - m_Sprite->width;
        m_vCurrVelocity[0] = 0;
    }

    if (m_bIsAcceleratingRight)
    {
        m_vCurrVelocity[0] += m_fAccelerationRate*deltaTime;
        if (m_vCurrVelocity[0] > m_fMaxSpeed) m_vCurrVelocity[0] = m_fMaxSpeed;
    }
    else if (m_bIsAcceleratingLeft)
    {
        m_vCurrVelocity[0] -= m_fAccelerationRate*deltaTime;
        if (m_vCurrVelocity[0] < -1*m_fMaxSpeed) m_vCurrVelocity[0] = -1*m_fMaxSpeed;
    }
    else //deccelerate
    {
        if (m_vCurrVelocity[0] < 0)
        {
            m_vCurrVelocity[0] += m_fAccelerationRate*deltaTime;
            if (m_vCurrVelocity[0] > 0) m_vCurrVelocity[0] = 0;
        }
        else
        {
            m_vCurrVelocity[0] -= m_fAccelerationRate*deltaTime;
            if (m_vCurrVelocity[0] < 0) m_vCurrVelocity[0] = 0;
        }

    }
}

void Player::Draw()
{
    SDL_Rect dimen = {.x = (int)m_vPosition[0], .y = (int)m_vPosition[1], .w = 64, .h = 64};
    SDL_RenderCopy(m_gRenderer, m_Sprite->m_tTexture, NULL, &dimen);
}

void Player::HandleEvent(SDL_Event e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch(e.key.keysym.sym)
        {
            case SDLK_LEFT: case SDLK_a:
                m_bIsAcceleratingRight = false;
                m_bIsAcceleratingLeft = true;
                break;
            case SDLK_RIGHT: case SDLK_d:
                m_bIsAcceleratingRight = true;
                m_bIsAcceleratingLeft = false;
                break;
            default:
                break;
        }
    }
    else if (e.type == SDL_KEYUP)
    {
        m_bIsAcceleratingLeft = false;
        m_bIsAcceleratingRight = false;
    }
}
