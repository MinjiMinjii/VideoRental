#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    //price code: REGULAR - 0 / NEW_RELEASE - 1 / CHILDRENS - 2 
    //(No price, Only code for using switch/case)
    Movie regular1{ "�Ϲ� 1", Movie::REGULAR };
    Movie regular2{ "�Ϲ� 2", Movie::REGULAR };
    Movie newRelease1{ "���� 1", Movie::NEW_RELEASE };
    Movie newRelease2{ "���� 2",Movie::NEW_RELEASE };
    Movie children1{ "��� 1", Movie::CHILDRENS };
    Movie children2{ "��� 2", Movie::CHILDRENS };
    Movie newGenre1{ "�� �帣1", Movie::EXAMPLE_GENRE };
    Movie newGenre2{ "�� �帣2", Movie::EXAMPLE_GENRE };
    Customer customer{ "��" };

    //parameter: Movie(Movie title, Price code), Rental days
    //addRental: Add parameters to Rental unit vector (customerRentals)
    //(Rental Class -> Movie(Movie title, Price code), Rental days)
    customer.addRental({ regular1, 2 });
    customer.addRental({ regular2, 3 });
    customer.addRental({ newRelease1, 1 });
    customer.addRental({ newRelease2, 2 });
    customer.addRental({ children1, 3 });
    customer.addRental({ children2, 4 });
    customer.addRental({ newGenre1, 2 });
    customer.addRental({ newGenre2, 4 });

    cout << customer.statement() << endl;

    return 0;
}
