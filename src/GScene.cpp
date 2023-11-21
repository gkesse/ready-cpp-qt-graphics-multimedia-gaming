//===============================================
#include "GScene.h"
#include "GBackground.h"
#include "GCoin.h"
#include "GQuestion.h"
#include "GMushroom.h"
#include "GFlower.h"
#include "GBrick.h"
#include "GWall.h"
#include "GNote.h"
#include "GGoomba.h"
#include "GTurtle.h"
#include "GPiranha.h"
#include "GBomb.h"
#include "GRedTurtle.h"
#include "GSpiny.h"
#include "GSmallMario.h"
#include "GCastle.h"
#include "GFlag.h"
#include "GCounter.h"
#include "GScore.h"
#include "GTimer.h"
#include "GStretch.h"
#include "GConveyor.h"
#include "GGiantGoomba.h"
#include "GWarpTube.h"
#include "GStairBlock.h"
//===============================================
GScene::GScene(QScrollBar* _scroll, QObject* _parent)
: QGraphicsScene(_parent)
, m_jumpAnimation(new QPropertyAnimation(this)) {
    initPlayField();
}
//===============================================
GScene::~GScene() {

}
//===============================================
void GScene::initPlayField(){
    int lWidth = 8000;
    int lHeight = 720;

    m_groundLevel = 660;

    setSceneRect(0, 0, lWidth, lHeight);

    sky = new GBackground(QPixmap(":/img/sky.png"));
    sky->setPos(0, 0);
    addItem(sky);

    gameover = new GBackground(QPixmap(":/img/gameovers.png"));
    courseclear = new GBackground(QPixmap(":/img/c2.png"));

    m_ground = new GBackground(QPixmap(":/img/ground.png"));
    m_ground->setPos(0, m_groundLevel );
    addItem(m_ground);

    m_Scene = new GBackground(QPixmap(":/img/scene.png"));
    m_Scene->setPos(0, m_groundLevel - m_Scene->boundingRect().height());
    addItem(m_Scene);

    m_countLogo = new GBackground(QPixmap(":/img/count.png"));
    m_countLogo->setPos(30, m_groundLevel -652);
    addItem(m_countLogo);

    m_scoreLogo = new GBackground(QPixmap(":/img/scoretext.png"));
    m_scoreLogo->setPos(900, m_groundLevel - 647);
    addItem(m_scoreLogo);

    m_timerLogo = new GBackground(QPixmap(":/img/clock.png"));
    m_timerLogo->setPos(1100, m_groundLevel -654 );
    addItem(m_timerLogo);

    m_wall2 = new GBackground(QPixmap(":/img/wallg.png"));
    m_wall2->setPos(3100, m_groundLevel - m_wall2->boundingRect().height());
    addItem(m_wall2);

    m_wall = new GBackground(QPixmap(":/img/wallf2.png"));
    m_wall->setPos(2900, m_groundLevel - m_wall->boundingRect().height());
    addItem(m_wall);

    m_wall3 = new GBackground(QPixmap(":/img/walli.png"));
    m_wall3->setPos(3350, m_groundLevel - m_wall3->boundingRect().height());
    addItem(m_wall3);

    m_flag = new GBackground(QPixmap(":/img/flag.png"));
    m_flag->setPos(7234, m_groundLevel - m_flag->boundingRect().height());
    addItem(m_flag);

    m_castle = new GBackground(QPixmap(":/img/castle.png"));
    m_castle->setPos(7637, m_groundLevel - m_castle->boundingRect().height());
    addItem(m_castle);

    //===============================================
    // coins
    //===============================================
    m_coins = new GCoin;
    m_coins->setPos(1300, m_groundLevel - m_coins->boundingRect().height() - 200);
    addItem(m_coins);

    m_coins2 = new GCoin;
    m_coins2->setPos(1300, m_groundLevel - m_coins2->boundingRect().height()-250);
    addItem(m_coins2);

    m_coins3 = new GCoin;
    m_coins3->setPos(1300, m_groundLevel - m_coins3->boundingRect().height()-300);
    addItem(m_coins3);

    m_coins4 = new GCoin;
    m_coins4->setPos(1300, m_groundLevel - m_coins4->boundingRect().height()-350);
    addItem(m_coins4);

    m_coins5 = new GCoin;
    m_coins5->setPos(1350, m_groundLevel - m_coins5->boundingRect().height()-350);
    addItem(m_coins5);

    m_coins6 = new GCoin;
    m_coins6->setPos(1400, m_groundLevel - m_coins6->boundingRect().height()-350);
    addItem(m_coins6);

    m_coins7 = new GCoin;
    m_coins7->setPos(1400, m_groundLevel - m_coins7->boundingRect().height()-300);
    addItem(m_coins7);

    m_coins8 = new GCoin;
    m_coins8->setPos(1350, m_groundLevel - m_coins8->boundingRect().height()-250);
    addItem(m_coins8);

    m_coins9 = new GCoin;
    m_coins9->setPos(1400, m_groundLevel - m_coins9->boundingRect().height()-200);
    addItem(m_coins9);

    m_coins10 = new GCoin;
    m_coins10->setPos(1500, m_groundLevel - m_coins10->boundingRect().height()-200);
    addItem(m_coins10);

    m_coins11 = new GCoin;
    m_coins11->setPos(1500, m_groundLevel - m_coins11->boundingRect().height()-250);
    addItem(m_coins11);

    m_coins12 = new GCoin;
    m_coins12->setPos(1500, m_groundLevel - m_coins12->boundingRect().height()-300);
    addItem(m_coins12);

    m_coins13 = new GCoin;
    m_coins13->setPos(1500, m_groundLevel - m_coins13->boundingRect().height()-350);
    addItem(m_coins13);

    m_coins14 = new GCoin;
    m_coins14->setPos(1550, m_groundLevel -  m_coins14->boundingRect().height()-350);
    addItem( m_coins14);

    m_coins15 = new GCoin;
    m_coins15->setPos(1600, m_groundLevel - m_coins15->boundingRect().height()-350);
    addItem(m_coins15);

    m_coins16 = new GCoin;
    m_coins16->setPos(1500, m_groundLevel - m_coins16->boundingRect().height()-200);
    addItem(m_coins16);

    m_coins17 = new GCoin;
    m_coins17->setPos(1550, m_groundLevel - m_coins17->boundingRect().height()-200);
    addItem(m_coins17);

    m_coins18 = new GCoin;
    m_coins18->setPos(1600, m_groundLevel - m_coins18->boundingRect().height()-200);
    addItem(m_coins18);

    m_coins19 = new GCoin;
    m_coins19->setPos(1700, m_groundLevel - m_coins19->boundingRect().height()-200);
    addItem(m_coins19);

    m_coins20 = new GCoin;
    m_coins20->setPos(1700, m_groundLevel - m_coins20->boundingRect().height()-250);
    addItem(m_coins20);

    m_coins21 = new GCoin;
    m_coins21->setPos(1700, m_groundLevel - m_coins21->boundingRect().height()-300);
    addItem(m_coins21);

    m_coins22 = new GCoin;
    m_coins22->setPos(1700, m_groundLevel - m_coins22->boundingRect().height()-350);
    addItem(m_coins22);

    m_coins23 = new GCoin;
    m_coins23->setPos(1750, m_groundLevel - m_coins23->boundingRect().height()-350);
    addItem(m_coins23);

    m_coins24 = new GCoin;
    m_coins24->setPos(1800, m_groundLevel - m_coins24->boundingRect().height()-350);
    addItem(m_coins24);

    m_coins25 = new GCoin;
    m_coins25->setPos(1750, m_groundLevel - m_coins25->boundingRect().height()-200);
    addItem(m_coins25);

    m_coins26 = new GCoin;
    m_coins26->setPos(1800, m_groundLevel - m_coins26->boundingRect().height()-200);
    addItem(m_coins26);

    m_coins27 = new GCoin;
    m_coins27->setPos(2970, m_groundLevel - m_coins27->boundingRect().height()-290);
    addItem(m_coins27);

    m_coins28 = new GCoin;
    m_coins28->setPos(3020, m_groundLevel - m_coins28->boundingRect().height()-290);
    addItem(m_coins28);

    m_coins29 = new GCoin;
    m_coins29->setPos(3070, m_groundLevel - m_coins29->boundingRect().height()-290);
    addItem(m_coins29);

    m_coins30 = new GCoin;
    m_coins30->setPos(2920, m_groundLevel - m_coins30->boundingRect().height()-290);
    addItem(m_coins30);

    m_coins32 = new GCoin;
    m_coins32->setPos(4110, m_groundLevel - m_coins32->boundingRect().height()-150);
    addItem(m_coins32);

    m_coins33 = new GCoin;
    m_coins33->setPos(3360, m_groundLevel - m_coins33->boundingRect().height()-150);
    addItem(m_coins33);

    m_coins34 = new GCoin;
    m_coins34->setPos(3410, m_groundLevel - m_coins34->boundingRect().height()-150);
    addItem(m_coins34);

    m_coins35 = new GCoin;
    m_coins35->setPos(3460, m_groundLevel - m_coins35->boundingRect().height()-150);
    addItem(m_coins35);

    m_coins36 = new GCoin;
    m_coins36->setPos(3510, m_groundLevel - m_coins36->boundingRect().height()-150);
    addItem(m_coins36);

    m_coins37 = new GCoin;
    m_coins37->setPos(3560, m_groundLevel - m_coins37->boundingRect().height()-150);
    addItem(m_coins37);

    m_coins38 = new GCoin;
    m_coins38->setPos(3610, m_groundLevel - m_coins38->boundingRect().height()-150);
    addItem(m_coins38);

    m_coins39 = new GCoin;
    m_coins39->setPos(3660, m_groundLevel - m_coins39->boundingRect().height()-150);
    addItem(m_coins39);

    m_coins40 = new GCoin;
    m_coins40->setPos(3710, m_groundLevel - m_coins40->boundingRect().height()-150);
    addItem(m_coins40);

    m_coins41 = new GCoin;
    m_coins41->setPos(3760, m_groundLevel - m_coins41->boundingRect().height()-150);
    addItem(m_coins41);

    m_coins42 = new GCoin;
    m_coins42->setPos(3810, m_groundLevel - m_coins42->boundingRect().height()-150);
    addItem(m_coins42);

    m_coins43 = new GCoin;
    m_coins43->setPos(3860, m_groundLevel - m_coins43->boundingRect().height()-150);
    addItem(m_coins43);

    m_coins44 = new GCoin;
    m_coins44->setPos(3910, m_groundLevel - m_coins44->boundingRect().height()-150);
    addItem(m_coins44);

    m_coins45 = new GCoin;
    m_coins45->setPos(3960, m_groundLevel - m_coins45->boundingRect().height()-150);
    addItem(m_coins45);

    m_coins46 = new GCoin;
    m_coins46->setPos(4010, m_groundLevel - m_coins46->boundingRect().height()-150);
    addItem(m_coins46);

    m_coins47 = new GCoin;
    m_coins47->setPos(4060, m_groundLevel - m_coins47->boundingRect().height()-150);
    addItem(m_coins47);

    m_coins48 = new GCoin;
    m_coins48->setPos(3995, m_groundLevel - m_coins48->boundingRect().height()-370);
    addItem(m_coins48);

    m_coins49 = new GCoin;
    m_coins49->setPos(4030, m_groundLevel - m_coins49->boundingRect().height()-440);
    addItem(m_coins49);

    m_coins50 = new GCoin;
    m_coins50->setPos(4108, m_groundLevel - m_coins50->boundingRect().height()-495);
    addItem(m_coins50);

    m_coins51 = new GCoin;
    m_coins51->setPos(4190, m_groundLevel - m_coins51->boundingRect().height()-450);
    addItem(m_coins51);

    m_coins52 = new GCoin;
    m_coins52->setPos(4240, m_groundLevel - m_coins52->boundingRect().height()-390);
    addItem(m_coins52);

    m_coins53 = new GCoin;
    m_coins53->setPos(4290, m_groundLevel - m_coins53->boundingRect().height()-465);
    addItem(m_coins53);

    m_coins54 = new GCoin;
    m_coins54->setPos(4360, m_groundLevel - m_coins54->boundingRect().height()-520);
    addItem(m_coins54);

    m_coins55 = new GCoin;
    m_coins55->setPos(4435, m_groundLevel - m_coins55->boundingRect().height()-465);
    addItem(m_coins55);

    m_coins56 = new GCoin;
    m_coins56->setPos(4490, m_groundLevel - m_coins56->boundingRect().height()-410);
    addItem(m_coins56);

    m_coins57 = new GCoin;
    m_coins57->setPos(4540, m_groundLevel - m_coins57->boundingRect().height()-490);
    addItem(m_coins57);

    m_coins58 = new GCoin;
    m_coins58->setPos(4610, m_groundLevel - m_coins58->boundingRect().height()-540);
    addItem(m_coins58);

    m_coins59 = new GCoin;
    m_coins59->setPos(4680, m_groundLevel - m_coins59->boundingRect().height()-500);
    addItem(m_coins59);

    m_coins60 = new GCoin;
    m_coins60->setPos(4730, m_groundLevel - m_coins60->boundingRect().height()-440);
    addItem(m_coins60);

    m_coins61 = new GCoin;
    m_coins61->setPos(650, m_groundLevel - m_coins61->boundingRect().height()-280);
    addItem(m_coins61);

    m_coins62 = new GCoin;
    m_coins62->setPos(2100, m_groundLevel - m_coins62->boundingRect().height()-250);
    addItem(m_coins62);

    m_coins63 = new GCoin;
    m_coins63->setPos(815, m_groundLevel - m_coins63->boundingRect().height()-320);
    addItem(m_coins63);

    m_coins64 = new GCoin;
    m_coins64->setPos(2155, m_groundLevel - m_coins64->boundingRect().height()-250);
    addItem(m_coins64);

    m_coins65 = new GCoin;
    m_coins65->setPos(2210, m_groundLevel - m_coins65->boundingRect().height()-250);
    addItem(m_coins65);

    m_coins66 = new GCoin;
    m_coins66->setPos(2265, m_groundLevel - m_coins66->boundingRect().height()-250);
    addItem(m_coins66);

    m_coins67 = new GCoin;
    m_coins67->setPos(2320, m_groundLevel - m_coins67->boundingRect().height()-250);
    addItem(m_coins67);

    m_coins68 = new GCoin;
    m_coins68->setPos(2375, m_groundLevel - m_coins68->boundingRect().height()-250);
    addItem(m_coins68);

    m_coins69 = new GCoin;
    m_coins69->setPos(5400, m_groundLevel - m_coins69->boundingRect().height()-250);
    addItem(m_coins69);

    m_coins70 = new GCoin;
    m_coins70->setPos(5400, m_groundLevel - m_coins70->boundingRect().height()-300);
    addItem(m_coins70);

    m_coins71 = new GCoin;
    m_coins71->setPos(5400, m_groundLevel - m_coins71->boundingRect().height()-350);
    addItem(m_coins71);

    m_coins72 = new GCoin;
    m_coins72->setPos(5350, m_groundLevel - m_coins72->boundingRect().height()-250);
    addItem(m_coins72);

    m_coins73 = new GCoin;
    m_coins73->setPos(5350, m_groundLevel - m_coins73->boundingRect().height()-300);
    addItem(m_coins73);

    m_coins74 = new GCoin;
    m_coins74->setPos(5350, m_groundLevel - m_coins74->boundingRect().height()-350);
    addItem(m_coins74);

    m_coins75 = new GCoin;
    m_coins75->setPos(5300, m_groundLevel - m_coins75->boundingRect().height()-250);
    addItem(m_coins75);

    m_coins76 = new GCoin;
    m_coins76->setPos(5300, m_groundLevel - m_coins76->boundingRect().height()-300);
    addItem(m_coins76);

    m_coins77 = new GCoin;
    m_coins77->setPos(5300, m_groundLevel - m_coins77->boundingRect().height()-350);
    addItem(m_coins77);

    m_coins78 = new GCoin;
    m_coins78->setPos(5250, m_groundLevel - m_coins78->boundingRect().height()-250);
    addItem(m_coins78);

    m_coins79 = new GCoin;
    m_coins79->setPos(5250, m_groundLevel - m_coins79->boundingRect().height()-300);
    addItem(m_coins79);

    m_coins80 = new GCoin;
    m_coins80->setPos(5250, m_groundLevel - m_coins80->boundingRect().height()-350);
    addItem(m_coins80);

    m_coins81 = new GCoin;
    m_coins81->setPos(5200, m_groundLevel - m_coins81->boundingRect().height()-250);
    addItem(m_coins81);

    m_coins82 = new GCoin;
    m_coins82->setPos(5200, m_groundLevel - m_coins82->boundingRect().height()-300);
    addItem(m_coins82);

    m_coins83 = new GCoin;
    m_coins83->setPos(5200, m_groundLevel - m_coins83->boundingRect().height()-350);
    addItem(m_coins83);

    m_coins84 = new GCoin;
    m_coins84->setPos(5150, m_groundLevel - m_coins84->boundingRect().height()-250);
    addItem(m_coins84);

    m_coins85 = new GCoin;
    m_coins85->setPos(5150, m_groundLevel - m_coins85->boundingRect().height()-300);
    addItem(m_coins85);

    m_coins86 = new GCoin;
    m_coins86->setPos(5150, m_groundLevel - m_coins86->boundingRect().height()-350);
    addItem(m_coins86);

    m_coins87 = new GCoin;
    m_coins87->setPos(5700, m_groundLevel - m_coins87->boundingRect().height()-350);
    addItem(m_coins87);

    m_coins88 = new GCoin;
    m_coins88->setPos(5750, m_groundLevel - m_coins88->boundingRect().height()-350);
    addItem(m_coins88);

    m_coins89 = new GCoin;
    m_coins89->setPos(5800, m_groundLevel - m_coins89->boundingRect().height()-350);
    addItem(m_coins89);

    m_coins90 = new GCoin;
    m_coins90->setPos(5850, m_groundLevel - m_coins90->boundingRect().height()-350);
    addItem(m_coins90);

    m_coins91 = new GCoin;
    m_coins91->setPos(5900, m_groundLevel - m_coins91->boundingRect().height()-350);
    addItem(m_coins91);

    m_coins92 = new GCoin;
    m_coins92->setPos(5950, m_groundLevel - m_coins92->boundingRect().height()-350);
    addItem(m_coins92);

    m_coins93 = new GCoin;
    m_coins93->setPos(6000, m_groundLevel - m_coins93->boundingRect().height()-350);
    addItem(m_coins93);

    m_coins94 = new GCoin;
    m_coins94->setPos(6050, m_groundLevel - m_coins94->boundingRect().height()-350);
    addItem(m_coins94);

    m_coins95 = new GCoin;
    m_coins95->setPos(6100, m_groundLevel - m_coins95->boundingRect().height()-350);
    addItem(m_coins95);

    m_coins96 = new GCoin;
    m_coins96->setPos(6140, m_groundLevel - m_coins96->boundingRect().height()-350);
    addItem(m_coins96);

    m_coins97 = new GCoin;
    m_coins97->setPos(6105, m_groundLevel - m_coins97->boundingRect().height()-300);
    addItem(m_coins97);

    m_coins98 = new GCoin;
    m_coins98->setPos(6060, m_groundLevel - m_coins98->boundingRect().height()-250);
    addItem(m_coins98);

    m_coins99 = new GCoin;
    m_coins99->setPos(6105, m_groundLevel - m_coins99->boundingRect().height()-400);
    addItem(m_coins99);

    m_coins100 = new GCoin;
    m_coins100->setPos(6060, m_groundLevel - m_coins100->boundingRect().height()-450);
    addItem(m_coins100);

    //===============================================
    // question
    //===============================================
    m_questbox = new GQuestion(1);
    m_questbox->setPos(643, m_groundLevel - m_questbox->boundingRect().height()-100);
    addItem(m_questbox);

    m_questbox2 = new GQuestion(1);
    m_questbox2->setPos(2755, m_groundLevel - m_questbox2->boundingRect().height()-150);
    addItem(m_questbox2);

    m_questbox3 = new GQuestion(1);
    m_questbox3->setPos(2658, m_groundLevel - m_questbox3->boundingRect().height()-100);
    addItem(m_questbox3);

    m_questbox4 = new GQuestion(1);
    m_questbox4->setPos(3250, m_groundLevel - m_questbox4->boundingRect().height()-450);
    addItem(m_questbox4);

    m_questbox5 = new GQuestion(1);
    m_questbox5->setPos(3750, m_groundLevel - m_questbox5->boundingRect().height()-250);
    addItem(m_questbox5);

    m_questbox6 = new GQuestion(1);
    m_questbox6->setPos(1745, m_groundLevel - m_questbox6->boundingRect().height()-130);
    addItem(m_questbox6);

    m_questbox7 = new GQuestion(1);
    m_questbox7->setPos(1545, m_groundLevel - m_questbox7->boundingRect().height()-130);
    addItem(m_questbox7);

    m_questbox8 = new GQuestion(1);
    m_questbox8->setPos(1345, m_groundLevel - m_questbox8->boundingRect().height()-130);
    addItem(m_questbox8);

    m_questbox9 = new GQuestion(1);
    m_questbox9->setPos(6240, m_groundLevel - m_questbox9->boundingRect().height()-350);
    addItem(m_questbox9);

    m_questbox10 = new GQuestion(1);
    m_questbox10->setPos(5600, m_groundLevel - m_questbox10->boundingRect().height()-350);
    addItem(m_questbox10);

    m_questbox11 = new GQuestion(1);
    m_questbox11->setPos(5153, m_groundLevel - m_questbox11->boundingRect().height()-200);
    addItem(m_questbox11);

    m_questbox12 = new GQuestion(1);
    m_questbox12->setPos(7200, m_groundLevel - m_questbox11->boundingRect().height()-100);
    addItem(m_questbox12);

    //===============================================
    // mushroom
    //===============================================
    mushroomQuestBox = new GMushroom(1);
    mushroomQuestBox->setPos(200, m_groundLevel - mushroomQuestBox->boundingRect().height()-100);
    mushroomQuestBox->setZValue(1);
    addItem(mushroomQuestBox);

    //===============================================
    // flower
    //===============================================
    flowerQuestBox = new GFlower(1);
    flowerQuestBox->setPos(1085, m_groundLevel - flowerQuestBox->boundingRect().height()-250);
    flowerQuestBox->setZValue(3);
    addItem(flowerQuestBox);

    //===============================================
    // bricks
    //===============================================
    mBrickPlatform = new GBrick(5);
    mBrickPlatform->setPos(404, m_groundLevel - mBrickPlatform->boundingRect().height()-100);
    addItem(mBrickPlatform);

    mBrickPlatform2 = new GBrick(1);
    mBrickPlatform2->setPos(648, m_groundLevel - mBrickPlatform2->boundingRect().height()-225);
    addItem(mBrickPlatform2);

    mBrickPlatform3 = new GBrick(1);
    mBrickPlatform3->setPos(810, m_groundLevel - mBrickPlatform3->boundingRect().height()-270);
    addItem(mBrickPlatform3);

    mBrickPlatform4 = new GBrick(5);
    mBrickPlatform4->setPos(1000, m_groundLevel - mBrickPlatform4->boundingRect().height()-100);
    addItem(mBrickPlatform4);

    mBrickPlatform5 = new GBrick(5);
    mBrickPlatform5->setPos(5500, m_groundLevel - mBrickPlatform5->boundingRect().height()-150);
    addItem(mBrickPlatform5);

    mBrickPlatform6 = new GBrick(5);
    mBrickPlatform6->setPos(5200, m_groundLevel - mBrickPlatform6->boundingRect().height()-200);
    addItem(mBrickPlatform6);

    mBrickPlatform7 = new GBrick(1);
    mBrickPlatform7->setPos(5900, m_groundLevel - mBrickPlatform7->boundingRect().height()-150);
    addItem(mBrickPlatform7);

    mBrickPlatform8 = new GBrick(7);
    mBrickPlatform8->setPos(6100, m_groundLevel - mBrickPlatform8->boundingRect().height()-150);
    addItem(mBrickPlatform8);

    //===============================================
    // walls
    //===============================================
    m_wallPlatform = new GWall(6);
    m_wallPlatform->setPos(2910, m_groundLevel - m_wallPlatform->boundingRect().height()-240);
    addItem(m_wallPlatform);

    m_wallPlatform2  = new GWall(8);
    m_wallPlatform2->setPos(3115, m_groundLevel - m_wallPlatform2->boundingRect().height()-300);
    addItem(m_wallPlatform2);

    m_wallPlatform3 = new GWall(16);
    m_wallPlatform3->setPos(3370, m_groundLevel - m_wallPlatform3->boundingRect().height()-103);
    addItem(m_wallPlatform3);

    m_wallPlatform4 = new GWall(20);
    m_wallPlatform4->setPos(5000, m_groundLevel );
    addItem(m_wallPlatform4);

    m_wallPlatform5 = new GWall(10);
    m_wallPlatform5->setPos(1345, m_groundLevel );
    addItem(m_wallPlatform5);

    m_wallPlatform6 = new GWall(3);
    m_wallPlatform6->setPos(404, m_groundLevel );
    addItem(m_wallPlatform6);

    m_wallPlatform7 = new GWall(3);
    m_wallPlatform7->setPos(1000, m_groundLevel );
    addItem(m_wallPlatform7);

    m_wallPlatform8 = new GWall(4);
    m_wallPlatform8->setPos(3115, m_groundLevel );
    addItem(m_wallPlatform8);

    m_wallPlatform9 = new GWall(3);
    m_wallPlatform9->setPos(4960, m_groundLevel );
    addItem(m_wallPlatform9);

    m_wallPlatform10 = new GWall(3);
    m_wallPlatform10->setPos(6100, m_groundLevel );
    addItem(m_wallPlatform10);

    m_wallPlatform11 = new GWall(3);
    m_wallPlatform11->setPos(2100, m_groundLevel- m_wallPlatform11->boundingRect().height()-150 );
    addItem(m_wallPlatform11);

    //===============================================
    // notes
    //===============================================
    m_NoteBox = new GNote(5);
    m_NoteBox->setPos(2100, m_groundLevel - m_NoteBox->boundingRect().height()-130);
    addItem(m_NoteBox);

    m_NoteBox2 = new GNote(1);
    m_NoteBox2->setPos(3980, m_groundLevel - m_NoteBox2->boundingRect().height()-300);
    addItem(m_NoteBox2);

    m_NoteBox3 = new GNote(1);
    m_NoteBox3->setPos(4230, m_groundLevel - m_NoteBox3->boundingRect().height()-325);
    addItem(m_NoteBox3);

    m_NoteBox4 = new GNote(1);
    m_NoteBox4->setPos(4480, m_groundLevel - m_NoteBox4->boundingRect().height()-340);
    addItem(m_NoteBox4);

    m_NoteBox5 = new GNote(1);
    m_NoteBox5->setPos(4720, m_groundLevel - m_NoteBox5->boundingRect().height()-365);
    addItem(m_NoteBox5);

    m_NoteBox6 = new GNote(5);
    m_NoteBox6->setPos(4940, m_groundLevel - m_NoteBox6->boundingRect().height()-400);
    addItem(m_NoteBox6);

    //===============================================
    // turtles
    //===============================================
    m_turtle = new GTurtle(QRectF(m_wallPlatform7->pos(), m_wallPlatform7->boundingRect().size()), -1);
    m_turtle->setPos(995, m_groundLevel - m_turtle->boundingRect().height()-150);
    addItem(m_turtle);
    connect(this->m_turtle, SIGNAL(marioSizeStatus(int)),this, SLOT(setMarioSize(int)));

    m_turtle2 = new GTurtle(QRectF(m_wallPlatform8->pos(), m_wallPlatform8->boundingRect().size()), -1);
    m_turtle2->setPos(3250, m_groundLevel - m_turtle2->boundingRect().height()-345);
    addItem(m_turtle2);
    connect(this->m_turtle2, SIGNAL(marioSizeStatus(int)),this, SLOT(setMarioSize(int)));

    //===============================================
    // piranha
    //===============================================
    m_piranha = new GPiranha;
    m_piranha->setPos(773, m_groundLevel - m_piranha->boundingRect().height()-95);
    addItem(m_piranha);

    m_piranha2 = new GPiranha;
    m_piranha2->setPos(2975, m_groundLevel - m_piranha2->boundingRect().height()-95);
    addItem(m_piranha2);

    m_piranha3= new GPiranha;
    m_piranha3->setPos(4850, m_groundLevel - m_piranha2->boundingRect().height()-95);
    addItem(m_piranha3);

    //===============================================
    // flag
    //===============================================
    m_flag2 = new GFlag;
    m_flag2->setPos(7320, m_groundLevel - m_flag2->boundingRect().height()-285);
    addItem(m_flag2);

    //===============================================
    // counter
    //===============================================
    m_count = new GCounter;
    m_count->setPos(65, m_groundLevel - m_count->boundingRect().height()-602);
    addItem(m_count);

    //===============================================
    // score
    //===============================================
    m_score = new GScore;
    m_score->setPos(980, m_groundLevel - m_score->boundingRect().height()-610);
    addItem(m_score);

    //===============================================
    // timer
    //===============================================
    m_gameTimer = new GTimer;
    m_gameTimer->setPos(1140, m_groundLevel - m_gameTimer->boundingRect().height()-610);
    addItem(m_gameTimer);

    //===============================================
    // stretch
    //===============================================
    m_stretch = new GStretch;
    m_stretch->setPos(2100, m_groundLevel - m_stretch->boundingRect().height()-20);
    addItem(m_stretch);

    //===============================================
    // sign
    //===============================================
    m_sign = new GBackground(QPixmap(":/img/sign.png"));
    m_sign->setPos(250, m_groundLevel - m_sign->boundingRect().height());
    addItem(m_sign);

    //===============================================
    // conveyor
    //===============================================
    m_conveyor = new GConveyor;
    m_conveyor->setPos(4160, m_groundLevel - m_conveyor->boundingRect().height()-100);
    addItem(m_conveyor);

    m_conveyor2 = new GConveyor;
    m_conveyor2->setPos(4370, m_groundLevel - m_conveyor2->boundingRect().height()-100);
    addItem(m_conveyor2);

    m_conveyor3 = new GConveyor;
    m_conveyor3->setPos(4580, m_groundLevel - m_conveyor3->boundingRect().height()-100);
    addItem(m_conveyor3);

    //===============================================
    // giant_goomba
    //===============================================
    m_giantgoomba = new GGiantGoomba;
    m_giantgoomba->setPos(4210, m_groundLevel - m_giantgoomba->boundingRect().height()-150);
    addItem(m_giantgoomba);

    m_giantgoomba2 = new GGiantGoomba;
    m_giantgoomba2->setPos(4420, m_groundLevel - m_giantgoomba2->boundingRect().height()-150);
    addItem(m_giantgoomba2);

    m_giantgoomba3 = new GGiantGoomba;
    m_giantgoomba3->setPos(4630, m_groundLevel - m_giantgoomba3->boundingRect().height()-150);
    addItem(m_giantgoomba3);

    //===============================================
    // warp_tube
    //===============================================
    m_warpTube1 = new GWarpTube;
    m_warpTube1->setPos(800, m_groundLevel - m_warpTube1->boundingRect().height());
    addItem(m_warpTube1);

    m_warpTube2 = new GWarpTube;
    m_warpTube2->setPos(3000, m_groundLevel - m_warpTube2->boundingRect().height());
    addItem(m_warpTube2);

    m_warpTube3 = new GWarpTube;
    m_warpTube3->setPos(4880, m_groundLevel - m_warpTube3->boundingRect().height());
    addItem(m_warpTube3);

    //===============================================
    // stairblock
    //===============================================
    m_stairBlock = new GStairBlock(9);
    m_stairBlock->setPos(6750, m_groundLevel - m_stairBlock->boundingRect().height());
    addItem(m_stairBlock);

    m_stairBlock2 = new GStairBlock(8);
    m_stairBlock2->setPos(6798, m_groundLevel - m_stairBlock2->boundingRect().height()-48);
    addItem(m_stairBlock2);

    m_stairBlock3 = new GStairBlock(7);
    m_stairBlock3->setPos(6846, m_groundLevel - m_stairBlock3->boundingRect().height()-96);
    addItem(m_stairBlock3);

    m_stairBlock4 = new GStairBlock(6);
    m_stairBlock4->setPos(6894, m_groundLevel - m_stairBlock4->boundingRect().height()-144);
    addItem(m_stairBlock4);

    m_stairBlock5 = new GStairBlock(5);
    m_stairBlock5->setPos(6942, m_groundLevel - m_stairBlock5->boundingRect().height()-192);
    addItem(m_stairBlock5);

    m_stairBlock6 = new GStairBlock(4);
    m_stairBlock6->setPos(6990, m_groundLevel - m_stairBlock6->boundingRect().height()-240);
    addItem(m_stairBlock6);

    m_stairBlock7 = new GStairBlock(3);
    m_stairBlock7->setPos(7038, m_groundLevel - m_stairBlock7->boundingRect().height()-288);
    addItem(m_stairBlock7);

    m_stairBlock8 = new GStairBlock(2);
    m_stairBlock8->setPos(7086, m_groundLevel - m_stairBlock8->boundingRect().height()-336);
    addItem(m_stairBlock8);

    //===============================================
    // goombas
    //===============================================
    m_goomba = new GGoomba(QRectF(m_wallPlatform6 ->pos(), m_wallPlatform6 ->boundingRect().size()), -1);
    m_goomba->setPos(400, m_groundLevel - m_goomba->boundingRect().height()-150);
    addItem(m_goomba);
    connect(m_goomba, SIGNAL(marioSizeStatus(int)),this, SLOT(setMarioSize(int)));

    //===============================================
    // bombs
    //===============================================
    m_bomb2 = new GBomb(QRectF(m_wallPlatform10->pos(), m_wallPlatform10->boundingRect().size()), -1);
    m_bomb2->setPos(6100, m_groundLevel - m_bomb2->boundingRect().height()-190);
    addItem(m_bomb2);

    //===============================================
    // turtles
    //===============================================
    m_redTurtle = new GRedTurtle(QRectF(m_wallPlatform4->pos(), m_wallPlatform4->boundingRect().size()), -1);
    m_redTurtle->setPos(5100, m_groundLevel - m_redTurtle->boundingRect().height()+4);
    addItem(m_redTurtle);

    //===============================================
    // spiny
    //===============================================
    m_spiny = new GSpiny(QRectF(m_wallPlatform5->pos(), m_wallPlatform5->boundingRect().size()), -1);
    m_spiny->setPos(1345, m_groundLevel - m_spiny->boundingRect().height()+4);
    addItem(m_spiny);

    //===============================================
    // small_mario
    //===============================================
    m_smallPlayer = new GSmallMario;
    m_smallPlayer->setPos(50, m_groundLevel - m_smallPlayer->boundingRect().height() );
    addItem(m_smallPlayer);

    //===============================================
    // castle
    //===============================================
    h_castle = new GCastle;
    h_castle->setPos(7637, m_groundLevel - h_castle->boundingRect().height());
    addItem(h_castle);

    //===============================================

    startTimer(100);
}
//===============================================
void GScene::timerEvent(QTimerEvent* _event) {
    m_coins->nextFrame();
    m_coins2->nextFrame();
    m_coins3->nextFrame();
    m_coins4->nextFrame();
    m_coins5->nextFrame();
    m_coins6->nextFrame();
    m_coins7->nextFrame();
    m_coins8->nextFrame();
    m_coins9->nextFrame();
    m_coins10->nextFrame();
    m_coins11->nextFrame();
    m_coins12->nextFrame();
    m_coins13->nextFrame();
    m_coins14->nextFrame();
    m_coins15->nextFrame();
    m_coins16->nextFrame();
    m_coins17->nextFrame();
    m_coins18->nextFrame();
    m_coins19->nextFrame();
    m_coins20->nextFrame();
    m_coins21->nextFrame();
    m_coins22->nextFrame();
    m_coins23->nextFrame();
    m_coins24->nextFrame();
    m_coins25->nextFrame();
    m_coins26->nextFrame();

    m_coins27->nextFrame();
    m_coins28->nextFrame();
    m_coins29->nextFrame();
    m_coins30->nextFrame();

    m_coins32->nextFrame();
    m_coins33->nextFrame();
    m_coins34->nextFrame();
    m_coins35->nextFrame();
    m_coins36->nextFrame();

    m_coins37->nextFrame();
    m_coins38->nextFrame();
    m_coins39->nextFrame();
    m_coins40->nextFrame();
    m_coins41->nextFrame();
    m_coins42->nextFrame();
    m_coins43->nextFrame();
    m_coins44->nextFrame();
    m_coins45->nextFrame();
    m_coins46->nextFrame();
    m_coins47->nextFrame();

    m_coins48->nextFrame();
    m_coins49->nextFrame();
    m_coins50->nextFrame();
    m_coins51->nextFrame();
    m_coins52->nextFrame();

    m_coins53->nextFrame();
    m_coins54->nextFrame();
    m_coins55->nextFrame();
    m_coins56->nextFrame();

    m_coins57->nextFrame();
    m_coins58->nextFrame();
    m_coins59->nextFrame();
    m_coins60->nextFrame();

    m_coins61->nextFrame();
    m_coins62->nextFrame();
    m_coins63->nextFrame();
    m_coins64->nextFrame();
    m_coins65->nextFrame();
    m_coins66->nextFrame();
    m_coins67->nextFrame();
    m_coins68->nextFrame();

    m_coins69->nextFrame();
    m_coins70->nextFrame();
    m_coins71->nextFrame();

    m_coins72->nextFrame();
    m_coins73->nextFrame();
    m_coins74->nextFrame();

    m_coins75->nextFrame();
    m_coins76->nextFrame();
    m_coins77->nextFrame();
    m_coins78->nextFrame();
    m_coins79->nextFrame();
    m_coins80->nextFrame();

    m_coins81->nextFrame();
    m_coins82->nextFrame();
    m_coins83->nextFrame();
    m_coins84->nextFrame();
    m_coins85->nextFrame();
    m_coins86->nextFrame();

    m_coins87->nextFrame();
    m_coins88->nextFrame();
    m_coins89->nextFrame();
    m_coins90->nextFrame();
    m_coins91->nextFrame();
    m_coins92->nextFrame();
    m_coins93->nextFrame();
    m_coins94->nextFrame();
    m_coins95->nextFrame();
    m_coins96->nextFrame();
    m_coins97->nextFrame();
    m_coins98->nextFrame();
    m_coins99->nextFrame();
    m_coins100->nextFrame();

    m_questbox->nextFrame();
    m_questbox2->nextFrame();
    m_questbox3->nextFrame();
    m_questbox4->nextFrame();
    m_questbox5->nextFrame();
    m_questbox6->nextFrame();
    m_questbox7->nextFrame();
    m_questbox8->nextFrame();
    m_questbox9->nextFrame();
    m_questbox10->nextFrame();
    m_questbox11->nextFrame();
    m_questbox12->nextFrame();

    m_piranha->nextFrame();
    m_piranha2->nextFrame();
    m_piranha3->nextFrame();

    mBrickPlatform->nextFrame();
    mBrickPlatform2->nextFrame();
    mBrickPlatform3->nextFrame();
    mBrickPlatform4->nextFrame();
    mBrickPlatform5->nextFrame();
    mBrickPlatform6->nextFrame();
    mBrickPlatform7->nextFrame();
    mBrickPlatform8->nextFrame();

    m_NoteBox->nextFrame();
    m_NoteBox2->nextFrame();
    m_NoteBox3->nextFrame();
    m_NoteBox4->nextFrame();
    m_NoteBox5->nextFrame();
    m_NoteBox6->nextFrame();

    m_flag2->nextFrame();

    m_stretch->nextFrame();

    m_conveyor->nextFrame();
    m_conveyor2->nextFrame();
    m_conveyor3->nextFrame();

    m_giantgoomba->nextFrame();
    m_giantgoomba2->nextFrame();
    m_giantgoomba3->nextFrame();

    m_bomb2->nextFrame();
    m_redTurtle->nextFrame();
    m_spiny->nextFrame();
    mushroomQuestBox->nextFrame();
    flowerQuestBox->nextFrame();
}
//===============================================
void GScene::movePlayer() {
    qDebug() << "GScene::movePlayer...";
}
//===============================================
void GScene::fallPlayer() {
    qDebug() << "GScene::fallPlayer...";
}
//===============================================
