#pragma once

namespace Constants {
    enum TYPE {
        None = 0,

        Player,
        Enemy,
        Obstacle
    };

    constexpr unsigned int WINDOW_HEIGHT = 650;
    constexpr unsigned int WINDOW_WIDTH = 1100;
    constexpr unsigned int FLOOR_HEIGHT = 600;

    /*Textures and sprites sizes*/
    constexpr unsigned int P1_HEIGHT = 104;
    constexpr unsigned int P1_WIDTH = 73;
    constexpr unsigned int P2_HEIGHT = 82;
    constexpr unsigned int P2_WIDTH = 80;
    constexpr unsigned int YOUKAI_HEIGHT = 75;
    constexpr unsigned int YOUKAI_WIDTH = 52;
    constexpr unsigned int PLATFORM_WIDTH = 86;
    constexpr unsigned int PLATFORM_HEIGHT = 24;
    constexpr unsigned int SPIKE_WIDTH = 25;
    constexpr unsigned int SPIKE_HEIGHT = 17;
    constexpr unsigned int SAW_WIDTH = 96;
    constexpr unsigned int SAW_HEIGHT = 66;

    constexpr float SPEED = 7.f;
    constexpr float GRAVITY = SPEED / 4.f;
    constexpr float JUMP_SPEED = SPEED * -4;

    constexpr char GAME_NAME[] = "PUTA";
}