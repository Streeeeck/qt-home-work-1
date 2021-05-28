#include "storage.h"

Storage::Storage(int _id, int _cap, QString _city, QString _addr)
{
    id = _id;
    capacity = _cap;
    city = _city;
    address = _addr;
}


int Storage::getId() const
{
    return id;
}

void Storage::setId(int value)
{
    id = value;
}

int Storage::getCapacity() const
{
    return capacity;
}

void Storage::setCapacity(int value)
{
    capacity = value;
}

QString Storage::getCity() const
{
    return city;
}

void Storage::setCity(const QString &value)
{
    city = value;
}

QString Storage::getAddress() const
{
    return address;
}

void Storage::setAddress(const QString &value)
{
    address = value;
}
