#ifndef EUCLIDEAN_RHYTHM_H
#define EUCLIDEAN_RHYTHM_H

#include <iostream>
#include <vector>

using namespace std;

class EuclideanRhythm
{
    public:
        EuclideanRhythm(int firstNum, int secondNum);

        template <typename T>
        void printVector(vector<T> v)
        {
            for (T t : v)
            {
                cout << t << " ";
            }
            cout << endl;
        }

        void printRhythm()
        {
            printVector(m_vRhythm);
        }

        vector<int> GetRhythm()
        {
            return m_vRhythm;
        }

        int GetLength()
        {
            return m_nRhythmLength;
        }


    private:
        int m_nBeatCounter;
        int m_nRhythmLength;
        vector<int> m_vRhythm;
        vector<int> m_vRemainder;
        vector<int> m_vMultiple;

        void recBuildRhythm(int it);
};

#endif
