//===============================================
#include "GSettings.h"
//===============================================
GSettings::GSettings(QWidget* _parent)
: QDialog(_parent) {
    label = new QLabel(tr("Identifiant du développeur : "));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    bgmLabel = new QLabel(tr("Musique : "));
    bgmSlider = new QSlider(Qt::Horizontal);
    bgmSpinBox = new QSpinBox;
    bgmSlider->setRange(0, 100);
    bgmSpinBox->setRange(0, 100);

    sfxLabel = new QLabel(tr("Effets sonores : "));
    sfxSlider = new QSlider(Qt::Horizontal);
    sfxSpinBox = new QSpinBox;
    sfxSlider->setRange(0, 100);
    sfxSpinBox->setRange(0, 100);

    screenSize = new QLabel(tr("Plein écran : "));
    fullScreenView = new QRadioButton("On");
    windowedView = new QRadioButton("Off");
    windowedView->setChecked(true);

    confirmButton = new QPushButton(tr("Confirmer"));
    cancelButton = new QPushButton(tr("Annuler"));

    connect(bgmSpinBox, SIGNAL(valueChanged(int)), bgmSlider, SLOT(setValue(int)));
    connect(bgmSlider, SIGNAL(valueChanged(int)), bgmSpinBox, SLOT(setValue(int)));
    connect(bgmSlider, SIGNAL(valueChanged(int)), this, SLOT(bgmChanged()));
    connect(sfxSpinBox, SIGNAL(valueChanged(int)), sfxSlider, SLOT(setValue(int)));
    connect(sfxSlider, SIGNAL(valueChanged(int)), sfxSpinBox, SLOT(setValue(int)));
    connect(sfxSlider, SIGNAL(valueChanged(int)), this, SLOT(sfxChanged()));
    connect(confirmButton, SIGNAL(clicked(bool)), this, SLOT(confirm()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));

    QHBoxLayout *firstLayout = new QHBoxLayout;
    firstLayout->addWidget(label);
    firstLayout->addWidget(lineEdit);

    QHBoxLayout *secondLayout = new QHBoxLayout;
    secondLayout->addWidget(screenSize);
    secondLayout->addStretch();
    secondLayout->addWidget(fullScreenView);
    secondLayout->addWidget(windowedView);

    QHBoxLayout *thirdLayout = new QHBoxLayout;
    thirdLayout->addWidget(bgmLabel);
    thirdLayout->addWidget((bgmSlider));
    thirdLayout->addWidget(bgmSpinBox);

    QHBoxLayout *fourthLayout = new QHBoxLayout;
    fourthLayout->addWidget(sfxLabel);
    fourthLayout->addWidget((sfxSlider));
    fourthLayout->addWidget(sfxSpinBox);

    QHBoxLayout *fifthLayout = new QHBoxLayout;
    fifthLayout->addWidget(confirmButton);
    fifthLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);
    mainLayout->addLayout(thirdLayout);
    mainLayout->addLayout(fourthLayout);
    mainLayout->addLayout(fifthLayout);

    setLayout(mainLayout);
    setWindowModality(Qt::WindowModal);
    setWindowTitle("Paramètres");
}
//===============================================
GSettings::~GSettings() {

}
//===============================================
void GSettings::readSettings() {
    QSettings settings("ReadyTeam", "ReadyApp");
    fullScreenView->setChecked(settings.value("fullscreen", false).toBool());
    bgmSlider->setValue(settings.value("bgm", 50).toInt());
    sfxSlider->setValue(settings.value("sfx", 50).toInt());
    confirm();
}
//===============================================
void GSettings::writeSettings() {
    QSettings settings("ReadyTeam", "ReadyApp");
    settings.setValue("fullscreen", fullScreenView->isChecked());
    settings.setValue("bgm", bgmSlider->value());
    settings.setValue("sfx", sfxSlider->value());
}
//===============================================
void GSettings::setState() {
    m_isFullscreen = fullScreenView->isChecked();
    m_isWindow = windowedView->isChecked();
    m_bgm = bgmSlider->value();
    m_sfx = sfxSlider->value();
}
//===============================================
void GSettings::revertState() {
    fullScreenView->setChecked(m_isFullscreen);
    windowedView->setChecked(m_isWindow);
    bgmSlider->setValue(m_bgm);
    sfxSlider->setValue(m_sfx);
}
//===============================================
void GSettings::bgmChanged() {
    qDebug() << "GSettings::bgmChanged...";
}
//===============================================
void GSettings::sfxChanged() {
    qDebug() << "GSettings::sfxChanged...";
}
//===============================================
void GSettings::reject() {
    revertState();
    QDialog::reject();
}
//===============================================
void GSettings::confirm() {
    setState();
    close();
    emit fullScreen(fullScreenView->isChecked());
    emit bgmAdjust(bgmSlider->value());
    emit sfxAdjust(sfxSlider->value());
}
//===============================================
void GSettings::alterState() {
    if(m_isFullscreen){
        windowedView->setChecked(true);
    }
    else {
        fullScreenView->setChecked(true);
    }
    confirm();
}
//===============================================
