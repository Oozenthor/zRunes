#include "runes.h"
#include "ui_runes.h"

Runes::Runes(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Runes)
{
  ui->setupUi(this);
  ui->textBrowser->setFontPointSize(18);
  runeNum = 0;

  QFile file(XML_FILE);

  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Cannot read file";
    return;
  }

  qDebug() << "File loading";
  if (!rn.xmlRead(&file)) {
    qDebug() << "Parse error in file";
  } else {
    qDebug() << "File loaded";
  }
}

Runes::~Runes()
{
  delete ui;
}

void Runes::on_loadButton_clicked()
{
  foreach(ZRunes::zRuneStruct xml, rn.all) {
   ui->textBrowser->append(xml.name + " " + xml.UTF);
 }
  ui->runeEdit->setText(rn.all.at(runeNum).UTF);
}

void Runes::on_lastButton_clicked()
{
  runeNum -= 1;
  if (runeNum < 0) {
    runeNum = rn.all.size() - 1;
  }
  ui->runeEdit->setText(rn.all.at(runeNum).UTF);
}

void Runes::on_nextButton_clicked()
{
  runeNum += 1;
  qDebug() << runeNum;
  if (runeNum > rn.all.size() - 1) {
    runeNum = 0;
  }
  ui->runeEdit->setText(rn.all.at(runeNum).UTF);
}
