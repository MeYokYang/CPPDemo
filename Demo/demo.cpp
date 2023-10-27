#include "demo.h"
#include "Worker.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>
#include <functional>

void outfile()
{

    int a = 12;
    char t[a];

    using std::ofstream;

    ofstream outFile;
    outFile.open("carinfo.txt");


    using std::cout;
    using std::cin;
    char automobile[50];
    int year;
    double a_price, d_price;

    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the mobile year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    using std::fixed;
    using std::ios_base;
    using std::endl;

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;


    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();

}

void sumafile()
{
    const int SIZE = 60;
    char filename[SIZE];
    using std::ifstream;
    using std::cout;
    using std::cin;
    using std::endl;
    ifstream inFile;
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);

    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count;

    inFile >> value;
    while (inFile.good())
    {
        ++count;
        sum += value;
        inFile >> value;
    }

    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    inFile.close();
}

void test_worker()
{
    using std::cout;
    using std::endl;

    Waiter w = Waiter(1, "yangyi", true, "dazhou", 1);
    Singer s = Singer(2, "zhangsan", false, "chengdu", 1);
    SingingWaiter sw = SingingWaiter(3, "lisi", true, "", 0, 0);

    cout << "-----------------------------" << endl
        << "---information and perform---" << endl;
    w.information();
    w.perform();
    s.information();
    s.perform();
    sw.information();
    sw.perform();
    cout << "-----------------------------" << endl;


    cout << "-----------------------------" << endl
        << "------------cout-------------" << endl;
    cout << w
        << s
        << sw << endl;
    cout << "-----------------------------" << endl;


    cout << "-----------------------------" << endl
        << "-------------add-------------" << endl;
    SingingWaiter sw1 = s + w;
    cout << sw1;
    SingingWaiter sw2 = w + s;
    cout << sw2;
    cout << "-----------------------------" << endl;


    cout << "-----------------------------" << endl
        << "-----------strtype-----------" << endl;
    char name[20];
    strcpy(name, strtype(sw1));
    cout << name << endl;
    cout << "-----------------------------" << endl;

}

void exercise7_1()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    double a, b;
    cout << "Please enter 2 numbers in a line firstly and separate them with spaces. "
        << "The extra characters will be discarded.(Press <q> or EOF to quit): " << endl;

    cin.exceptions(ios_base::badbit);

    cout.setf(ios_base::showpoint);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(4);


    try
    {
        while (cin.peek() != 'q')
        {
            if (cin.eof()) { cout << "Get the EOF, and quit." << endl; break; }

            int ch;
            bool flag = false;

            while ((ch = cin.get()) != EOF)
            {
                if (isdigit(char(ch)))
                {
                    cin.putback(char(ch));
                    cin >> a;
                    break;
                }
                else if (ch == '\n') { flag = true; break; }
                else if (!isspace(char(ch)))
                {
                    while ((ch = cin.get()) != EOF) { if (ch == '\n') { flag = true; break; } }
                    break;
                }
            }

            if (cin.eof()) { cout << "Get the EOF, and quit." << endl; break; }
            if (flag == true) { cout << "Format error, please re-enter: " << endl; continue; }

            while ((ch = cin.get()) != EOF)
            {
                if (isdigit(char(ch)))
                {
                    cin.putback(char(ch));
                    cin >> b;
                    ch = cin.get();
                    while (true)
                    {
                        if (ch == EOF || ch == '\n') break;
                        ch = cin.get();
                    }
                    break;
                }
                else if (ch == '\n') { flag = true; break; }
                else if (!isspace(char(ch)))
                {
                    while ((ch = cin.get()) != EOF) { if (ch == '\n') { flag = true; break; } }
                    break;
                }
            }

            if (cin.eof()) { cout << "Get the EOF, and quit." << endl; break; }
            if (flag == true) { cout << "Format error, please re-enter: " << endl; continue; }

            cout << "The average: ";
            cout.width(10);
            cout << harmonic_mean(a, b) << endl;
        }
        cin.sync();
        cin.clear(cin.rdstate() & (~ios_base::eofbit));
    }
    catch(const std::ios_base::failure& bf)
    {
        std::cerr << bf.what() << '\n';
        cout << std::flush;

        cout.unsetf(ios_base::showpoint);
        cout.unsetf(ios_base::floatfield);
        cout.precision(prec);

        exit(EXIT_FAILURE);
    }

    cout.unsetf(ios_base::showpoint);
    cout.unsetf(ios_base::floatfield);
    cout.precision(prec);

}

