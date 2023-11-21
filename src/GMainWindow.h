//===============================================
#ifndef _GMainWindow_
#define _GMainWindow_
//===============================================
#include "GObject.h"
//===============================================
class GView;
class GHome;
class GSettings;
//===============================================
class GMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GMainWindow(QWidget* _parent = nullptr);
    ~GMainWindow();
    void setSize();

private:
    void createActions();
    void createMenus();
    void createScene();

public slots:
    void showWeather();
    void alterScreen();
    void settings();
    void showAbout();

protected:
    void closeEvent(QCloseEvent* _event);

private:
    enum { MAX_STATE = 10 };

private:
    GView* m_view;
    GHome* m_home;
    GSettings* m_setting;

    QAction *returnAction;
    QAction *emptyAction;
    QAction *saveStateAction[MAX_STATE];
    QAction *loadStateAction[MAX_STATE];
    QAction *quitAction;
    QAction *fullScreenAction;
    QAction *settingsAction;
    QAction *aboutAction;
    QAction *weatherStationAction;

    QMenu *fileMenu;
    QMenu *saveSubMenu;
    QMenu *loadSubMenu;
    QMenu *viewMenu;
    QMenu *toolMenu;
    QMenu *helpMenu;
    QMenu *weatherMenu;
};
//===============================================
#endif
//===============================================
