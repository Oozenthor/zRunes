#include "runes.h"
#include "ui_runes.h"

Runes::Runes(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Runes)
{
  ui->setupUi(this);
  ui->textBrowser->setFontPointSize(18);

  QFile file("ElderFuthark.xml");

  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Cannot read file";
    return;
  }

  qDebug() << "File loading";
  if (!xmlContents.xmlRead(&file)) {
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
  foreach(ZRunes::zRuneStruct xml, xmlContents.zRuneList) {
   ui->textBrowser->append(xml.name + " " + xml.UTF);
 }
// ui->textBrowser->append("Done");
}
