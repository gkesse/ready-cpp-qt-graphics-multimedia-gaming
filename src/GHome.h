//===============================================
#ifndef _GHome_
#define _GHome_
//===============================================
#include "GObject.h"
//===============================================
class GView;
class GScene;
class GAnimation;
class GSound;
//===============================================
class GHome : public QGraphicsScene {
    Q_OBJECT

public:
    explicit GHome(GView* _view, QWidget* _parent = 0);
    ~GHome();

public slots:
     void login();
     void newUser();
     void developerLogin();
     void on_radioButton_toggled(bool checked);
     void quitProgram();

private:
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;

signals:
    void playSound(const QString& _name);

private:
    GView* m_view;
    QScrollBar* m_scroll;
    GAnimation* background;
    QGraphicsPixmapItem *foreground;
    QGraphicsPixmapItem *logo;
    QPropertyAnimation* animation;

    QPushButton *loginButton;
    QPushButton *developerButton;
    QPushButton *quitButton;
    QPushButton *newUserButton;

    QLineEdit *userLine;
    QLineEdit *passLine;

    QLabel *userName;
    QLabel *password;

    QRadioButton *radioButton;
    QLabel *radioText;

    GSound* soundManager;
    GScene* scene;
};
//===============================================
#endif
//===============================================
