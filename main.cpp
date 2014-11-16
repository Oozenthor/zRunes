#include "runes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Runes w;
  w.show();

  return a.exec();
}
