#pragma once

namespace Constants {
    constexpr unsigned int WINDOW_HEIGHT = 640;//probably is better to change for something divisible by 16 or 32
    constexpr unsigned int WINDOW_WIDTH = 1088;
    constexpr unsigned int FLOOR_HEIGHT = 608;

    constexpr int SCALE_TXT = 32;

    /*Textures and sprites sizes*/
    constexpr unsigned int P1_HEIGHT = 104;
    constexpr unsigned int P1_WIDTH = 73;
    constexpr unsigned int P2_HEIGHT = 82;
    constexpr unsigned int P2_WIDTH = 80;
    constexpr unsigned int YOUKAI_HEIGHT = 75;
    constexpr unsigned int YOUKAI_WIDTH = 52;
    constexpr unsigned int PLATFORM_WIDTH = 32;
    constexpr unsigned int PLATFORM_HEIGHT = 32;
    constexpr unsigned int SPIKE_WIDTH = 25;
    constexpr unsigned int SPIKE_HEIGHT = 17;
    constexpr unsigned int SAW_WIDTH = 96;
    constexpr unsigned int SAW_HEIGHT = 66;
    constexpr unsigned int BALL_WIDTH = 15;
    constexpr unsigned int BALL_HEIGHT = 15;
    constexpr unsigned int FLOOR_SPRITE_WIDTH = 1000;
    constexpr unsigned int FLOOR_SPRITE_HEIGHT = 50;
    constexpr unsigned int FLOOR_SPRITE_SCALE = 5;
    constexpr unsigned int CANNONHEAD_WIDTH = 70;
    constexpr unsigned int CANNONHEAD_HEIGHT = 50;
    constexpr unsigned int BACKGROUND_NIGHT_WIDTH = 2304;
    constexpr unsigned int BACKGROUND_NIGHT_HEIGHT = 1296;

    constexpr float SPEED = 7.f;
    constexpr float GRAVITY = SPEED / 4.f;
    constexpr float JUMP_SPEED = SPEED * -4.f;
    constexpr float BALL_SPEED = SPEED * 2.f;

    constexpr float BUTTON_HEIGHT = 32.f;
    constexpr float BUTTON_WIDTH = 256.f;

    constexpr char GAME_NAME[] = "Regular Game";
}