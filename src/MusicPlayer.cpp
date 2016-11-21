#include <iostream>
#include "MusicPlayer.h"
#include "Static.h"

MusicPlayer::MusicPlayer()
: m_fSecondsPerBeat(.3),
  m_fTimeStepBuffer(0),
  m_nNoteBufferIndex(0),
  m_nRhythmBufferIndex(0),
  m_nNumNotes(0),
  m_nNumBeats(0)
{}

void MusicPlayer::Run(float deltaTime)
{
    m_fTimeStepBuffer += deltaTime;
    if (m_fTimeStepBuffer > m_fSecondsPerBeat)
    {
        m_nRhythmBufferIndex = (m_nRhythmBufferIndex + 1) % m_nNumBeats;
        if (m_RhythmBuffer[m_nRhythmBufferIndex] == 1)
        {
            m_nNoteBufferIndex = (m_nNoteBufferIndex + 1) % m_nNumNotes;
            m_NoteBuffer[m_nNoteBufferIndex].PlaySound();
        }
        m_fTimeStepBuffer = 0;
    }
}

void MusicPlayer::SetBPM(int bpm)
{
    m_fSecondsPerBeat = 60.0 / (float) bpm;
}

void MusicPlayer::SetNoteBuffer(vector<Sound> buffer, int size)
{
    m_NoteBuffer.clear();
    m_NoteBuffer = buffer;
    m_nNumNotes = size;
}

void MusicPlayer::SetRhythmBuffer(vector<int> buffer, int size)
{
    m_RhythmBuffer.clear();
    m_RhythmBuffer = buffer;
    m_nNumBeats = size;
    Static::PrintVector(m_RhythmBuffer);
}
