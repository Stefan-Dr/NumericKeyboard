#ifndef KEYPAD_H
#define KEYPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Keypad;
}
QT_END_NAMESPACE

class Keypad : public QMainWindow
{
    Q_OBJECT

public:
    Keypad(QWidget *parent = nullptr);
    ~Keypad();

    inline Ui::Keypad* getUi(){ return ui;}

private slots:

    void onNumberClicked();
    void on_pbDot_clicked();
    void on_pbDelete_clicked();

private:
    Ui::Keypad *ui;
    bool dotClicked = false;
};
#endif // KEYPAD_H
