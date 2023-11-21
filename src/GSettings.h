//===============================================
#ifndef _GSettings_
#define _GSettings_
//===============================================
#include "GObject.h"
//===============================================
class GSettings : public QDialog {
    Q_OBJECT

public:
    explicit GSettings(QWidget* _parent = 0);
    ~GSettings();
    void readSettings();
    void writeSettings();
    void setState();
    void revertState();
    void alterState();

private slots:
    void bgmChanged();
    void sfxChanged();
    void reject();
    void confirm();

signals:
    void fullScreen(bool);
    void bgmAdjust(int);
    void sfxAdjust(int);

private:
    bool m_isFullscreen;
    bool m_isWindow;
    int m_bgm;
    int m_sfx;

    QLabel *label;
    QLabel *bgmLabel;
    QLabel *sfxLabel;
    QLabel *screenSize;
    QLineEdit *lineEdit;
    QSlider *bgmSlider;
    QSlider *sfxSlider;
    QSpinBox *bgmSpinBox;
    QSpinBox *sfxSpinBox;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QRadioButton *windowedView;
    QRadioButton *fullScreenView;
};
//===============================================
#endif
//===============================================
