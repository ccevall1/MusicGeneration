#include "MusicGenerator.h"
#include "ResourceManager.h"

MusicGenerator::MusicGenerator(vector<Sound> notePool)
: m_EuclideanRhythm(NULL),
  m_nMelodyLength(0)
{
    m_NotePool = notePool;
}

void MusicGenerator::GenerateMusic()
{
    if (m_EuclideanRhythm)
        delete m_EuclideanRhythm;
    m_Melody.clear();

    int secondNum = pow(2, (rand() % 2) + 3); // 8 or 16
    int firstNum = 2*((rand() % 3)+1) + 1;
    cout << firstNum << "," << secondNum << endl;
    m_EuclideanRhythm = new EuclideanRhythm(firstNum,secondNum);

    for (int i = 0; i < secondNum-firstNum; i++)
    {
        RomanNumeral eChoice = RomanNumeral(rand() % RomanNumeral::END);
        m_Melody.push_back(CreateChord(eChoice, 0));
    }

    m_nMelodyLength = secondNum - firstNum;
}

void MusicGenerator::Cleanup()
{
    delete m_EuclideanRhythm;
    m_Melody.clear();
}

Chord MusicGenerator::CreateChord(RomanNumeral eChord, int nBaseNoteIndex)
{
    // For now let's just do C major because other keys are hard
    Chord chord;
    for (int i = 0; i < 2; i++)
    {
        chord.push_back(m_NotePool[Constants::RomanNumeralVectors[eChord][i]]);
    }
    Static::PrintVector(chord);
    return chord;
}
