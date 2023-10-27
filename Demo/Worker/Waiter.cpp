#include "Worker.h"
#include <ostream>

Waiter::~Waiter() {}

void Waiter::information() const
{
    Worker::information();
    using std::cout;
    using std::endl;
    cout << "Panache: " << panache << endl;
}

void Waiter::perform() const
{
    using std::cout;
    using std::endl;
    cout << get_name() << ": I deliver a dish." << endl;
}

SingingWaiter Waiter::operator+(const Singer s) const
{
    return SingingWaiter(*this, s.get_voice());
}

std::ostream & operator<<(std::ostream & os, const Waiter & w)
{
    using std::endl;
    os << "Id: " << w.get_id() << endl
        << "Name: " << w.get_name() << endl
        << "Gender: " << w.get_gender() << endl
        << "Addr: " << w.get_addr() << endl
        << "Panache: " << w.panache << endl;
    return os;
}
