//===============================================
#ifndef _GSound_
#define _GSound_
//===============================================
#include "GObject.h"
//===============================================
class GSound : public QObject {
    Q_OBJECT

public:
    explicit GSound(QObject* _parent = 0);
    ~GSound();

public slots:
    void onPlaySound(const QString& _name);

private:
    QSoundEffect *mario_jump, *mario_death, *coin, *select, *levelClear, *ghost, *shrink, *powerup, *sprout, *fsprout, *kick, *fireball, *hitWarptube;
    QMediaPlayer *soundPlayer, *level1;
    QAudioOutput* audioOutput;
};
//===============================================
#endif
//===============================================
