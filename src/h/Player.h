#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

using namespace std;

class Player : public GameObject
{

    public:
        Player(SDL_Renderer* gRenderer, Sprite* sprite, vector<float> pos, vector<float> rot, 
                float maxSpeed, float accelRate) : GameObject(gRenderer, sprite, pos, rot)
        {
            m_fAccelerationRate = accelRate;
            m_fMaxSpeed = maxSpeed;
            m_vCurrVelocity.push_back(0.0);
            m_vCurrVelocity.push_back(0.0);
        }
        void Update(float deltaTime);
        void Draw();
        void HandleEvent(SDL_Event e);

    private:
        float m_fAccelerationRate; //in reference to the horizontal acceleration (vertical is gravity)
        vector<float> m_vCurrVelocity;
        float m_fMaxSpeed;

        bool m_bIsAcceleratingRight;
        bool m_bIsAcceleratingLeft;

};

#endif
