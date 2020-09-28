#include "file_log.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <form_2.h>
#include <iostream>
//#include <stdio.h>
//#include <QTime>



file_log::file_log() {}
file_log::file_log(QString nome){
    _nomearquivo = nome;
    _arquivo = new QFile(_nomearquivo);
    if(!_arquivo->open(QFile::ReadOnly|QFile::Text))
        QMessageBox::warning(nullptr, "ERRO", "Erro Abrir Arquivo");

}


file_log::~file_log(){_arquivo->close();}


QString file_log::printname(){return _nomearquivo;}


void file_log::filtro(QString parametro){
    QVector<double> vec_temps;
    QVector<QTime> vec_times;
    QString titlegraph;

    if (parametro==".01GTT"){ gettemperatura();
        titlegraph = "Tile Temperature  " + getmachine() ;
    }
    if (parametro==".01QPT"){ gettiles();
        titlegraph = "Tiles" + getmachine();
    }

    grafico(titlegraph);

}

void file_log::gettemperatura(){

    QString value, hh, min, sec, linha;
    QTime hora;
    _vec_temp.append(100);
    _vec_time.append(QTime(0,0,0));
    _arquivo->seek(0);


    while (!_arquivo->atEnd()){
        linha = _arquivo->readLine();
        value = linha.mid(30,12);
        hh = linha.mid(9,2);
        min = linha.mid(12,2);
        sec = linha.mid(15,2);
        hora.setHMS(hh.toInt(),min.toInt(),sec.toInt());

        if (value.contains(".01GTT",Qt::CaseInsensitive)){

            value= value.mid(6,3);
            _vec_temp.append((value.toInt())/10);
            _vec_time.append(hora);

        }
    }


}


void file_log::gettiles(){

    QString value, hh, min, sec, linha;
    QTime hora;
    _vec_temp.clear();
    _vec_time.clear();
    _vec_temp.append(10000);
    _vec_time.append(QTime(0,0,0));
    _arquivo->seek(0);


    while (!_arquivo->atEnd()){
        linha = _arquivo->readLine();
        value = linha.mid(30,12);
        hh = linha.mid(9,2);
        min = linha.mid(12,2);
        sec = linha.mid(15,2);
        hora.setHMS(hh.toInt(),min.toInt(),sec.toInt());

        if (value.contains(".01QPT",Qt::CaseInsensitive)){
            value= value.mid(6,6);
            _vec_temp.append(value.toInt());
            _vec_time.append(hora);
        }
    }

}


void file_log::grafico(QString titlegraph){

    form_2 * _form2;
    _form2 = new form_2(nullptr, &_vec_temp,  &_vec_time, titlegraph);
    _form2 -> show();

}


void file_log::geterror(QString &strerror){

     QString linha;
      _arquivo->seek(0);
      while (!_arquivo->atEnd()){
          linha = _arquivo->readLine();
          if (linha.contains("ERROR",Qt::CaseSensitive)){
              strerror.append(linha);
          }
      }


}



QString file_log::getmachine(){
    QString value, linha;
    _arquivo->seek(0);

    while (!_arquivo->atEnd()){
        linha = _arquivo->readLine();
        if (linha.contains("System Number",Qt::CaseSensitive)){
            value = linha.mid(36,7);
        }
    }
   return (value);
}
