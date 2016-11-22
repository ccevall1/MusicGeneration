#include "EuclideanRhythm.h"

using namespace std;

EuclideanRhythm::EuclideanRhythm(int firstNum, int secondNum)
: m_nBeatCounter(0),
  m_nRhythmLength(0)
{
    m_vRemainder.push_back(firstNum);
    int rem = secondNum - firstNum;
    int count = 0;

    while (m_vRemainder.back() != 0) {
        int newRem = m_vRemainder.back();
        m_vMultiple.push_back(rem / m_vRemainder.back());
        m_vRemainder.push_back(rem % m_vRemainder.back());
        rem = newRem;
        count++;
    }
    m_vRemainder.pop_back(); // edge case where we appended 0
    recBuildRhythm(count-1);
 
}

void EuclideanRhythm::recBuildRhythm(int it)
{
    if (it == -1)
    {
        m_vRhythm.push_back(1);
        m_nRhythmLength++;
    }
    else if (it == -2)
    {
        m_vRhythm.push_back(0);
        m_nRhythmLength++;
    }
    else
    {
        for (int i = 0; i < m_vMultiple[it]; i++)
        {
            recBuildRhythm(it-1);
        }
        if (m_vRemainder[it] != 0)
        {
            recBuildRhythm(it-2);
        }
    }
}
