TEMPLATE = app
CONFIG += console c++17
QT += widgets multimedia

QT_MEDIA_BACKEND=ffmpeg

SOURCES += \
    GBackground.cpp \
    GBomb.cpp \
    GBrick.cpp \
    GCastle.cpp \
    GCoin.cpp \
    GConveyor.cpp \
    GCounter.cpp \
    GFlag.cpp \
    GFlower.cpp \
    GGiantGoomba.cpp \
    GGoomba.cpp \
    GHome.cpp \
    GMainWindow.cpp \
    GMushroom.cpp \
    GNote.cpp \
    GPiranha.cpp \
    GQuestion.cpp \
    GRedTurtle.cpp \
    GScene.cpp \
    GScore.cpp \
    GSettings.cpp \
    GSmallMario.cpp \
    GSound.cpp \
    GSpiny.cpp \
    GStairBlock.cpp \
    GStretch.cpp \
    GTimer.cpp \
    GTurtle.cpp \
    GView.cpp \
    GWall.cpp \
    GWarpTube.cpp \
    main.cpp \
    qmediaplaylist.cpp \
    qmediaplaylist_p.cpp \
    qplaylistfileparser.cpp


HEADERS += \
    GAnimation.h \
    GBackground.h \
    GBomb.h \
    GBrick.h \
    GCastle.h \
    GCoin.h \
    GConveyor.h \
    GCounter.h \
    GFlag.h \
    GFlower.h \
    GGiantGoomba.h \
    GGoomba.h \
    GHome.h \
    GInclude.h \
    GMainWindow.h \
    GMushroom.h \
    GNote.h \
    GPiranha.h \
    GQuestion.h \
    GRedTurtle.h \
    GScene.h \
    GScore.h \
    GSettings.h \
    GSmallMario.h \
    GSound.h \
    GSpiny.h \
    GStairBlock.h \
    GStretch.h \
    GTimer.h \
    GTurtle.h \
    GView.h \
    GWall.h \
    GWarpTube.h \
    qmediaplaylist.h \
    qmediaplaylist_p.h \
    qplaylistfileparser.h

RESOURCES += \
    resources.qrc
