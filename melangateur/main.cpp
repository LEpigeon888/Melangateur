#include <QApplication>
#include "mel.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    melClass *mel = new melClass;
    mel->show();

    return app.exec();
}

