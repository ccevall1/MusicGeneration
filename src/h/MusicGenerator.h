#ifndef MUSIC_GENERATOR_H
#define MUSIC_GENERATOR_H

#include <stdlib.h>

#include "EuclideanRhythm.h"
#include "Sound.h"
#include "Static.h"
#include "Constants.h"

using namespace Constants;

class MusicGenerator
{

    public:
        enum RomanNumeral {I, II, III, IV, V, VI, VII, END};

        MusicGenerator(vector<Sound> noteBuffer);
        void Cleanup();
        void GenerateMusic();
        Chord CreateChord(MusicGenerator::RomanNumeral eChord, int nBaseNoteIndex);
        //TODO: add parameters for tweaking values
        EuclideanRhythm* GetRhythm() { return m_EuclideanRhythm; }
        Melody GetMelody() { return m_Melody; }
        int GetMelodyLength() { return m_nMelodyLength; }

    private:
        vector<Sound> m_NotePool;
        EuclideanRhythm* m_EuclideanRhythm;
        Melody m_Melody;
        
        int m_nMelodyLength;

};

#endif
