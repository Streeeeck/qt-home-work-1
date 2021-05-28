#ifndef STORAGE_H
#define STORAGE_H
#include <QString>

class Storage
{
public:
    Storage(int _id, int _cap, QString _city, QString _addr);

    int getId() const;
    void setId(int value);

    int getCapacity() const;
    void setCapacity(int value);

    QString getCity() const;
    void setCity(const QString &value);

    QString getAddress() const;
    void setAddress(const QString &value);

private:
    int id;
    int capacity;
    QString city;
    QString address;
};

#endif // STORAGE_H
