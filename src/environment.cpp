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


Environment::Environment()
{
    // initialization of the board
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    // this->indexBoard = rand() % NB_BOARDS;
    this->indexBoard = 0;
    this->init();

}
void Environment::init() {
    for (int y = 0; y < BOARD_Y; y++) {
        for (int x = 0; x < BOARD_X; x++) {
                //change 1st index to indexBoard for random map
               this->board[y][x] = BOARDS [this->indexBoard][y][x];
        }
    }
}


void Environment::setStateBox(int x, int y, BoxState state) {
    this->board[y][x] = state;
}
BoxState Environment::getBoxState(int x, int y) {
    return this->board[y][x];
}

QImage Environment::display(){
    qDebug () << "Display Map Here" << endl;

    QImage image( BOARD_X, BOARD_Y, QImage::Format_RGB32 );

    for (int y = 0; y < BOARD_Y; y++) {
        for (int x = 0; x < BOARD_X; x++) {
            QRgb argb = qRgb(1,0,0);
            //1PX -> 5/5PX
            switch (this->board[y][x]) {
                case BoxState::FREE:
                    argb = qRgb(0,0,0);
                    break;
                case BoxState::WALL:
                    argb = qRgb(0,0,255);
                    break;
                case BoxState::PLAYER:
                    argb = qRgb(0,255,0);
                    break;
                case BoxState::ENEMY:
                    argb = qRgb(255,0,0);
                    break;
                case BoxState::FOOD:
                    argb = qRgb(1,0,0);
                    break;
            }
            image.setPixel(x,y,argb);
        }
    }
    /*for(int i = 0; i < BOARD_X; i++){
        for(int n = 0; n < BOARD_Y; n++){
            qDebug () << image.pixel(i,n);
        }
    }*/

   // QImage::save ( const QString & fileName, const char * format = 0, int quality = -1 )
    return image;
}

string Environment::toString() {
    ostringstream ss;

    for (int y = 0; y < BOARD_Y; y++) {
        for (int x = 0; x < BOARD_X; x++) {
            ss << " " << ((int)this->board[y][x]);
        }
        ss << endl;
    }

    return ss.str();
}
