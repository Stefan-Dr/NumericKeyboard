#include "keypad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Keypad w;
    w.show();
    return a.exec();
}
