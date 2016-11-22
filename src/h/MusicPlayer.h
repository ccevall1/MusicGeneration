// Class to handle playing melodies given note buffer, bpm, and timestep
// Will have a reference to the music generator class so it can request new notes

#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "Sound.h"
#include <vector>
#include "Constants.h"

using namespace std;
using namespace Constants;

class MusicPlayer
{

    public:
        MusicPlayer();
        void Run(float deltaTime);
        void SetNoteBuffer(vector<Chord> buffer, int size);
        void SetRhythmBuffer(vector<int> buffer, int size);
        void SetBPM(int bpm);

    private:
        vector<Chord> m_NoteBuffer;
        vector<int> m_RhythmBuffer;
        float m_fSecondsPerBeat;  // easier to handle logically, computed from BPM
        float m_fTimeStepBuffer;
        int   m_nNoteBufferIndex;
        int   m_nRhythmBufferIndex;
        int   m_nNumNotes;
        int   m_nNumBeats;
};

#endif
