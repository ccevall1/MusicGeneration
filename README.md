# MusicGeneration

A simple test of some ideas for pseudo-randomly generated music.
Long term goals is dynamically generated to respond to messages
from a game or similar program.
Currently implemented:
    1) Euclidean Rhythm algorithm to generate a beat consisting of an odd
       number of pulses and either 8 or 16 beats
    2) MusicGenerator class currently selects random notes from the ResourceManager's
       scale and MusicPlayer plays these notes sequentially on each pulse

TODO:
    1) Chord structure of some sort to store notes to be played together (contains 3 Sound objects)
    2) Map which stores chords belonging to a key to choose from
        --Use Roman Numeral notation as the key and a vector of Sounds as the value
    3) Dynamically alter the BPM value based on "Player speed"
        --For now no real game, but can simulate acceleration and deceleration easily
    4) Check for memory leaks and optimize because VirtualBox is not super happy with this
    5) Chord progressions, maybe implement some kind of state machine or grammar to choose next
       chord based on existing known patterns (ie Circle progressions)

Roman Numeral Notation:
    I       0,2,4
    II      1,3,5
    III     2,4,6
    IV      0,3,5
    V       1,4,6
    VI      0,2,5
    VII     1,3,6
