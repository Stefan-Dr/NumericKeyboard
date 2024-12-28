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

    auto text = ui->textEdit->toPlainText();
    text.append(buttonText);
    ui->textEdit->setPlainText(text);
}

void Keypad::on_pbDot_clicked()
{
    if (!dotClicked){
        QString text = ui->textEdit->toPlainText();
        text.append(ui->pbDot->text());
        ui->textEdit->setPlainText(text);
        dotClicked = true;
    }
}

void Keypad::on_pbDelete_clicked()
{
    QString text = ui->textEdit->toPlainText();
    if (text.isEmpty()) return;

    text.chop(1);
    ui->textEdit->setPlainText(text);
    if (!text.contains('.')) dotClicked = false;

}

