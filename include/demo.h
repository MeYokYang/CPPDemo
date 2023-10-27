#ifndef _DEMO_H
#define _DEMO_H

#include <string>

void outfile();
void sumafile();

void test_worker();

/**
 * @brief Calculate the harmonic of 2 numbers.
 * @param a Number a.
 * @param b Number b.
 * @return The harmonic of number a and number b.
 */
inline double harmonic_mean(const double a, const double b) { return 2.0 * a * b / (a + b); }

/**
 * @brief The exercise of Question 1, Chapter 7: Input 2 numbers every time, and output their harmonic mean.
 */
void exercise7_1();


void exercise7_2();

int fill_array(double* arr, const int len);

void show_array(double* arr, const int len);

void reverse_array(double* arr, const int len);

using p_type = double(*)(double, double);

inline double calculate(double a, double b, p_type f) { return f(a, b); }

inline double add(double a, double b) { return a + b; }

void string_toupper(std::string & s);

struct stringy
{
    char * str;
    int ct;
};

void set(stringy & s, const char* o_s);

void show(const stringy & s, const int times = 1);

void show(const char * s, int times = 1);

template <typename T>
T max5(const T * arr);

template <typename T>
T maxn(const T arr[], const int n);

using char_p = char *;

template <>
char_p maxn<char_p>(const char_p arr[], const int n);

namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    void set_sales(Sales & s, const double ar[], int n);
    void set_sales(Sales & s);
    void show_sales(const Sales & s);
} // namespace SALES

class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];
public:
    Person() { lname = ""; fname[0] = '\0'; }
    Person(const std::string & ln, const char * fn = "Heyyou");
    ~Person();

    void show() const;
    void formal_show() const;

};

class Grand
{
private:
    float g;
public:
    Grand(float gg = 0) : g(gg) {}
    virtual ~Grand();

    virtual void show();

};

class Superb : public Grand
{
private:

public:
    Superb() : Grand() {}
    virtual ~Superb();

    virtual void show() override;

};

class Linear
{
private:
    double dou;

public:
    Linear() = default;
    Linear(double d) : dou(d) {}
    ~Linear() = default;

    void operator() (double d);

};

void ddd() {}

template <typename T, typename... Args>
void ddd(T value, const Args&... args);


void exercise();

#endif
