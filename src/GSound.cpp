//===============================================
#include "GSound.h"
//===============================================
GSound::GSound(QObject* _parent)
: QObject(_parent) {
    audioOutput = new QAudioOutput;

    select = new QSoundEffect;
    select->setSource(QUrl("qrc:/audio/Select.wav"));
    select->setLoopCount(0);
    select->setVolume(.25f);

    coin = new QSoundEffect;
    coin->setSource(QUrl("qrc:/audio/coin.wav"));
    coin->setLoopCount(0);
    coin->setVolume(.25f);

    mario_jump = new QSoundEffect;
    mario_jump->setSource(QUrl("qrc:/audio/jump.wav"));
    mario_jump->setLoopCount(0);
    mario_jump->setVolume(.25f);

    mario_death = new QSoundEffect;
    mario_death->setSource(QUrl("qrc:/audio/death.wav"));
    mario_death->setLoopCount(0);
    mario_death->setVolume(.25f);

    levelClear = new QSoundEffect;
    levelClear->setSource(QUrl("qrc:/audio/levelclear.wav"));
    levelClear->setLoopCount(0);
    levelClear->setVolume(.25f);

    ghost = new QSoundEffect;
    ghost->setSource(QUrl("qrc:/audio/ghost.wav"));
    ghost->setLoopCount(0);
    ghost->setVolume(.25f);

    shrink = new QSoundEffect;
    shrink->setSource(QUrl("qrc:/audio/shrink.wav"));
    shrink->setLoopCount(0);
    shrink->setVolume(.25f);

    powerup = new QSoundEffect;
    powerup->setSource(QUrl("qrc:/audio/powerup.wav"));
    powerup->setLoopCount(0);
    powerup->setVolume(.25f);

    sprout = new QSoundEffect;
    sprout->setSource(QUrl("qrc:/audio/sprout.wav"));
    sprout->setLoopCount(0);
    sprout->setVolume(.25f);

    fsprout = new QSoundEffect;
    fsprout->setSource(QUrl("qrc:/audio/sprout.wav"));
    fsprout->setLoopCount(0);
    fsprout->setVolume(.25f);

    kick = new QSoundEffect;
    kick ->setSource(QUrl("qrc:/audio/kick.wav"));
    kick ->setLoopCount(0);
    kick ->setVolume(.25f);

    fireball = new QSoundEffect;
    fireball->setSource(QUrl("qrc:/audio/fireball.wav"));
    fireball->setLoopCount(0);
    fireball->setVolume(.25f);

    hitWarptube = new QSoundEffect;
    hitWarptube->setSource(QUrl("qrc:/audio/hitwarptube.wav"));
    hitWarptube->setLoopCount(0);
    hitWarptube->setVolume(.25f);

    level1 = new QMediaPlayer;
    level1->setAudioOutput(audioOutput);
    level1->setSource(QUrl("qrc:/audio/level1.mp3"));

    soundPlayer = new QMediaPlayer;
    soundPlayer->setAudioOutput(audioOutput);
    soundPlayer->setSource(QUrl("qrc:/audio/ThemeSong.mp3"));
}
//===============================================
GSound::~GSound() {

}
//===============================================
void GSound::onPlaySound(const QString& _name) {
    if(_name == "mario_jump"){
        mario_jump->play();
    }
    else if(_name == "mario_death") {
        level1->stop();
        mario_death->play();
    }
    else if(_name == "coin") {
        coin->play();
    }
    else if(_name == "select") {
        select->play();
    }
    else if(_name == "theme") {
        soundPlayer->play();
    }
    else if(_name == "level1") {
        level1->play();
    }
    else if(_name == "stopMusic") {
        soundPlayer->stop();
    }
    else if(_name == "stopLevelMusic") {
        level1->stop();
    }
    else if(_name == "levelClear") {
        levelClear->play();
    }
    else if(_name == "ghost") {
        ghost->play();
    }
    else if(_name == "shrink") {
        shrink->play();
    }
    else if(_name == "powerup") {
        powerup->play();
    }
    else if(_name == "sprout") {
        sprout->play();
    }
    else if(_name == "fsprout") {
        fsprout->play();
    }
    else if(_name == "kick") {

        kick->play();
    }
    else if(_name == "fireball") {
        fireball->play();
    }
    else if(_name == "hitWarptube") {
        hitWarptube->play();
    }
    else {
        qDebug() << "Le fichier audio n'est pas chargé: " << _name;
    }
}
//===============================================
