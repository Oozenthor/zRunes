#include "zrunes.h"
#include <QDebug>

zRunes::zRunes()
{
}

zRunes::~zRunes()
{

}

zRunes::zRunes(QTreeWidget *treeWidget): treeWidget(treeWidget)
{
      QStyle *style = treeWidget->style();

      folderIcon.addPixmap(style->standardPixmap(QStyle::SP_DirClosedIcon),
                           QIcon::Normal, QIcon::Off);
      folderIcon.addPixmap(style->standardPixmap(QStyle::SP_DirOpenIcon),
                           QIcon::Normal, QIcon::On);
      bookmarkIcon.addPixmap(style->standardPixmap(QStyle::SP_FileIcon));
}

bool zRunes::read(QIODevice *device)
{
  xml.setDevice(device);

  if (xml.readNextStartElement()) {
      if (xml.name() == "ElderFuthark" && xml.attributes().value("version") == "1.0")
          readXmlRunes();
      else
          xml.raiseError(QObject::tr("The file is not an ElderFuthark version 1.0 file."));
  }
  return !xml.error();
}

QString zRunes::errorString() const
{
  return QObject::tr("%1\nLine %2, column %3")
          .arg(xml.errorString())
          .arg(xml.lineNumber())
          .arg(xml.columnNumber());
}

void zRunes::readXmlRunes()
{
  qDebug() << "read runes";

}
