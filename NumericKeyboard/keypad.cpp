#include "keypad.h"
#include "./ui_keypad.h"

Keypad::Keypad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Keypad)
{
    ui->setupUi(this);
    this->setFixedSize(400, 250);

    for (int i = 0; i <= 9; i++){
        QString buttonName = QString("pb%1").arg(i);
        auto button = findChild<QPushButton*>(buttonName);

        if (button){
            connect(button, &QPushButton::clicked, this, &Keypad::onNumberClicked);
        }
    }
}

Keypad::~Keypad()
{
    delete ui;
}

void Keypad::onNumberClicked(){
    auto button = qobject_cast<QPushButton*>(sender());
    auto buttonText = button->text();
    //prevents adding a text that aren't numbers in case QPushButton text is changed
    if (buttonText.length() != 1 || !buttonText[0].isDigit()){
        return;
    }

    ui->lineEdit->insert(buttonText);
}

void Keypad::on_pbDot_clicked()
{
    if (!dotClicked){
        ui->lineEdit->insert(".");
        dotClicked = true;
    }
}

void Keypad::on_pbDelete_clicked()
{
    QString text = ui->lineEdit->text();
    if (text.isEmpty()) return;

    text.chop(1);
    ui->lineEdit->setText(text);
    if (!text.contains('.')) dotClicked = false;

}

