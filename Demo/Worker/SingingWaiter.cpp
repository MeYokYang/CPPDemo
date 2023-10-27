#include "Worker.h"
#include <ostream>

SingingWaiter::~SingingWaiter() {}

void SingingWaiter::information() const
{
    Worker::information();
    using std::cout;
    using std::endl;
    cout << "Panache: " << get_panache() << endl
        << "Voice: " << get_voice() << endl;
}

void SingingWaiter::perform() const
{
    using std::cout;
    using std::endl;
    cout << get_name() << ": I sing a song and deliver a dish." << endl;
}

std::ostream & operator<<(std::ostream& os, const SingingWaiter & sw)
{
    using std::endl;
    os << Singer(sw)
        << "Panache: " << sw.get_voice() << endl;
    return os;
}
