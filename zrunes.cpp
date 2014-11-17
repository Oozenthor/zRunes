#include "zrunes.h"
#include <QDebug>

ZRunes::ZRunes()
{
}

ZRunes::~ZRunes()
{
}

bool ZRunes::xmlRead(QIODevice *device)
{
  xml.setDevice(device); // Set read position to start of file
  if (xml.readNextStartElement()) { // Find first level (root) xml tag
    qDebug() << "Root Name" << xml.name();
    if (xml.name() == XMLDOCTYPE && xml.attributes().value("version") == XMLVERSION) {
      readXmlContents();
    } else {
      qDebug() << "File has incorrect DocType /  Version.";
      xml.raiseError(QObject::tr("File has incorrect DocType /  Version."));
    }
  }
  return !xml.error();
}

QString ZRunes::errorString() const
{
  return QObject::tr("%1\nLine %2, column %3")
      .arg(xml.errorString())
      .arg(xml.lineNumber())
      .arg(xml.columnNumber());
}

void ZRunes::readXmlContents()
{
  qDebug() << "Read runes";

  Q_ASSERT(xml.isStartElement() && xml.name() == XMLDOCTYPE);

  while (xml.readNextStartElement()) {
    if (xml.name() == "Rune") {
//      qDebug() << xml.name();
      readRune();
    } else {
      xml.skipCurrentElement();
    }
  }
}

void ZRunes::readRune()
{
  zRuneStruct data;

  Q_ASSERT(xml.isStartElement() && xml.name() == "Rune");

  while (xml.readNextStartElement()) {
    if (xml.name() == "Name")
      data.name = xml.readElementText();
    else if (xml.name() == "Letter")
      data.letter = xml.readElementText();
    else if (xml.name() == "Meaning")
      data.meaning = xml.readElementText();
    else if (xml.name() == "Reverse") {
      if (xml.readElementText() == "true") {
        data.reverse = true;
      } else {
        data.reverse = false;
      }
    }
    else if (xml.name() == "UTFValue")
      data.UTFValue = xml.readElementText();
    else if (xml.name() == "UTF")
      data.UTF = xml.readElementText();
    else
      xml.skipCurrentElement();
  }
  zRuneList.append(data);
//  qDebug() << data.name << data.letter << data.meaning <<
//              data.reverse << data.UTFValue << data.UTF;
}
