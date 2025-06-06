#pragma once

namespace Texture {
    enum ID {
        Player1 = 0,
        Player2,
        Youkai, 
        Platform,
        Floor,
        Spike,
        Saw,
        BackgroundDayMountain,
        BackgroundNightMountain,
        Ball,
        Cannonhead
    };
        constexpr char PLAYER1[] = "../assets/images/samurai_run.png";
        constexpr char PLAYER2[] = "../assets/images/shinobi_run.png";
        constexpr char YOUKAI[] = "../assets/images/youkai_walk.png";
        constexpr char PLATFORM[] = "../assets/images/platform.png";
        constexpr char FLOOR[] = "../assets/images/floor_mine.png";
        constexpr char SPIKE[] = "../assets/images/spike.png";
        constexpr char SAW[] = "../assets/images/saw.png";
        constexpr char BACKGROUND_DAY_MOUNTAIN[] = "../assets/images/bgsimao.png";
        constexpr char BACKGROUND_NIGHT_MOUNTAIN[] = "../assets/images/night_mountain.png";
        constexpr char BALL[] = "../assets/images/ball.png";
        constexpr char CANNONHEAD[] = "../assets/images/cannonhead_walk.png";
}