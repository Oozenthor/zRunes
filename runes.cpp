#include "runes.h"
#include "ui_runes.h"

Runes::Runes(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Runes)
{
  ui->setupUi(this);
  zRunes myrunes;
}

Runes::~Runes()
{
  delete ui;
}
