#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;


class ExceptionList : public exception
{
protected:
    string errormsg;

public:
    ExceptionList(const string &filename,
                  const int line,
                  const string &time)
    {
        errormsg = "In: "          + filename        +
                   "\nat line: "   + to_string(line) +
                   "\nat: "        + time;
    }
    virtual const char* what() const noexcept override
    {
        return errormsg.c_str();
    }
};


class   ErrorProdigalAlias : public ExceptionList
{
public:
     ErrorProdigalAlias(
            const char* file_name,
            const int index,
            const char* time)
    : ExceptionList(file_name, index, time) {}
    virtual ~ErrorProdigalAlias() {}
};


class   ErrorBadAlloc : public ExceptionList
{
public:
      ErrorBadAlloc(
            const char* file_name,
            const int index,
            const char* time)
    : ExceptionList(file_name, index, time) {}
    virtual ~ErrorBadAlloc() {}
};



class  ErrorIndex : public ExceptionList
{
public:
     ErrorIndex(
            const char* file_name,
            const int index,
            const char* time)
    : ExceptionList(file_name, index, time) {}
    virtual ~ ErrorIndex() {}
};


class ConstructorBadArguments : public ExceptionList
{
public:
    ConstructorBadArguments(
            const char* file_name,
            const int index,
            const char* time)
    : ExceptionList(file_name, index, time) {}
};


class BadObjectPtr : public ExceptionList
{
public:
    BadObjectPtr(
            const char* file_name,
            const int index,
            const char* time)
    : ExceptionList(file_name, index, time) {}
};


class EmptyList : public ExceptionList
{
public:
    EmptyList(
            const char* file_name,
            const int index,
            const char* time)
    : ExceptionList(file_name, index, time) {}
};

#endif // ERRORS_H
