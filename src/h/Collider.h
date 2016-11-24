#ifndef COLLIDER_H
#define COLLIDER_H

class Collider
{

    enum Type {Circle, Rectangle};
    public:
        Collider(int radius);
        Collider(int width, int height);
        bool CheckCollision(Collider* coll);
        Type GetType() { return m_eType; }

    private:
        Type m_eType;
        int radius, width, height;

};

#endif
