#ifndef ZRUNES_H
#define ZRUNES_H

#include <QString>
#include <QList>
#include <QTreeWidget>
#include <QXmlStreamReader>

//  ElderFuthark.xml

class zRunes
{
public:
  zRunes();
  ~zRunes();

  zRunes(QTreeWidget *treeWidget);

  bool read(QIODevice *device);
  QString errorString() const;

//  struct zRuneStruct {
//    zRuneStruct(QString sname, QString senglish, QString smeaning, bool sreversable)
//      :name(sname)
//      ,english (senglish)
//      ,meaning (smeaning)
//      ,reversable (sreversable)
//    {}
//        QString name;     /* English rune name */
//    QString english;     /* Equivilent english letter(s) */
//    QString meaning;     /* Runes significance */
//    bool reversable;        /* TRUE if rune reversable*/
    /*   char germanic; Germanic rune name */
    /*   char rev;       Reversed meaning */
//  };
  void readXmlRunes();

private:
//  void readName(QTreeWidgetItem *item);
//  void readSeparator(QTreeWidgetItem *item);
//  void readFolder(QTreeWidgetItem *item);
//  void readBookmark(QTreeWidgetItem *item);

//  QTreeWidgetItem *createChildItem(QTreeWidgetItem *item);

  QXmlStreamReader xml;
  QTreeWidget *treeWidget;

  QIcon folderIcon;
  QIcon bookmarkIcon;
};

#endif // ZRUNES_H
