#ifndef RUNES_H
#define RUNES_H

#include <QDebug>
#include <QDialog>
#include <QPainter>
//#include <QTreeWidget>
#include <QFileDialog>
#include <QMessageBox>
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


public slots:
//    void open();
//    void about();
//    void saveAs();

private slots:
  void on_loadButton_clicked();

private:
  Ui::Runes *ui;

//  void createActions();
//  void createMenus();

//  QTreeWidget *treeWidget;

//  zRunes *reader;
  QMenu *fileMenu;
  QMenu *helpMenu;
  QAction *openAct;
  QAction *saveAsAct;
  QAction *exitAct;
  QAction *aboutAct;
  QAction *aboutQtAct;
};

#endif // RUNES_H

