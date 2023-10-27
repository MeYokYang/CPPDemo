#include "Worker.h"
#include <cstring>
#include <ostream>

Worker::Worker(unsigned i, const char* n, bool g, const char* a)
    : id(i), gender(g)
{
    strcpy(name, n);
    strcpy(addr, a);
}

Worker::~Worker() {}

void Worker::information() const
{
    using std::cout;
    using std::endl;

    cout << "Id: " << id << endl
        << "Name: " << name << endl
        << "Gender: " << gender << endl
        << "Addr: " << addr << endl;
}

std::ostream & operator<<(std::ostream & os, const Worker & w)
{
    using std::endl;
    os << "Id: " << w.id << endl
        << "Name: " << w.name << endl
        << "Gender: " << w.gender << endl
        << "Addr: " << w.addr << endl;
    return os;
}
