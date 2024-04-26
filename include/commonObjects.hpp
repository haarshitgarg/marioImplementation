#ifndef COMMON_OBJECTS_HPP
#define COMMON_OBJECTS_HPP

#define WINDOW_X 2400
#define WINDOW_Y 1200

#define gravityAccel 300     // 5 pixel/sec2

#define ROOT_ASSET_DIR "/Users/harshitgarg/CPP-projects/marioImplementation/assets/"
#define ROOT_MAP_DIR "/Users/harshitgarg/CPP-projects/marioImplementation/maps/"


struct location {
    int x;
    int y;
};

struct ObjectSize {
    int length;
    int breadth;
};

struct Velocity2D {
    float x;
    float y;
};

#endif
