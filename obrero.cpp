#include "obrero.h"

int Obrero::horasAsignadas() const
{
    return m_horas;
}

QString Obrero::nombreObrero() const
{
    return m_nombre;
}

char Obrero::jornada() const
{
    return m_jornada;
}

bool Obrero::guardar(QString texto)
{
    QString fileName = QFileDialog::getSaveFileName(nullptr,"Guardar datos",QDir::home().absolutePath(),"Archivo de Texto(*.txt)");
        QFile data(fileName);
        if(data.open(QFile::WriteOnly|QFile::Truncate)){
            QTextStream salida(&data);
            salida<<texto;
        }
        data.close();
        return true;
}

QString Obrero::abrir()
{
    QString linea="";
    QFile file(QFileDialog::getOpenFileName(nullptr,"Abrir Archivo","","Archivo de Texto(*.txt)"));

           if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
              QMessageBox::warning(nullptr, "Salarios", "No se puede abrir el archivo");
           }else{

               // return;

               QTextStream in(&file);
               while (!in.atEnd()) {
                   linea += in.readLine()+'\n';//texto + \n + texto + \n ....
               }
               file.close();
           }
    return linea;
}

Obrero::Obrero(QString nombre, int horas, char jornada)
{
    m_nombre = nombre;
    m_horas = horas;
    m_jornada = jornada;
}
