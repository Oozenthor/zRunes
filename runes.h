#ifndef RUNES_H
#define RUNES_H

#include <QDialog>
#include <QPainter>
#include "zrunes.h"


namespace Ui {
class Runes;
}

class Runes : public QDialog
{
  Q_OBJECT

public:
  explicit Runes(QWidget *parent = 0);
  ~Runes();

private:
  Ui::Runes *ui;
};

#endif // RUNES_H
