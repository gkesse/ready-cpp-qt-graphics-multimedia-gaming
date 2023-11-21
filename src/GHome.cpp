//===============================================
#include "GHome.h"
#include "GView.h"
#include "GScene.h"
#include "GAnimation.h"
#include "GSound.h"
//===============================================
GHome::GHome(GView* _view, QWidget* _parent)
: QGraphicsScene(_parent)
, m_view(_view) {
    m_view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    m_scroll = m_view->horizontalScrollBar();

    background = new GAnimation;
    background->setPixmap(QPixmap(":/img/background.png"));
    foreground = new QGraphicsPixmapItem(QPixmap(":/img/title.png"));
    logo = new QGraphicsPixmapItem(QPixmap(":/img/logo.png"));

    animation = new QPropertyAnimation(background, "pos");
    animation->setLoopCount(-1);
    animation->setDuration(150000);
    animation->setStartValue(QPoint(-WIDTH, 0));
    animation->setEndValue(QPoint(0,0));
    animation->start();

    logo->setPos((WIDTH - logo->boundingRect().width()) / 2, HEIGHT / 12);

    addItem(background);
    addItem(foreground);
    addItem(logo);

    setFocus();
    setSceneRect(0, 0, WIDTH, HEIGHT);
    m_view->setScene(this);

    loginButton = new QPushButton(m_view);
    loginButton->setText("Se connecter");
    loginButton->setToolTip("Cliquez pour vous connecter");
    loginButton->setGeometry(QRect(540, 500, 100, 32));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(login()));

    developerButton = new QPushButton(m_view);
    developerButton->setText("Connexion invité");
    developerButton->setToolTip("Connectez-vous en tant qu'invité");
    developerButton->setGeometry(QRect(540, 535, 100, 32));
    connect(developerButton, SIGNAL(clicked()), this, SLOT(developerLogin()));

    quitButton = new QPushButton(m_view);
    quitButton->setText("Quitter");
    quitButton->setToolTip("Quitter le programme");
    quitButton->setGeometry(QRect(642, 535, 100, 32));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitProgram()));

    newUserButton = new QPushButton(m_view);
    newUserButton->setText("S'inscrire");
    newUserButton->setToolTip("Cliquez pour créer un identifiant");
    newUserButton->setGeometry(QRect(642, 500, 100, 32));
    connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUser()));

    userLine = new QLineEdit(m_view);
    userLine->setToolTip("Entrez une adresse email");
    userLine->setGeometry(QRect(540, 420, 200, 25));

    QFont font("MV Boli", 15, QFont::Bold);
    userName = new QLabel(m_view);
    userName->setFont(font);
    userName->setText("Email");
    userName->setGeometry(QRect(430, 420, 100, 25));

    passLine = new QLineEdit(m_view);
    passLine->setEchoMode(QLineEdit::Password);
    passLine->setToolTip("Entrez le mot de passe");
    passLine->setGeometry(QRect(540, 450, 200, 25));

    password = new QLabel(m_view);
    password->setFont(font);
    password->setText("Password");
    password->setGeometry(QRect(430, 450, 100, 25));

    radioButton = new QRadioButton(m_view);
    radioButton->setToolTip("Cliquez pour afficher le texte du mot de passe");
    radioButton->setGeometry(QRect(760, 450, 100, 25));
    connect(radioButton, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_toggled(bool)));

    radioText = new QLabel(m_view);
    radioText->setText("Afficher");
    radioText->setToolTip("Cliquez pour afficher le texte du mot de passe");
    radioText->setGeometry(QRect(780, 450, 100, 25));
    radioText->setBuddy(radioButton);

    soundManager = new GSound;
    connect(this, &GHome::playSound, soundManager, &GSound::onPlaySound);
    emit playSound("theme");
}
//===============================================
GHome::~GHome() {

}
//===============================================
void GHome::login() {

}
//===============================================
void GHome::newUser() {

}
//===============================================
void GHome::developerLogin() {
    loginButton->close();
    newUserButton->close();
    passLine->close();
    userLine->close();
    userName->close();
    password->close();
    radioButton->close();
    radioText->close();
    developerButton->close();
    quitButton->close();

    scene = new GScene(m_scroll, this);
    m_view->setScene(scene);
    emit playSound("stopMusic");
}
//===============================================
void GHome::on_radioButton_toggled(bool checked) {

}
//===============================================
void GHome::quitProgram() {

}
//===============================================
