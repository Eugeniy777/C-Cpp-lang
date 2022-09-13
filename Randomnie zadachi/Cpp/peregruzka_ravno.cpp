#include <iostream>
#include <string>
using namespace std;

class point
{
private:
    int x;
    int y;

public:
    void Print()
    {
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
    }
    point()
    {
        x = 0;
        y = 0;
        cout << this << " constructor"s << endl;
    }
    // konstruktor
    point(int valueX, int valueY)
    {
        x = valueX;
        y = valueY;
        cout << this << " constructor"s << endl;
    }

    // peregruzka operatora ==
    bool operator==(const point &other)
    {
        if (this->x == other.x && this->y == other.y)
        {
            return true;
        }
        else
        {
            return false;
        }
        // po krasote
        // return (this->x == other.x && this->y == other.y)
    }

    // peregruzka operatora !=
    bool operator!=(const point &other)
    {
        if (this->x == other.x && this->y == other.y)
        {
            return false;
        }
        else
        {
            return true;
        }
        // po krasote
        // return !(this->x == other.x && this->y == other.y)
    }
    // setter - ustanavlivaet znachenie v pole
    void SetX(int valueX)
    {
        x = valueX;
    }
    void SetY(int y)
    {
        this->y = y;
    }

    // getter - vozvraschaet znachenie iz polya
    int GetX()
    {
        return x;
    }
};

int main()
{
    point a(5, 1);
    point b(5, 1);

    bool result = a == b;
    cout << result << endl;

    /*----------------------------------*/
    // g++ prakt_1.cpp -o prakt_1 -std=c++17 -Wall -Wextra -pedantic -Werror
    return 0;
}