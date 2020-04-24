#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMainWindow>

namespace Ui {
class converter;
}

class converter : public QMainWindow
{
    Q_OBJECT

public:
    explicit converter(QWidget *parent = nullptr);
    ~converter();

private slots:
    void on_pushButton_clicked();

private:
    Ui::converter *ui;

std::string numtowords(int, std::string);

std::string convert(long);
};

#endif // CONVERTER_H
