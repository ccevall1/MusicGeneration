#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>

namespace Constants
{

    typedef std::vector<Sound> Chord;
    typedef std::vector<Chord> Melody;
    // Arrays of ints which store indices of notes in ResourceManager::m_vNotes
    // Correspond to different musical keys
    /*
     * C  = 0
     * C# = 1
     * D  = 2
     * Eb = 3
     * E  = 4
     * F  = 5
     * F# = 6
     * G  = 7
     * Ab = 8
     * A  = 9
     * Bb = 10
     * B  = 11
     */
/*    const int C_MAJOR[] = {0, 2, 4, 5, 7, 9, 11};
    const int C_HARMONIC_MINOR[] = {0, 2, 3, 5, 7, 8, 11};
    const int C_NATURAL_MINOR[] = {0, 2, 3, 5, 7, 8, 10};
    const int C_MELODIC_MINOR[] = {0, 2, 3, 5, 7, 9, 11};
*/
    // Roman Numeral Notation array
    const int RomanNumeralVectors[7][3] = { {0,2,4},
                                            {1,3,5},
                                            {2,4,6},
                                            {0,3,5},
                                            {1,4,6},
                                            {0,2,5},
                                            {1,3,6}
                                        };

}

#endif
