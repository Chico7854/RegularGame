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
        Background,
        Shuriken
    };
        constexpr char PLAYER1[] = "../images/samurai_run.png";
        constexpr char PLAYER2[] = "../images/shinobi_run.png";
        constexpr char YOUKAI[] = "../images/youkai_walk.png";
        constexpr char PLATFORM[] = "../images/platform.png";
        constexpr char FLOOR[] = "../images/floor_mine.png";
        constexpr char SPIKE[] = "../images/spike.png";
        constexpr char SAW[] = "../images/saw.png";
        constexpr char BACKGROUND[] = "../images/bgsimao.png";
        constexpr char SHURIKEN[] = "../images/shuriken.png";
}