#ifndef RUNES_H
#define RUNES_H

#define XML_FILE "ElderFuthark.xml"

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QTextBrowser>
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

private slots:
  void on_loadButton_clicked();

private:
  Ui::Runes *ui;
  ZRunes xmlContents;
};

#endif // RUNES_H

