#ifndef CARSCALCULATOR_H
#define CARSCALCULATOR_H
#include <QString>
using namespace std;

class PassengerCar
{
protected:
    QString brand;
    QString color;
    QString fuel_volume;
    QString fuel_power;
public:
    ~PassengerCar();
    PassengerCar();
    PassengerCar(QString, QString, QString, QString);
    QString Distance_fuel() const;
    QString Get_brand() const;
    QString Get_color() const;
    QString Get_volume() const;
    QString Get_power() const;
    void Set_brand(QString);
    void Set_color(QString);
    void Set_volume(QString);
    void Set_power(QString);
};

class Truck: public PassengerCar
{
private:
    QString max_weight;
public:
    ~Truck();
    Truck();
    Truck(QString, QString, QString, QString, QString);
    QString Price_km(QString) const;
    void Set_max_weight(QString);
    QString Get_max_weight() const;
};


#endif // CARSCALCULATOR_H
