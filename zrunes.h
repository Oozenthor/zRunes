#ifndef ZRUNES_H
#define ZRUNES_H

// Rune data is held in ElderFuthark.xml
#define XMLDOCTYPE "ElderFuthark"
#define XMLVERSION "1.0"

#include <QDebug>
#include <QString>
#include <QList>
#include <QXmlStreamReader>


class ZRunes
{
public:
  ZRunes();
  ~ZRunes();

  bool xmlRead(QIODevice *device);
  QString errorString() const;

  struct zRuneStruct {
    int number;         // ElderFuthark alphabet position
    QString name;       // English rune name
    QString latin;      // Equivilent english letter(s)
    QString meaning;    // Runes significance
    QString divination; // Runes significance
    bool reverse;       // true if rune reversable
    int rank;           // Rune type rank
    QString type;       // rune type
    int order;          // Yggdrasil root order
    QString root;       // Yggdrasil root creature
    QString value;      // Unicode address
    QString UTF;        // Unicode character
  };

  QList<zRuneStruct> all;

  void readXmlRunes();

private:
  void readXmlContents();
  void readRune();

  QXmlStreamReader xml;
};

#endif // ZRUNES_H
