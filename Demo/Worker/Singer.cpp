#include "Worker.h"
#include <ostream>

Singer::~Singer() {}

void Singer::information() const
{
    Worker::information();
    using std::cout;
    using std::endl;
    cout << "Voice: " << voice << endl;
}

void Singer::perform() const
{
    using std::cout;
    using std::endl;
    cout << get_name() << ": I sing a song." << endl;
}

SingingWaiter Singer::operator+(const Waiter w) const
{
    return SingingWaiter(*this, w.get_panache());
}

std::ostream & operator<<(std::ostream & os, const Singer & s)
{
    using std::endl;
    os << "Id: " << s.get_id() << endl
        << "Name: " << s.get_name() << endl
        << "Gender: " << s.get_gender() << endl
        << "Addr: " << s.get_addr() << endl
        << "Voice: " << s.voice << endl;
    return os;
}
