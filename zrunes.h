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
    QString name;     // English rune name
    QString letter;   // Equivilent english letter(s)
    QString meaning;  // Runes significance
    bool reverse;     // true if rune reversable
    QString UTFValue; // Unicode address
    QString UTF;      // Unicode character
  };

  QList<zRuneStruct> zRuneList;

  void readXmlRunes();

private:
  void readXmlContents();
  void readRune();

  QXmlStreamReader xml;
};

#endif // ZRUNES_H
