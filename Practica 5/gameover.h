#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

namespace Ui {
class Gameover;
}

class Gameover : public QWidget
{
    Q_OBJECT

public:
    explicit Gameover(QWidget *parent = nullptr);
    ~Gameover();

private:
    Ui::Gameover *ui;
};

#endif // GAMEOVER_H
