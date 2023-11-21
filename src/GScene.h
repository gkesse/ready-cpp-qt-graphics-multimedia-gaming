//===============================================
#ifndef _GScene_
#define _GScene_
//===============================================
#include "GObject.h"
//===============================================
class GBackground;
class GCoin;
class GQuestion;
class GMushroom;
class GFlower;
class GBrick;
class GWall;
class GNote;
class GGoomba;
class GTurtle;
class GPiranha;
class GBomb;
class GRedTurtle;
class GSpiny;
class GSmallMario;
class GCastle;
class GFlag;
class GCounter;
class GScore;
class GTimer;
class GStretch;
class GConveyor;
class GGiantGoomba;
class GWarpTube;
class GStairBlock;
//===============================================
class GScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit GScene(QScrollBar* _scroll, QObject* _parent = 0);
    ~GScene();
    void initPlayField();

public slots:
    void movePlayer();
    void fallPlayer();

protected:
    void timerEvent(QTimerEvent* _event);

private:
    int m_groundLevel;

    QTimer m_timer;
    QTimer mFallTimer;

    QPropertyAnimation *m_jumpAnimation;

    GBackground* sky;
    GBackground* gameover;
    GBackground* courseclear;
    GBackground* m_ground;
    GBackground* m_Scene;
    GBackground* m_countLogo;
    GBackground* m_scoreLogo;
    GBackground* m_timerLogo;
    GBackground* m_wall2;
    GBackground* m_wall;
    GBackground* m_wall3;
    GBackground* m_flag;
    GBackground* m_castle;
    GBackground* m_sign;

    GCoin* m_coins;
    GCoin* m_coins2;
    GCoin* m_coins3;
    GCoin* m_coins4;
    GCoin* m_coins5;
    GCoin* m_coins6;
    GCoin* m_coins7;
    GCoin* m_coins8;
    GCoin* m_coins9;
    GCoin* m_coins10;
    GCoin* m_coins11;
    GCoin* m_coins12;
    GCoin* m_coins13;
    GCoin* m_coins14;
    GCoin* m_coins15;
    GCoin* m_coins16;
    GCoin* m_coins17;
    GCoin* m_coins18;
    GCoin* m_coins19;
    GCoin* m_coins20;
    GCoin* m_coins21;
    GCoin* m_coins22;
    GCoin* m_coins23;
    GCoin* m_coins24;
    GCoin* m_coins25;
    GCoin* m_coins26;

    GCoin* m_coins27;
    GCoin* m_coins28;
    GCoin* m_coins29;
    GCoin* m_coins30;

    GCoin* m_coins32;
    GCoin* m_coins33;
    GCoin* m_coins34;
    GCoin* m_coins35;
    GCoin* m_coins36;

    GCoin* m_coins37;
    GCoin* m_coins38;
    GCoin* m_coins39;
    GCoin* m_coins40;
    GCoin* m_coins41;

    GCoin* m_coins42;
    GCoin* m_coins43;
    GCoin* m_coins44;
    GCoin* m_coins45;
    GCoin* m_coins46;
    GCoin* m_coins47;

    GCoin* m_coins48;
    GCoin* m_coins49;
    GCoin* m_coins50;
    GCoin* m_coins51;
    GCoin* m_coins52;

    GCoin* m_coins53;
    GCoin* m_coins54;
    GCoin* m_coins55;
    GCoin* m_coins56;

    GCoin* m_coins57;
    GCoin* m_coins58;
    GCoin* m_coins59;
    GCoin* m_coins60;

    GCoin* m_coins61;
    GCoin* m_coins62;
    GCoin* m_coins63;
    GCoin* m_coins64;
    GCoin* m_coins65;
    GCoin* m_coins66;
    GCoin* m_coins67;
    GCoin* m_coins68;

    GCoin* m_coins69;
    GCoin* m_coins70;
    GCoin* m_coins71;

    GCoin* m_coins72;
    GCoin* m_coins73;
    GCoin* m_coins74;

    GCoin* m_coins75;
    GCoin* m_coins76;
    GCoin* m_coins77;
    GCoin* m_coins78;
    GCoin* m_coins79;
    GCoin* m_coins80;

    GCoin* m_coins81;
    GCoin* m_coins82;
    GCoin* m_coins83;
    GCoin* m_coins84;
    GCoin* m_coins85;
    GCoin* m_coins86;

    GCoin* m_coins87;
    GCoin* m_coins88;
    GCoin* m_coins89;
    GCoin* m_coins90;
    GCoin* m_coins91;
    GCoin* m_coins92;
    GCoin* m_coins93;
    GCoin* m_coins94;
    GCoin* m_coins95;
    GCoin* m_coins96;
    GCoin* m_coins97;
    GCoin* m_coins98;
    GCoin* m_coins99;
    GCoin* m_coins100;

    GQuestion* m_questbox;
    GQuestion* m_questbox2;
    GQuestion* m_questbox3;
    GQuestion* m_questbox4;
    GQuestion* m_questbox5;
    GQuestion* m_questbox6;
    GQuestion* m_questbox7;
    GQuestion* m_questbox8;

    GQuestion* m_questbox9;
    GQuestion* m_questbox10;
    GQuestion* m_questbox11;

    GQuestion* m_questbox12;

    GMushroom* mushroomQuestBox;
    GFlower* flowerQuestBox;

    GBrick* mBrickPlatform;
    GBrick* mBrickPlatform2;
    GBrick* mBrickPlatform3;
    GBrick* mBrickPlatform4;
    GBrick* mBrickPlatform5;
    GBrick* mBrickPlatform6;
    GBrick* mBrickPlatform7;
    GBrick* mBrickPlatform8;

    GWall* m_wallPlatform;
    GWall* m_wallPlatform2;
    GWall* m_wallPlatform3;
    GWall* m_wallPlatform4;
    GWall* m_wallPlatform5;
    GWall* m_wallPlatform6;
    GWall* m_wallPlatform7;
    GWall* m_wallPlatform8;
    GWall* m_wallPlatform9;
    GWall* m_wallPlatform10;
    GWall* m_wallPlatform11;

    GNote* m_NoteBox;
    GNote* m_NoteBox2;
    GNote* m_NoteBox3;
    GNote* m_NoteBox4;
    GNote* m_NoteBox5;
    GNote* m_NoteBox6;

    GGoomba *m_goomba;
    GGoomba *m_goomba2;

    GTurtle* m_turtle;
    GTurtle* m_turtle2;

    GBomb* m_bomb2;
    GRedTurtle* m_redTurtle;
    GSpiny* m_spiny;
    GSmallMario* m_smallPlayer;
    GCastle* h_castle;

    GPiranha* m_piranha;
    GPiranha* m_piranha2;
    GPiranha* m_piranha3;

    GConveyor* m_conveyor;
    GConveyor* m_conveyor2;
    GConveyor* m_conveyor3;

    GGiantGoomba* m_giantgoomba;
    GGiantGoomba* m_giantgoomba2;
    GGiantGoomba* m_giantgoomba3;

    GWarpTube* m_warpTube1;
    GWarpTube* m_warpTube2;
    GWarpTube* m_warpTube3;

    GStairBlock* m_stairBlock;
    GStairBlock* m_stairBlock2;
    GStairBlock* m_stairBlock3;
    GStairBlock* m_stairBlock4;
    GStairBlock* m_stairBlock5;
    GStairBlock* m_stairBlock6;
    GStairBlock* m_stairBlock7;
    GStairBlock* m_stairBlock8;
    GStairBlock* m_stairBlock9;

    GFlag* m_flag2;
    GCounter* m_count;
    GScore* m_score;
    GTimer* m_gameTimer;
    GStretch* m_stretch;
};
//===============================================
#endif
//===============================================