void exercise7_2()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    const int Arr_len = 10;
    double arr[Arr_len];

    cout << "Input up to 10 socres, and press <q> to end early: " << endl;

    int ch, count = 0;
    bool exit_flag = false;
    bool error_enter_flag = false;
    bool max_enter_flag = false;
    while (!exit_flag && !max_enter_flag)
    {
        ch = cin.get();
        if (ch == EOF) { break; }
        else if (ch == '\n')
        {
            cout << "Error number, please re-enter: " << endl;
            continue;
        }
        cin.putback(ch);

        count = 0;

        for (int i = 0; i < Arr_len; i++)
        {
            arr[i] = 0.0;
            while ((ch = cin.get()) != EOF)
            {
                if (isdigit(char(ch)))
                {
                    cin.putback(ch);
                    cin >> arr[i];
                    ++count;
                    if (i == Arr_len - 1) { max_enter_flag = true; }
                    break;
                }
                else if (ch == 'q')
                {
                    exit_flag = true;
                    while ((ch = cin.get()) != EOF) { if (ch == '\n') { break; } }
                    break;
                }
                else if (!isspace(char(ch)))
                {
                    cout << "Error number, please re-enter: " << endl;
                    error_enter_flag = true;
                    while ((ch = cin.get()) != EOF) { if (ch == '\n') { break; } }
                    break;
                }
            }
            if (exit_flag || error_enter_flag || max_enter_flag)
            {
                error_enter_flag = false;
                break;
            }
        }
        if (cin.eof()) { exit_flag = true; }
    }

    if (cin.eof())
    {
        cout << "EOF. " << endl;
        cin.setstate(cin.rdstate() & (~ios_base::eofbit));
    }
    else
    {
        double sum = 0;
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
            sum += arr[i];
        }

        cout << endl;
        cout << "Count: " << count << endl;
        cout << "The average: " << sum / count << endl;
    }

}

int fill_array(double* arr, const int len)
{
    using std::cin;
    using std::cout;
    using std::endl;

    int count;
    for (count = 0; count < len; count++)
    {
        cout << "Input: ";
        cin >> arr[count];
        if (cin.fail())
        {
            cout << "error input." << endl;
            cin.clear();
            int ch;
            while ((ch = cin.get()) != EOF && (ch != '\n')) {}
            break;
        }
    }
    return count;
}

void show_array(double* arr, const int len)
{
    using std::cin;
    using std::cout;
    using std::endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse_array(double* arr, const int len)
{
    int i = 1, j = len - 2, t;
    for (; i < j; ++i, --j)
    {
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

void string_toupper(std::string & s)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        s[i] = toupper(s[i]);
    }
}

void set(stringy & s, const char * o_s)
{
    s.ct = strlen(o_s);
    s.str = new char[s.ct + 1];
    strcpy(s.str, o_s);
}

void show(const stringy & s, const int times)
{
    using std::cout;
    using std::endl;

    for (int i = 0; i < times; i++)
    {
        cout << s.str << endl;
    }

}

void show(const char * s, int times)
{
    using std::cout;
    using std::endl;

    for (size_t i = 0; i < times; i++)
    {
        cout << s << endl;
    }

}

template <typename T>
T max5(const T * arr)
{
    T max = arr[0];
    for (size_t i = 0; i < 5; i++) { max = (arr[i] > max) ? arr[i] : max; }
    return max;
}

template <typename T>
T maxn(const T arr[], const int n)
{
    T max = arr[0];
    for (size_t i = 0; i < n; i++) { max = (arr[i] > max) ? arr[i] : max; }
    return max;
}

template <> char_p maxn<char_p>(const char_p arr[], const int n)
{
    char_p max_p = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        max_p = (strlen(arr[i]) > strlen(max_p)) ? arr[i] : max_p;
    }
    return max_p;
}

