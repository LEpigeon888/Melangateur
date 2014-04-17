#include "mel.hpp"
#include <time.h>

melClass::melClass()
{
    QPushButton *trad = new QPushButton("Mélanger");

    trad->setAutoDefault(true);
    textdecod.setTabChangesFocus(true);
    textencod.setReadOnly(true);

    QVBoxLayout *princBox = new QVBoxLayout;
    princBox->addWidget(&textdecod);
    princBox->addWidget(trad);
    princBox->addWidget(&textencod);

    setLayout(princBox);
    setWindowTitle("Mélangateur");

    connect(trad, SIGNAL(clicked()), this, SLOT(encod()));
}

void melClass::encod()
{
    std::string phrase = textdecod.toPlainText().replace(",", " , ").replace(". ", " . ").replace(".\n", " .\n").toStdString(), msg, carac;
    phrase.append(" ");
    while(!phrase.empty())
    {
        msg = phrase.substr(0, phrase.find_first_of(" \n"));
        carac = phrase[phrase.find_first_of(" \n")];
        phrase.erase(0, phrase.find_first_of(" \n") + 1);
        melange(msg);
        resul.append(carac);
    }
    textencod.setText(QString::fromStdString(resul).replace(" , ", ",").replace(" . ", ". ").replace(" .\n", ".\n"));
    resul = "";
}

void melClass::melange(std::string msg)
{
    int num = 0;
    std::string tmp;
    srand(time(NULL));
    while(!msg.empty())
    {
        num = rand() % msg.size();
        tmp = msg[num];
        resul.append(tmp);
        msg.erase(num, 1);
    }
}
