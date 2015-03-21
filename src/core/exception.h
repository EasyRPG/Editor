#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
public:

    enum Code
    {
        UNKNOWN = 1,
        FILE_NOT_FOUND,
        INVALID_FILE_PATH
    } code;

    Exception();

    QString title;
    QString description;
};

#endif // EXCEPTION_H
