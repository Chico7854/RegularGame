#pragma once

namespace Texture {
    enum ID {
        Player1 = 0,
        Player2,
        Youkai, 
        Platform,
        Spike,
        Saw
    };

    #ifdef _WIN32
        constexpr char PLAYER1[] = "images/samurai_run.png";
        constexpr char PLAYER2[] = "images/shinobi_run.png";
        constexpr char YOUKAI[] = "images/youkai_walk.png";
        constexpr char PLATFORM[] = "images/platform.png";
        constexpr char SPIKE[] = "images/spike.png";
        constexpr char SAW[] = "images/saw.png";
    #else
        constexpr char PLAYER1[] = "../images/samurai_run.png";
        constexpr char PLAYER2[] = "../images/shinobi_run.png";
        constexpr char YOUKAI[] = "../images/youkai_walk.png";
        constexpr char PLATFORM[] = "../images/platform.png";
        constexpr char SPIKE[] = "../images/spike.png";
        constexpr char SAW[] = "../images/saw.png";
    #endif
    
}