#ifndef JSON_H
#define JSON_H

#include "bug.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>


void saveJson(std::vector<bug> b)
{
    QJsonArray arr;

    for(auto i : b)
    {
        QJsonObject obj;

        obj["name"] = i.name;
        obj["type"] = i.type;
        obj["code"] = i.code;
        obj["reason"] = i.reason;

        arr.append(obj);
    }

    QJsonDocument doc(arr);

    QFile file("json_debug");

    file.open(QIODevice::WriteOnly);

    QByteArray bar = doc.toJson();

    file.write(bar);

    file.close();
}

#endif // JSON_H