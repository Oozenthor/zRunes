#include "runes.h"
#include "ui_runes.h"

Runes::Runes(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Runes)
{
  ui->setupUi(this);

  QStringList labels;
  labels << tr("Title") << tr("Location");
  ui->treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
  ui->treeWidget->setHeaderLabels(labels);

  QString fileName = QFileDialog::getOpenFileName(
    this, tr("Open Rune File"), QDir::currentPath(), tr("Rune xml Files (*.xml)"));
  qDebug() << "1";
  if (fileName.isEmpty()) {
    return;
  }

  ui->treeWidget->clear();

  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, tr("QXmlStream Runes"),
                         tr("Cannot read file %1:\n%2.")
                         .arg(fileName)
                         .arg(file.errorString()));
    return;
  }

  qDebug() << "2";
  zRunes reader(ui->treeWidget);
  if (!reader.read(&file)) {
    QMessageBox::warning(this, tr("QXmlStream Runes"),
                         tr("Parse error in file %1:\n\n%2")
                         .arg(fileName)
                         .arg(reader.errorString()));
  } else {
    //      statusBar()->showMessage(tr("File loaded"), 2000);
    qDebug() << "File loaded";
  }

}

Runes::~Runes()
{
  qDebug() << "4";
  delete ui;
}

void Runes::on_loadButton_clicked()
{
  zRunes reader(ui->treeWidget);
  reader.readXmlRunes();
}
