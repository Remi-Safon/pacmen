#include "gamemanager.h"
#include "button.h"
#include "boardservice.h"

GameManager::GameManager(QWidget* parent)
{
    isPlaying = false;
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,900);

    //Load all scenes
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,900);

    sceneGame = new QGraphicsScene();
    sceneGame->setSceneRect(0,0,800,900);

    scenePause = new QGraphicsScene();
    scenePause->setSceneRect(0,0,800,900);
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

    environment = BoardService::getInstance();

    player = new Player(9, 19);
    ghost1 = new Enemy(9, 10);
    ghost2 = new Enemy(10, 10);
    ghost3 = new Enemy(8, 10);
    ghost4 = new Enemy(11, 10);

    characters.push_back(this->player);
    characters.push_back(this->ghost1);
    characters.push_back(this->ghost2);
    characters.push_back(this->ghost3);
    characters.push_back(this->ghost4);

    isPlaying = true;

    changeLivesHUD();
    changeScoreHUD();
    environmentUI();

     int i = 0;
    while(1) { //!this->gameOver()
        update();
    }


}

void GameManager::update(){
    QApplication::processEvents();
    this->environment->init();
    for (std::list<Character*>::iterator it = this->characters.begin(); it != characters.end(); ++it) {
        (*it)->move();
    }

    changeLivesHUD();
    changeScoreHUD();
    environmentUI();

    Sleep(500);
}

bool GameManager::gameOver () {
    return (this->player->isAlive() ? false : true);
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
    //TODO: SET TIME TO NORMAL AND HIDE PAUSE MENU
    isPlaying = true;
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

    isPlaying = false;

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

void GameManager::environmentUI(){
    //QImage map ("C:/Users/Shana/Pictures/test.png");
    /*for(int i = 0; i < map.width(); i++){
        for(int n = 0; n < map.height(); n++){
            qDebug () << map.pixel(i,n);
        }
    }*/
    QImage map(environment->display());
    int txPos = (this->width()/2 - scoreText->boundingRect().width()/2)-100;
    int tyPos = 80;
    std::string s = "C:/Users/remis/Desktop/MERDE/test";
    s+= std::to_string(i++);
    s+= ".png";

    map.save(s.c_str());
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem( QPixmap::fromImage(map));
    item->setScale(28);
    item->setPos(txPos,tyPos);
    sceneGame->addItem(item);
}

void GameManager::keyPressEvent(QKeyEvent *event)
{
    //CREER UNE VARIABLE D'ETAT -> isPlaying
    if(isPlaying){
        qDebug ("keyPressEvent\n");
        this->player->setNextMove(Qt::Key(event->key()));
    }
}

