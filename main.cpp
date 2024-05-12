#include "geometrygame.h"
#include <QApplication>
#include <QtMultimedia/QSoundEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    geometryGame w;
    w.show();
    QSoundEffect* effect = new QSoundEffect;
    effect->setSource(QUrl::fromLocalFile(":/audio/backgroungmusic.wav"));
    effect->setLoopCount(QSoundEffect::Infinite); //循环次数
    effect->setVolume(0.1f); //音量 0~1之间
    effect->play();
    return a.exec();
}
