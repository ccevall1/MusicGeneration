OBJS = \
    Game.cpp \
    EuclideanRhythm.cpp \
    MusicGenerator.cpp \
    MusicPlayer.cpp \
    ResourceManager.cpp \
    Sound.cpp \


#CFLAGS += -g -std=c++11 -Wall -Wextra -Wpedantic -O2 `pkg-config --cflags sdl2 SDL2_image SDL2_mixer SDL2_ttf`
CFLAGS += -g -std=c++11 -O2 `pkg-config --cflags sdl2 SDL2_image SDL2_mixer SDL2_ttf`
CXXFLAGS += $(CFLAGS)
LDLIBS = `pkg-config --libs sdl2 SDL2_image SDL2_mixer SDL2_ttf`
INCLUDE = -Ih

all: game

game:  $(OBJS)
	$(CXX) $(CFLAGS) -o game main.cpp  $(OBJS) $(LDLIBS) $(INCLUDE)

clean:
	rm -f *.o game
