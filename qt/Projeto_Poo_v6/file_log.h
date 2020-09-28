#ifndef FILE_LOG_H
#define FILE_LOG_H

#include <QVector>
#include <QDateTime>
#include <QFile>
#include <QTextStream>



class file_log
{
public:
    file_log();
    file_log(QString nome);

    QString  printname();
    void filtro(QString parametro);
    void geterror(QString &strerror);
    QString getmachine();

    ~file_log();

private:
    void grafico( QString titlegraph );
    void gettemperatura();
    void gettiles();

    QString _nomearquivo="";
    QVector<double> _vec_temp;
    QVector<QTime> _vec_time;
    QFile *_arquivo=nullptr;
    QString _machine="";

};

#endif // FILE_LOG_H
