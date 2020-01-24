#include "gamemanager.h"
#include "button.h"
#include "boardservice.h"

GameManager::GameManager(QWidget* parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,500);

    //Load all scenes
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,500);

    sceneGame = new QGraphicsScene();
    sceneGame->setSceneRect(0,0,800,500);

    scenePause = new QGraphicsScene();
    scenePause->setSceneRect(0,0,800,500);

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

    environment = BoardService::getInstance();

    player = new Player(10, 17);
    ghost1 = new Enemy(10, 13);
    ghost2 = new Enemy(10, 14);
    ghost3 = new Enemy(11, 13);
    ghost4 = new Enemy(11, 14);

    changeLivesHUD();
    changeScoreHUD();

    qDebug ("Print environment :\n %s", environment->toString().c_str());
}

void GameManager::quitGame()
{
    QCoreApplication::quit();
}

void GameManager::pauseGame()
{
    //TODO: STOP TIME AND KEEP SCENE
    changeLivesHUD();
    setScene(scenePause);

    show();

    pauseMenuDisplay();
}

void GameManager::resumeGame()
{
    //TODO: SET TIME TO NORMAL AND HIDE PAUSE MENU
    setScene(sceneGame);
    show();
}

void GameManager::goMainMenu()
{
    free(player);
    free(ghost1);
    free(ghost2);
    free(ghost3);
    free(ghost4);

    setScene(scene);
    show();
    mainMenuDisplay();
}

void GameManager::changeScoreHUD(){
    scoreText->setPlainText(QString("SCORE: ")+QString::number(100));
}

void GameManager::changeLivesHUD(){
    livesText->setPlainText(QString("LIVES: ")+QString::number(player->loseLive()));
}

void GameManager::hudLoad()
{
    //PAUSE BTN
    Button* pauseButton = new Button(QString("Pause"));
    int bxPos = 20;
    int byPos = 20;
    pauseButton->setPos(bxPos,byPos);
    connect(pauseButton,SIGNAL(clicked()),this,SLOT(pauseGame()));
    sceneGame->addItem(pauseButton);

    //PLAYER SCORE
    scoreText = new QGraphicsTextItem(QString("SCORE: 0"));
    int txPos = this->width()/2 - scoreText->boundingRect().width()/2;
    int tyPos = 20;
    scoreText->setPos(txPos,tyPos);
    sceneGame->addItem(scoreText);

    //PLAYER LIVES
    livesText = new QGraphicsTextItem(QString("LIVES: 3"));
    int lxPos = 750;
    int lyPos = 20;
    livesText->setPos(lxPos,lyPos);
    sceneGame->addItem(livesText);
}


void GameManager::mainMenuDisplay(){
    scene->clear();
    //Main menu UI
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Pac MEN"));
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

