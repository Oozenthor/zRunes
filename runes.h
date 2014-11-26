#ifndef RUNES_H
#define RUNES_H

#define XML_FILE "G:/QtGit/zRunes/ElderFuthark.xml"

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QDir>
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

  void on_lastButton_clicked();

  void on_nextButton_clicked();

private:
  Ui::Runes *ui;
  ZRunes rn;

  int runeNum;
};

#endif // RUNES_H

