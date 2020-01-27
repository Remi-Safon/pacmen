#include "gamemanager.h"
#include "button.h"
#include "boardservice.h"

GameManager::GameManager(QWidget* parent)
{
    std::srand(std::time(nullptr));
    isPlaying = false;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,900);

    //Load all scenes
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::black);
    scene->setSceneRect(0,0,800,900);

    sceneGame = new QGraphicsScene();
    sceneGame->setBackgroundBrush(Qt::black);
    sceneGame->setSceneRect(0,0,800,900);

    scenePause = new QGraphicsScene();
    scenePause->setBackgroundBrush(Qt::black);
    scenePause->setSceneRect(0,0,800,900);

    sceneEnd = new QGraphicsScene();
    sceneEnd->setBackgroundBrush(Qt::black);
    sceneEnd->setSceneRect(0,0,800,900);

    i = 1;

    setScene(scene);

    show();
}

void GameManager::newGame(){
    sceneGame->clear();
    //When start

    setScene(sceneGame);
    show();

    hudLoad();

    //Load player and enemies

    characters.clear();
    // items.clear();
    BoardService::resetInstance();
    environment = BoardService::getInstance();

    player = new Player(3, 19);
    ghost1 = new Puller(9, 10);
    ghost2 = new Puller(10, 10);
    ghost3 = new Puller(8, 15);
    ghost4 = new Ghost(5, 5);

    characters.push_back(this->player);
    characters.push_back(this->ghost1);
    characters.push_back(this->ghost2);
    characters.push_back(this->ghost3);
    characters.push_back(this->ghost4);

    framesBoost = 0;

    isPlaying = true;

    initItems();

    changeLivesHUD();
    changeScoreHUD();
    environmentUI();

    // std::thread t(&GameManager::testThread, this);

    gameLoop();
    // t.join();

}
/*
void GameManager::run() {
    gameLoop();
}
*/
void GameManager::gameLoop() {


    while (!this->gameOver()) {
        if(isPlaying){
            this->environment->init();
            displayItems();
            for (std::list<Character*>::iterator it = this->characters.begin(); it != characters.end(); ++it) {
                (*it)->move();
            }
            hitItems();
            checkCollision();
            changeLivesHUD();
            changeScoreHUD();
            environmentUI();

            if(framesBoost != 0){
                framesBoost --;
                ghostEaterText->setPlainText(QString("GHOST EATER : ") + QString::number(framesBoost));
                this->player->canEatGhost(true);
            } else {
                this->player->canEatGhost(false);
                ghostEaterText->setPlainText(QString(""));
            }

            Sleep(150);
        }
        QApplication::processEvents();
        //qDebug () << this->player->isAlive() << endl;

    }


    setScene(this->sceneEnd);
    endMenuDisplay(this->player->isAlive());
}

void GameManager::checkCollision() {
    Character* eatedGhost = 0;
    for (std::list<Character*>::iterator it = this->characters.begin(); it != characters.end(); ++it) {
        if (this->player->isCollision(*it)) {
            if (player->ghostEater) {
                eatedGhost = *it;
            } else {
                this->player->loseLive();
                (*it)->isTouch = 10;
            }
        }
    }
    if (eatedGhost != 0) {
        this->characters.remove(eatedGhost);
        this->player->canEatGhost(false);
    }

}

bool GameManager::gameOver () {
    /*if(!this->player->isAlive()){
        return false;
    } else if (this->goldRemaining()) {
        return false;
    } else {
        return true;
    }*/
    return !this->player->isAlive();
    //return (this->player->isAlive() || this->goldRemaining() ? false : true);
}

void GameManager::quitGame()
{
    QCoreApplication::quit();
}

void GameManager::pauseGame()
{
    changeLivesHUD();
    setScene(scenePause);

    isPlaying = false;

    show();

    pauseMenuDisplay();
}

void GameManager::resumeGame()
{
    isPlaying = true;
    setScene(sceneGame);
    show();
}

void GameManager::goMainMenu()
{
    isPlaying = false;

    setScene(scene);
    show();
    mainMenuDisplay();
}

void GameManager::changeScoreHUD(){
    scoreText->setPlainText(QString("SCORE: ")+QString::number(this->player->nbGold));
}

void GameManager::changeLivesHUD(){
    livesText->setPlainText(QString("LIVES: ")+QString::number(player->getLives()));
}

void GameManager::hudLoad()
{
    //PAUSE BTN
    Button* pauseButton = new Button(QString("Pause"));
    pauseButton->setPos(20,20);
    connect(pauseButton,SIGNAL(clicked()),this,SLOT(pauseGame()));
    sceneGame->addItem(pauseButton);

    //PLAYER SCORE
    scoreText = new QGraphicsTextItem(QString("SCORE: 0"));
    int txPos = this->width()/2 - scoreText->boundingRect().width()/2;
    int tyPos = 20;
    scoreText->setPos(5,650);
    scoreText->setFont(*new QFont("Times", 18, QFont::Bold));
    scoreText->setDefaultTextColor(Qt::white);
    sceneGame->addItem(scoreText);

    //PLAYER LIVES
    ghostEaterText = new QGraphicsTextItem(QString(""));
    ghostEaterText->setPos(5,750);
    ghostEaterText->setFont(*new QFont("Times", 18, QFont::Bold));
    ghostEaterText->setDefaultTextColor(Qt::white);
    sceneGame->addItem(ghostEaterText);



    //PLAYER LIVES
    livesText = new QGraphicsTextItem(QString("LIVES: 3"));
    livesText->setFont(*new QFont("Times", 18, QFont::Bold));
    livesText->setDefaultTextColor(Qt::white);
    livesText->setPos(5, 700);
    sceneGame->addItem(livesText);
}


