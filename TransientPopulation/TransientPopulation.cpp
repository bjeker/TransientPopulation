/*Ryan Bieker, CS 3060 001, Chapter 6 Programming Challenges, due 3 / 1 / 2022, 
calculates size of population over number of years based ono factors*/

#include <iostream>
#include <cmath>

using namespace std;

double popSize(double pop, double birthRate, double deathRate, double annualArrived, double annualMoved);

int main()
{
    double pop;
    double birthRate;
    double deathRate;
    double annualArrived;
    double annualMoved;
    double years;

    //title
    cout << "This program calculates population change." << endl;

    //ask for pop size
    cout << "Enter the starting population size: ";
    cin >> pop;
    //validate pop to be greater than 2
    while (pop < 2)
    {
        cout << "Starting population must be 2 or more." << endl;
        cout << "Please re-enter: ";
        cin >> pop;
    }

    cout << "Enter the annual birth rate (as % of current population): ";
    cin >> birthRate;
    //validate birth rate to be positive
    while (birthRate < 0)
    {
        cout << "Birth rate percent cannot be negative." << endl;
        cout << "Please re-enter: ";
        cin >> birthRate;
    }
    birthRate /= 100;

    cout << "Enter the annual death rate (as % of current population): ";
    cin >> deathRate;
    //validate death rate to be positive
    while (deathRate < 0)
    {
        cout << "Death rate percent cannot be negative." << endl;
        cout << "Please re-enter: ";
        cin >> deathRate;
    }
    deathRate /= 100;

    cout << "How many individuals move into the area each year? ";
    cin >> annualArrived;
    //validate the annual people arrived to be positive
    while (annualArrived < 0)
    {
        cout << "Arrivals cannot be negative." << endl;
        cout << "Please re-enter: ";
        cin >> annualArrived;
    }

    cout << "How many individuals leave the area each year? ";
    cin >> annualMoved;
    //validate the annual people moved to be positive
    while (annualMoved < 0)
    {
        cout << "Departures cannot be negative." << endl;
        cout << "Please re-enter: ";
        cin >> annualMoved;
    }

    cout << "For how many years do you wish to view population changes? ";
    cin >> years;
    //validate the years to be 1 or more years
    while (years < 1)
    {
        cout << "Years must be one or more." << endl;
        cout << "Please re-enter: ";
        cin >> years;
    }

    //extra spacing
    cout << endl << endl;

    //print starting pop
    cout << "Starting population: " << pop << endl << endl;
    //loop to print new pop size over set years
    for (double i = 1; i <= years; i++)
    {
        //calculate new pop size
        pop = popSize(pop, birthRate, deathRate, annualArrived, annualMoved);
        cout << "Population at the end of year " << i << " is " << floor(pop) << "." << endl;
    }
}

//calcualtes new pop size and returns the value
double popSize(double pop, double birthRate, double deathRate, double annualArrived, double annualMoved)
{
    return (pop + (birthRate * pop) - (deathRate * pop) + annualArrived - annualMoved);
}