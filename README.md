# MusicGeneration

A simple test of some ideas for pseudo-randomly generated music.
Long term goals is dynamically generated to respond to messages
from a game or similar program.
DONE:
    * Euclidean Rhythm algorithm to generate a beat consisting of an odd
       number of pulses and either 8 or 16 beats
    * MusicGenerator class currently selects random notes from the ResourceManager's
       scale and MusicPlayer plays these notes sequentially on each pulse
    * Generate two-note chords (3-note possible but VM seems to struggle) using state machine
        to randomly determine which chord to transition to next

TODO:
    * Map which stores chords belonging to a key to choose from
        --Use Roman Numeral notation as the key and a vector of Sounds as the value
    * Dynamically alter the BPM value based on "Player speed"
        --For now no real game, but can simulate acceleration and deceleration easily
    * Check for memory leaks and optimize because VirtualBox is not super happy with this

OTHER:

Note Indices- C = 0, C# = 1, D = 2, Eb = 3, E = 4, F = 5, F# = 6, G = 7, Ab = 8, A = 9, Bb = 10, B = 11
Roman Numeral Notation:
Number      Whole notes     Index Equiv
    I       0,2,4           0,4,7       0,4,7
    ii      1,3,5           2,5,9       2,5,9
    iii     2,4,6           4,7,11      4,7,11
    IV      0,3,5           5,9,0       0,5,9
    v       1,4,6           7,11,4      4,7,11
    vi      0,2,5           9,0,4       0,4,9
    viio    1,3,6           11,2,5      2,5,11

Common Chord Progressions:

iii --> vi --> ii/IV --> V/viio --> I
^                         |
|-------------------------|

Circle-
I --> IV --> viio --> iii --> vi --> ii --> V
^                                           |
|-------------------------------------------|

