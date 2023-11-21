//===============================================
#include "GMainWindow.h"
//===============================================
int main(int _argc, char** _argv) {
    QApplication lApp(_argc, _argv);
    lApp.setWindowIcon(QIcon(":/img/icon.ico"));

    QSplashScreen* lSplash = new QSplashScreen;
    lSplash->setPixmap(QPixmap(":/img/mariosplash.png"));
    lSplash->show();

    GMainWindow lWindow;
    lWindow.setSize();

    QTimer::singleShot(500, lSplash, &QSplashScreen::close);
    QTimer::singleShot(500, &lWindow, &GMainWindow::show);

    return lApp.exec();
}
//===============================================
