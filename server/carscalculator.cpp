#include "carscalculator.h"
//PassengerCar
#include <QVariant>
#include <QRegularExpression>

bool isNumber(const QString &str) {
    QRegularExpression regex("^-?\\d+(\\.\\d+)?$");
    QRegularExpressionMatch match = regex.match(str);
    return match.hasMatch();
}

PassengerCar::~PassengerCar(){}

PassengerCar::PassengerCar()
{
    this->Set_brand("0");
    this->Set_color("0");
    this->Set_power("0");
    this->Set_volume("0");
}
PassengerCar::PassengerCar(QString _brand, QString _color, QString _volume, QString _power)
{
    this->Set_brand(_brand);
    this->Set_color(_color);
    this->Set_power(_power);
    this->Set_volume(_volume);
    if(!isNumber(_volume)){this->Set_volume("0");}
    if(!isNumber(_power)){this->Set_power("0");}

}
QString PassengerCar::Distance_fuel() const
{
    return QString::number(qRound(this->fuel_volume.toDouble()/(1.*this->fuel_power.toDouble())*100));
}
QString PassengerCar::Price_for_full_tank(QString fuel_price) const
{
    return QString::number(qRound(this->fuel_volume.toDouble()* fuel_price.toDouble()));
}

QString PassengerCar::Get_brand() const
{
    return this->brand;
}
QString PassengerCar::Get_color() const
{
    return this->color;
}
QString PassengerCar::Get_volume() const
{
    return this->fuel_volume;
}
QString PassengerCar::Get_power() const
{
    return this->fuel_power;
}
void PassengerCar::Set_brand(QString _brand)
{
    this->brand = _brand;
}
void PassengerCar::Set_color(QString _color)
{
    this->color = _color;
}
void PassengerCar::Set_volume(QString _volume)
{
    this->fuel_volume = _volume;
}
void PassengerCar::Set_power(QString _fuel_power)
{
    this->fuel_power = _fuel_power;
}

//Truck
Truck::~Truck(){}
Truck::Truck(): PassengerCar::PassengerCar(){
    this->Set_max_weight("1");
}
Truck::Truck(QString _brand, QString _color, QString _volume, QString _power, QString _max_weight):
    PassengerCar::PassengerCar(_brand, _color, _volume, _power){
    this->Set_max_weight(_max_weight);
}
QString Truck::Price_km(QString fuel_price) const{
    return QString::number(((1.*this->fuel_power.toDouble())*fuel_price.toDouble()/100)/this->max_weight.toDouble());
}
void Truck::Set_max_weight(QString _max_weight){
    this->max_weight = _max_weight;
}
QString Truck::Get_max_weight() const{
    return this->max_weight;
}