void GameManager::mainMenuDisplay(){
    scene->clear();
    //Main menu UI
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Pac MEN"));
    titleText->setDefaultTextColor(Qt::white);
    titleText->setFont(*new QFont("Times", 40, QFont::Bold));
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Play!"));
    int bxPos = this->width()/2-playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(newGame()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Exit"));
    int qxPos = this->width()/2-quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    scene->addItem(quitButton);
}

void GameManager::pauseMenuDisplay(){
    scenePause->clear();
    //Pause menu UI
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Game paused"));
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scenePause->addItem(titleText);

    Button* playButton = new Button(QString("Resume"));
    int bxPos = this->width()/2-playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(resumeGame()));
    scenePause->addItem(playButton);

    Button* quitButton = new Button(QString("Main menu"));
    int qxPos = this->width()/2-quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(goMainMenu()));
    scenePause->addItem(quitButton);
}

void GameManager::endMenuDisplay(bool win){
    sceneEnd->clear();
    if(win){
        QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Congratulations!"));
        int txPos = this->width()/2 - titleText->boundingRect().width()/2;
        int tyPos = 150;
        titleText->setPos(txPos,tyPos);
        sceneEnd->addItem(titleText);

    } else {
        QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("You lose..."));
        int txPos = this->width()/2 - titleText->boundingRect().width()/2;
        int tyPos = 150;
        titleText->setPos(txPos,tyPos);
        sceneEnd->addItem(titleText);

    }
    scoreText = new QGraphicsTextItem(QString("Your Score: "+QString::number(this->player->nbGold)));
    int txPos = this->width()/2 - scoreText->boundingRect().width()/2;
    int tyPos = 180;
    scoreText->setPos(txPos,tyPos);
    sceneEnd->addItem(scoreText);

    Button* quitButton = new Button(QString("Main menu"));
    int qxPos = this->width()/2-quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(goMainMenu()));
    sceneEnd->addItem(quitButton);

}

void GameManager::environmentUI(){
    //QImage map ("C:/Users/Shana/Pictures/test.png");
    /*for(int i = 0; i < map.width(); i++){
        for(int n = 0; n < map.height(); n++){
            qDebug () << map.pixel(i,n);
        }
    }*/
    map = new QImage(environment->display());
    int txPos = (this->width()/2 - scoreText->boundingRect().width()/2)-100;
    int tyPos = 80;

    item = new QGraphicsPixmapItem( QPixmap::fromImage(*map));
    item->setScale(5);
    item->setPos(272,tyPos);
    sceneGame->addItem(item);

    delete map;
}

bool GameManager::eventFilter(QObject *obj, QEvent *event)
{
     if( event->type() == QEvent::KeyPress)
      {
           qDebug()<<"Scroll Bar Key press event";

            return true;
       }
        if( event->type() == QEvent::Paint)
      {
           qDebug()<<"Scroll Bar Paint event";
       }

    return false;

}

void GameManager::keyPressEvent(QKeyEvent *event)
{
    if(isPlaying){
        this->player->setNextMove(Qt::Key(event->key()));
    }
}
void GameManager::initItems() {
    int nbFood = 3;
    for (int y = 0; y < this->environment->boardSizeY; y++) {
        for (int x = 0; x < this->environment->boardSizeX; x++) {
            int rand = std::rand() % 100;
            if (this->environment->getBoxState(x, y) == BoxState::FREE) {
                if (rand < 2 && nbFood-- > 0) {
                    this->items.push_back(new Food(x, y));
                } else {
                    this->items.push_back(new Gold(x, y));
                }
            }
        }
    }
}
void GameManager::displayItems() {
    for (std::list<Item*>::iterator it = this->items.begin(); it != items.end(); ++it) {
        (*it)->place();
    }
}
void GameManager::hitItems() {
    std::vector<Item*> deletedItem;
    for (std::list<Item*>::iterator it = this->items.begin(); it != items.end(); ++it) {
        if ((*it)->isHitByPlayer()) {
            if ((*it)->characterType == BoxState::GOLD) {
                this->player->nbGold++;
            } else  if ((*it)->characterType == BoxState::FOOD) {
                this->player->nbGold += 5;
                //this->player->canEatGhost(true);
                framesBoost += 50;
                ghostEaterText->setPlainText(QString("GHOST EATER !!"));
            }
            deletedItem.push_back((*it));
            // this->items.remove((*it));
        }
    }

    for(std::vector<Item*>::iterator it = deletedItem.begin(); it != deletedItem.end(); ++it) {
        this->items.remove((*it));
    }

    deletedItem.clear();
}

bool GameManager::goldRemaining() {
    for (std::list<Item*>::iterator it = this->items.begin(); it != items.end(); ++it) {
        if ((*it)->characterType == BoxState::GOLD) {
            return true;
        }
    }
    return false;
}
