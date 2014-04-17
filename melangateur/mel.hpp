#ifndef MEL_HPP
#define MEL_HPP

#include <QtCore>
#include <QtGui>

class melClass : public QWidget
{
    Q_OBJECT
public:
    melClass();
    void melange(std::string msg);
private slots:
    void encod();
private:
    QTextEdit textencod;
    QTextEdit textdecod;
    std::string resul;
};

#endif // MEL_HPP
