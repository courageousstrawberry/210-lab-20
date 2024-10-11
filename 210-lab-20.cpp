#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int SIZE = 3;
class Chair
{
private:
    int legs;
    double *prices;

public:
    // constructors
    Chair()
    {
        const int MIN = 10000, MAX = 99999;

        prices = new double[SIZE];
        legs = rand()%2 + 3;
        // Populate prices array with random double values.
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
    }
    Chair(int l, double *arr)
    {
        prices = new double[SIZE];
        legs = l;
        // Populate prices array with the values in the parameter array.
        for (int i = 0; i < SIZE; i++)
            prices[i] = arr[i];
    }
    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }
    void setPrices(double p1, double p2, double p3)
    {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }
    double getAveragePrices()
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }
    void print()
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl
             << "Historical avg price: " << getAveragePrices();
        cout << endl
             << endl;
    }
};
int main()
{
    srand(time(0));

    cout << fixed << setprecision(2);
    // creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    // creating dynamic chair object with parameter constructor
    double arr[3] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, arr);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    double arr2[3]= {484.84, 959.59, 868.68};
    for (int i = 0; i < SIZE; i++) {
        collection[i] = Chair();
        if (i == 1) {
            collection[i] = Chair(4, arr2);
        }
    }

    // Print out each chair in the collection array.
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }

    delete[] collection;
    collection = nullptr;

    return 0;
}
