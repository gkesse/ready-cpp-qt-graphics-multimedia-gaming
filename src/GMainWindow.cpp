//===============================================
#include "GMainWindow.h"
#include "GView.h"
#include "GHome.h"
#include "GSettings.h"
//===============================================
GMainWindow::GMainWindow(QWidget* _parent)
: QMainWindow(_parent)  {
    createActions();
    createMenus();
    createScene();
    setCentralWidget(m_view);
    setWindowTitle("ReadyApp");
}
//===============================================
GMainWindow::~GMainWindow() {

}
//===============================================
void GMainWindow::setSize() {
    setFixedSize(1280, 740);
    int x = ((QGuiApplication::primaryScreen()->geometry().width() - width()) / 2);
    int y = ((QGuiApplication::primaryScreen()->geometry().height() - height()) / 2);
    move(x, y);
}
//===============================================
void GMainWindow::createActions() {
    returnAction = new QAction(tr("&Revenir au titre"), this);
    returnAction->setShortcut(tr("Ctrl+R"));
    returnAction->setStatusTip(tr("Revenir à l'écran titre"));

    for(int i=0; i< MAX_STATE; ++i){
        saveStateAction[i] = new QAction("-Empty-", this);
        loadStateAction[i] = new QAction("-Empty-", this);
    }

    quitAction = new QAction(tr("&Fermer"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Fermer"));
    connect(quitAction, &QAction::triggered, this, &GMainWindow::close);

    weatherStationAction = new QAction(tr("&Date et Heure"), this);
    weatherStationAction->setShortcut(tr("Ctrl+w"));
    weatherStationAction->setStatusTip(tr("Date et Heure"));
    connect(weatherStationAction , &QAction::triggered, this, &GMainWindow::showWeather);

    fullScreenAction = new QAction(tr("Plein écran"), this);
    fullScreenAction->setShortcut(tr("F11"));
    fullScreenAction->setStatusTip(tr("Affichage plein écran"));
    connect(fullScreenAction, &QAction::triggered, this, &GMainWindow::alterScreen);

    settingsAction = new QAction(tr("&Paramétrages"), this);
    settingsAction->setStatusTip(tr("Modifier les paramètres du jeu"));
    connect(settingsAction, &QAction::triggered, this, &GMainWindow::settings);

    aboutAction = new QAction(tr("&À propos"), this);
    connect(aboutAction, &QAction::triggered, this, &GMainWindow::showAbout);

    m_setting = new GSettings(this);
    m_setting->readSettings();
}
//===============================================
void GMainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&Fichier"));

    fileMenu->addAction(returnAction);
    saveSubMenu = fileMenu->addMenu(tr("&Enregistrer"));
    loadSubMenu = fileMenu->addMenu(tr("&Charger"));

    for(int i=0; i < MAX_STATE; i++){
        saveSubMenu->addAction(saveStateAction[i]);
        loadSubMenu->addAction(loadStateAction[i]);
    }

    fileMenu->addAction(quitAction);

    viewMenu = menuBar()->addMenu(tr("&Affichage"));
    viewMenu->addAction(fullScreenAction);

    toolMenu = menuBar()->addMenu(tr("&Outils"));
    toolMenu->setToolTip("Paramètres du jeu");
    toolMenu->addAction(settingsAction);

    helpMenu = menuBar()->addMenu(tr("&Aide"));
    helpMenu->setToolTip("Info du développeur");
    helpMenu->addAction(aboutAction);

    weatherMenu = menuBar()->addMenu(tr("&UDP"));
    weatherMenu->setToolTip("UDP");
    weatherMenu->addAction(weatherStationAction);
}
//===============================================
void GMainWindow::createScene() {
    m_view = new GView(this);
    m_home = new GHome(m_view);
}
//===============================================
void GMainWindow::showWeather() {

}
//===============================================
void GMainWindow::alterScreen() {
    m_setting->alterState();
}
//===============================================
void GMainWindow::settings() {
    m_setting->setState();
    m_setting->show();
}
//===============================================
void GMainWindow::showAbout() {

}
//===============================================
void GMainWindow::closeEvent(QCloseEvent* _event){
    m_setting->writeSettings();
    _event->accept();
}
//===============================================
