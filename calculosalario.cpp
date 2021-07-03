#include "calculosalario.h"

QString CalculoSalario::getJornada()
{
    QString str;
    switch(trabajador->jornada())
    {
    case 'V':
        str = "Vespertina";
        break;
    case 'M':
        str = "Matutina";
        break;
    case 'N':
        str = "Nocturna";
        break;
    }
    return str;
}

CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent)
{

}

CalculoSalario::CalculoSalario(Obrero &trabajador)
{
    this->trabajador = &trabajador;
}

QString CalculoSalario::resultado()
{
    QString str;
    str = "Obrero " + trabajador->nombreObrero() + "\n";
    str += "Horas: " + QString::number(trabajador->horasAsignadas()) + "\n";
    str += "Jornada: " + getJornada() + "\n";
    str += "Salario Bruto: $" + QString::number(m_salarioBruto) + "\n";
    str += "Descuento: $" + QString::number(m_descuento) + "\n";
    str += "Salario Neto: $" + QString::number(m_salarioNeto) + "\n\n";
    return str;
}

void CalculoSalario::calcular()
{
    float valorHora = 0;
    switch(trabajador->jornada())
    {
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }

    m_salarioBruto = trabajador->horasAsignadas() * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO/100;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

float CalculoSalario::salarioBruto() const
{
    return m_salarioBruto;
}

float CalculoSalario::descuento() const
{
    return m_descuento;
}

float CalculoSalario::salarioNeto() const
{
    return m_salarioNeto;
}

bool CalculoSalario::guardarControlador(QString texto)
{
    if(trabajador->guardar(texto)){

        return true;
    }else{
        QMessageBox::warning(nullptr, "Salarios", "No se puede guardar el archivo");
        return false;
    }
}

QString CalculoSalario::abrirControlador()
{
    return trabajador->abrir();

}
