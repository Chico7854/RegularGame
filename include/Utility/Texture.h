//Textures from https://craftpix.net/freebies/free-green-zone-tileset-pixel-art/
//Textures from https://craftpix.net/freebies/free-shinobi-sprites-pixel-art/?num=1&count=1&sq=shinobi&pos=0
//Textures from https://craftpix.net/freebies/free-nature-backgrounds-pixel-art/?num=1&count=187&sq=nature%20background&pos=2
//Textures from https://froggu999.itch.io/stabby-spikes
#pragma once
#include <SFML/Graphics.hpp>

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
        Cannonhead,
        NewDayButton,
        NewNightButton,
        ExitGameButton
    };

    struct Texture {
        ID id;
        sf::Texture* texture;
    };

    constexpr char PLAYER1[] = "../assets/images/samurai_run.png";
    constexpr char PLAYER2[] = "../assets/images/shinobi_run.png";
    constexpr char YOUKAI[] = "../assets/images/youkai_walk.png";
    constexpr char PLATFORM[] = "../assets/images/Tile_10.png";
    constexpr char FLOOR[] = "../assets/images/floor_mine.png";
    constexpr char SPIKE[] = "../assets/images/spike.png";
    constexpr char SAW[] = "../assets/images/saw.png";
    constexpr char BACKGROUND_DAY_MOUNTAIN[] = "../assets/images/bgsimao.png";
    constexpr char BACKGROUND_NIGHT_MOUNTAIN[] = "../assets/images/night_mountain.png";
    constexpr char BALL[] = "../assets/images/ball.png";
    constexpr char CANNONHEAD[] = "../assets/images/cannonhead_walk.png";
    constexpr char NEW_DAY[] = "../assets/images/daystage.png";
    constexpr char NEW_NIGHT[] = "../assets/images/nightstage.png";
    constexpr char EXIT_GAME[] = "../assets/images/exitgame.png";
}