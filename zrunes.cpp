#include "zrunes.h"
#include <QDebug>

zRunes::zRunes()
{
  zRuneStruct zRuneList[26] = {
    {"Name"   ,"Letter" ,"Significance" ,false},
    {"Fehu"     ,"f"    ,"Possessions"  ,true},
    {"Urez"     ,"u"    ,"Strength"     ,true},
    {"Thurisaz" ,"th"   ,"Gateway"      ,true},
    {"Ansuz"    ,"a"    ,"Signals"      ,true},
    {"Radio"    ,"r"    ,"Journey"      ,true},
    {"Kano"     ,"k"    ,"Opening"      ,true},
    {"Gebo"     ,"g"    ,"Partnership"  ,false},
    {"Wunjo"    ,"w"    ,"Joy"          ,true},
    {"Hagalaz"  ,"h"    ,"Disruption"   ,false},
    {"Nauthiz"  ,"n"    ,"Constraint"   ,true},
    {"Isa"      ,"i"    ,"Standstill"   ,false},
    {"Jera"     ,"j"    ,"Harvest"      ,false},
    {"Eihwaz"   ,"e(ei)","Defence"      ,false},
    {"Perth"    ,"p"    ,"Initiation"   ,true},
    {"Algiz"    ,"z"    ,"Protection"   ,true},
    {"Sowelu"   ,"s"    ,"Wholeness"    ,false},
    {"Teiwaz"   ,"t"    ,"Warrior"      ,true},
    {"Berkana"  ,"b"    ,"Growth"       ,true},
    {"Ehwaz"    ,"e(o)" ,"Movement"     ,true},
    {"Mannaz"   ,"m"    ,"Self"         ,true},
    {"Laguz"    ,"l"    ,"Flow"         ,true},
    {"Inguz"    ,"ng"   ,"Fertility"    ,false},
    {"Othila"   ,"o"    ,"Seperation"   ,true},
    {"Dagaz"    ,"d"    ,"Breakthrough" ,false},
    {"Odin"     ,"-"    ,"The Unknown"  ,false}
  };
  qDebug() << "::" << zRuneList[2].name;
}

zRunes::~zRunes()
{

}
