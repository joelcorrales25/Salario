#ifndef OBRERO_H
#define OBRERO_H
#include <QObject>
#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
class Obrero
{
private:
    int m_horas;      //Numeros de horas trabajadas
    QString m_nombre; //Nombre del Obrero
    char m_jornada;   //Jornada del Obrero

public:
    Obrero(QString nombre, int horas, char jornada);
    int horasAsignadas() const;
    QString nombreObrero() const;
    char jornada() const;
    bool guardar(QString);
    QString abrir();

};

#endif // OBRERO_H
