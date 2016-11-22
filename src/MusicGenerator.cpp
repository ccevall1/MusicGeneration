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

    // Generate rhythm:
    int secondNum = pow(2, (rand() % 2) + 3); // 8 or 16
    int firstNum = 2*((rand() % 3)+1) + 1;
    cout << firstNum << "," << secondNum << endl;
    m_EuclideanRhythm = new EuclideanRhythm(firstNum,secondNum);

    // Generate chords:
    // first chord generated is random
    RomanNumeral eChord = RomanNumeral(rand() % RomanNumeral::END);
    m_Melody.push_back(CreateChord(eChord,0));

    // remaining are based on state machine
    for (int i = 0; i < secondNum-firstNum-1; i++)
    {
        eChord = NextMajorChordProgression(eChord);
        m_Melody.push_back(CreateChord(eChord, 0));
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
/*    for (int i = 0; i < 2; i++)
    {
        chord.push_back(m_NotePool[Constants::RomanNumeralVectors[eChord][i]]);
    }
*/
    //Choose two random notes from the chord to play to vary it up
    chord.push_back(m_NotePool[Constants::RomanNumeralVectors[eChord][rand()%3]]);
    chord.push_back(m_NotePool[Constants::RomanNumeralVectors[eChord][rand()%3]]);

    return chord;
}

MusicGenerator::RomanNumeral MusicGenerator::NextMajorChordProgression(RomanNumeral eChord)
{

    RomanNumeral ret;
    int result;
    switch(eChord)
    {
        case RomanNumeral::I:
            ret = RomanNumeral((rand() % RomanNumeral::END-1) + 1);
            break;
        case RomanNumeral::II:
            result = rand() % 2;
            ret = (result == 0 ? RomanNumeral::VII : RomanNumeral::V);
            break;
        case RomanNumeral::III:
            result = rand() % 2;
            ret = (result == 0 ? RomanNumeral::VI : RomanNumeral::IV);
            break;
        case RomanNumeral::IV:
            result = rand() % 4;
            if (result == 0) ret = RomanNumeral::II;
            else if (result == 1) ret = RomanNumeral::V;
            else if (result == 2) ret = RomanNumeral::VII;
            else if (result == 3) ret = RomanNumeral::I;
            break;
        case RomanNumeral::V:
            result = rand() % 2;
            ret = (result == 0 ? RomanNumeral::I : RomanNumeral::VI);
            break;
        case RomanNumeral::VI:
            result = rand() % 3;
            if (result == 0) ret = RomanNumeral::II;
            else if (result == 1) ret = RomanNumeral::IV;
            else if (result == 2) ret = RomanNumeral::V;
            break;
        case RomanNumeral::VII:
            result = rand() % 2;
            ret = (result == 0 ? RomanNumeral::I : RomanNumeral::V);
            break;
        default:
            ret = RomanNumeral::I;
            break;
    }
    return ret;

}
