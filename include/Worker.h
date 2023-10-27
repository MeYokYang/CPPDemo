#include <cstring>
#include <iostream>
#include <fstream>

using strtype = char*;

class Singer;
class SingingWaiter;



class Worker
{
private:
    enum {Max_name_len = 20, Max_addr_len = 20};
    const unsigned id;
    char name[Max_name_len] = {'\0'};
    const bool gender;
    char addr[Max_addr_len] = {'\0'};

public:
    Worker(unsigned i, const char* n, bool g, const char* a = "");
    virtual ~Worker() = 0;

    void set_name(const char* new_name) { strcpy(name, new_name); }
    void set_addr(const char* new_addr) { strcpy(addr, new_addr); }
    unsigned get_id() const { return id; }
    const char* get_name() const { return name; }
    bool get_gender() const { return gender; }
    const char* get_addr() const { return addr; }

    virtual void information() const;
    virtual void perform() const = 0;

    explicit operator strtype() const { return strtype(name); }

    friend std::ostream & operator<<(std::ostream& os, const Worker & w);
};


class Waiter : virtual public Worker
{
private:
    int panache;

public:
    Waiter(unsigned i, const char* n, bool g, const char* a = "", int p = 0)
        : Worker(i, n, g, a), panache(p) {}
    Waiter(unsigned i, const char* n, bool g, int p)
        : Worker(i, n, g, ""), panache(p) {}
    Waiter(const Worker & wk, int p = 0)
        : Worker(wk), panache(p) {}
    virtual ~Waiter();

    void set_panache(int p) { panache = p; }
    int get_panache() const { return panache; }

    virtual void information() const;
    virtual void perform() const;

    SingingWaiter operator+(const Singer s) const;

    friend std::ostream & operator<<(std::ostream& os, const Waiter & w);

};


class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};

private:
    static char* pv[Vtypes];
    int voice;
public:
    Singer(unsigned i, const char* n, bool g, const char* a = "", int v = other)
        : Worker(i, n, g, a), voice(v) {}
    Singer(unsigned i, const char* n, bool g, int v)
        : Worker(i, n, g, ""), voice(v) {}
    Singer(const Worker & wk, int v = other)
        : Worker(wk), voice(v) {}
    virtual ~Singer();

    void set_voice(int v) { voice = v; }
    int get_voice() const { return voice; }

    virtual void information() const;
    virtual void perform() const;

    SingingWaiter operator+(const Waiter w) const;

    friend std::ostream & operator<<(std::ostream& os, const Singer & s);

};


class SingingWaiter : public Singer, public Waiter
{
public:
    SingingWaiter(unsigned i, const char* n, bool g, const char* a = "", int p = 0, int v = other)
        : Worker(i, n, g, a), Singer(i, n, g, v), Waiter(i, n, g, p) {}
    SingingWaiter(const Singer & s, int p = 0)
        : Worker(s), Singer(s), Waiter(s, p) {}
    SingingWaiter(const Waiter & w, int v = other)
        : Worker(w), Singer(w, v), Waiter(w) {}
    virtual ~SingingWaiter();

    virtual void information() const;
    virtual void perform() const;

    friend std::ostream & operator<<(std::ostream& os, const SingingWaiter & sw);

};