namespace SALES
{
    void set_sales(Sales & s, const double ar[], int n)
    {
        n = (n > 4) ? 4 : n;
        double max = ar[0];
        double min = ar[0];
        double sum = 0;
        for (size_t i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            sum += ar[i];
            max = (ar[i] > max) ? ar[i] : max;
            min = (ar[i] < min) ? ar[i] : min;
        }
        for (size_t i = n; i < 4; i++) { s.sales[i] = 0; }

        s.average = sum / n;
        s.max = max;
        s.min = min;
    }

    void set_sales(Sales & s)
    {
        double max, min, sum = 0;

        using std::cout;
        using std::cin;
        for (size_t i = 0; i < 4; i++)
        {
            cout << "Enter " << i << ": ";
            cin >> s.sales[i];
            sum += s.sales[i];
            if (i == 0)
            {
                max = s.sales[0];
                min = s.sales[0];
            }
            else
            {
                max = (s.sales[i] > max) ? s.sales[i] : max;
                min = (s.sales[i] < min) ? s.sales[i] : min;
            }
        }

        s.average = sum / 4;
        s.max = max;
        s.min = min;

    }

    void show_sales(const Sales & s)
    {
        using std::cout;
        using std::endl;
        for (size_t i = 0; i < 4; i++)
        {
            cout << "sales[" << i << "]: " << s.sales[i] << endl;
        }
        cout << "average: " << s.average << endl;
        cout << "max: " << s.max << endl;
        cout << "min: " << s.min << endl;
    }
} // namespace SALES

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
}

Person::~Person() {}

void Person::show() const
{
    using std::cout;
    using std::endl;
    cout << std::setw(12) << "firstname: " << fname << endl;
    cout << std::setw(12) << "lastname: " << lname << endl;
}

void Person::formal_show() const
{
    using std::cout;
    using std::endl;
    cout << std::setw(12) << "lastname: " << lname << endl;
    cout << std::setw(12) << "firstname: " << fname << endl;
}

Grand::~Grand() {}

void Grand::show()
{
    using std::cout;
    using std::endl;

    cout << "I'm grand show." << endl;
}

Superb::~Superb() {}

void Superb::show()
{
    using std::cout;
    using std::endl;

    cout << "I'm superb show." << endl;
}

void change(const int * p)
{
    int * p1 = const_cast<int *>(p);
    *p1 += 3;
}

void Linear::operator() (double d)
{

    std::ostream_iterator<double, char> out_iter(std::cout, "\n");
    // *out_iter++ = "print number d: ";
    using std::ios_base;
    using std::cout;
    cout.precision(3);
    cout.setf(ios_base::showpoint);

    *out_iter++ = d;

}

template <typename T, typename... Args>
void ddd(T value, const Args&... args)
{
    using std::cout;
    using std::endl;
    cout << value << endl;

    ddd(args...);
}


void exercise()
{
    using std::cin;
    using std::cout;
    using std::endl;

    std::binder1st<std::multiplies<double>> b = bind1st(std::multiplies<double>(), 2.5);
    // std::binder1st<std::multiplies<double>, 2.5> f1;
    std::binder1st<std::multiplies<double>> f1(std::multiplies<double>(), 2.5);

    std::vector<double> v(2, 4.5);
    std::ostream_iterator<double, char> out(cout, "\n");
    std::transform(v.begin(), v.end(), out, f1);


}
