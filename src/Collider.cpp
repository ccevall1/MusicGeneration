#include "Collider.h"

Collider::Collider(int radius)
: width(-1),
  height(-1)
{
    m_eType = Type::Circle;
    radius = radius;
}

Collider::Collider(int width, int height)
{
    m_eType = Type::Rectangle;

}

bool Collider::CheckCollision(Collider* coll)
{

}
