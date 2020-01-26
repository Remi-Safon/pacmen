#include "environment.h"

BoxState BOARDS [NB_BOARDS][BOARD_Y][BOARD_X] = {
    {
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL },
        { BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE },
        { BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE },
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL },
        { BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE },
        { BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE },
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL },
        { BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE },
        { BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE },
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL },
        { BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE },
        { BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::FREE },
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL },
        { BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL }
    },
    {
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL, BoxState::WALL, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::FREE, BoxState::WALL },
        { BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL, BoxState::WALL }
    }
};

QRgb rgbWall [5][5] = {
    {qRgb(0,0,255),qRgb(0,0,255),qRgb(0,0,255),qRgb(0,0,255),qRgb(0,0,255)},
    {qRgb(0,0,255),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,255)},
    {qRgb(0,0,255),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,255)},
    {qRgb(0,0,255),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,255)},
    {qRgb(0,0,255),qRgb(0,0,255),qRgb(0,0,255),qRgb(0,0,255),qRgb(0,0,255)}
};

QRgb rgbEnemy [2][5][5] = {
    {
        {qRgb(0,0,1),qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0),qRgb(0,0,1)},
        {qRgb(255,0,0),qRgb(255,0,0),qRgb(255,255,255),qRgb(255,0,0),qRgb(255,255,255)},
        {qRgb(255,0,0),qRgb(255,0,0),qRgb(255,255,255),qRgb(255,0,0),qRgb(255,255,255)},
        {qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0)},
        {qRgb(255,0,0),qRgb(0,0,1),qRgb(255,0,0),qRgb(0,0,1),qRgb(255,0,0)}
    },
    {
        {qRgb(0,0,1),qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0),qRgb(0,0,1)},
        {qRgb(255,0,0),qRgb(255,255,255),qRgb(255,0,0),qRgb(255,255,255),qRgb(255,0,0)},
        {qRgb(255,0,0),qRgb(255,255,255),qRgb(255,0,0),qRgb(255,255,255),qRgb(255,0,0)},
        {qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0),qRgb(255,0,0)},
        {qRgb(255,0,0),qRgb(0,0,1),qRgb(255,0,0),qRgb(0,0,1),qRgb(255,0,0)}
    }
};

QRgb rgbPlayer [2][5][5] = {
    {
        {qRgb(0,0,1),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(0,0,1)},
        {qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0)},
        {qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0)},
        {qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0)},
        {qRgb(0,0,1),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(0,0,1)}
    },
    {
        {qRgb(0,0,1),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(0,0,1)},
        {qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0)},
        {qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(0,0,1),qRgb(0,0,1)},
        {qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0)},
        {qRgb(0,0,1),qRgb(255,255,0),qRgb(255,255,0),qRgb(255,255,0),qRgb(0,0,1)}
    }
};

QRgb rgbGold [5][5] = {
    {qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,0,1),qRgb(255,255,0),qRgb(0,0,1),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1)}
};

QRgb rgbFood [5][5] = {
    {qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,255,0),qRgb(0,255,0),qRgb(0,255,0),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,255,0),qRgb(0,255,0),qRgb(0,255,0),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,255,0),qRgb(0,255,0),qRgb(0,255,0),qRgb(0,0,1)},
    {qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1),qRgb(0,0,1)}
};

Environment::Environment()
{
    // initialization of the board
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    this->indexBoard = rand() % NB_BOARDS;
    this->boardSizeX = BOARD_X;
    this->boardSizeY = BOARD_Y;
    // this->indexBoard = 0;
    this->init();
}

void Environment::init()
{
    for (int y = 0; y < BOARD_Y; y++) {
        for (int x = 0; x < BOARD_X; x++) {
            //change 1st index to indexBoard for random map
            this->board[y][x] = BOARDS [this->indexBoard][y][x];
        }
    }
}

void Environment::setStateBox(int x, int y, BoxState state)
{
    this->board[y][x] = state;
}

BoxState Environment::getBoxState(int x, int y)
{
    return this->board[y][x];
}

QImage Environment::display()
{
    QImage image( BOARD_X*5, BOARD_Y*5, QImage::Format_RGB32 );

    for (int y = 0; y < BOARD_Y; y++) {
        for (int x = 0; x < BOARD_X; x++) {
            QRgb argb = qRgb(1,0,0);
            //1PX -> 5/5PX
            switch (this->board[y][x]) {
                case BoxState::FREE:
                    //argb = qRgb(0,0,0);
                    for(int n = 0;n < 5; n++){
                        for(int m = 0;m < 5; m++){
                            argb = qRgb(0,0,0);
                            image.setPixel(x*5+m,y*5+n,argb);
                        }
                    }

                    break;
                case BoxState::WALL:                   
                    for(int n = 0;n < 5; n++){
                        for(int m = 0;m < 5; m++){
                            argb = rgbWall[n][m];
                            image.setPixel(x*5+m,y*5+n,argb);
                        }
                    }
                    break;
                case BoxState::PLAYER:
                    for(int n = 0;n < 5; n++){
                        for(int m = 0;m < 5; m++){
                            argb = rgbPlayer[animIndex][n][m];
                            image.setPixel(x*5+m,y*5+n,argb);
                        }
                    }
                    break;
                case BoxState::ENEMY:
                    for(int n = 0;n < 5; n++){
                        for(int m = 0;m < 5; m++){
                            argb = rgbEnemy[animIndex][n][m];
                            image.setPixel(x*5+m,y*5+n,argb);
                        }
                    }
                    break;
                case BoxState::FOOD:
                    for(int n = 0;n < 5; n++){
                        for(int m = 0;m < 5; m++){
                            argb = rgbFood[n][m];
                            image.setPixel(x*5+m,y*5+n,argb);
                        }
                    }
                    break;
                case BoxState::GOLD:
                    for(int n = 0;n < 5; n++){
                        for(int m = 0;m < 5; m++){
                            argb = rgbGold[n][m];
                            image.setPixel(x*5+m,y*5+n,argb);
                        }
                    }
                    break;
            }
            //image.setPixel(x,y,argb);
        }
    }
    /*for(int i = 0; i < BOARD_X; i++){
        for(int n = 0; n < BOARD_Y; n++){
            qDebug () << image.pixel(i,n);
        }
    }*/

   // QImage::save ( const QString & fileName, const char * format = 0, int quality = -1 )
    if(animIndex == 0){
        animIndex = 1;
    } else {
        animIndex = 0;
    }

    return image;
}

string Environment::toString()
{
    ostringstream ss;

    for (int y = 0; y < BOARD_Y; y++) {
        for (int x = 0; x < BOARD_X; x++) {
            ss << " " << ((int)this->board[y][x]);
        }
        ss << endl;
    }

    return ss.str();
}
