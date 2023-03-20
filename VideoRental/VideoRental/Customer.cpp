// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
  double totalAmount = 0.;
  int frequentRenterPoints = 0;

  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();
  // cutomerRentals: movie title, price code, renatal days (using AddRental())

  // result will be returned by statement()
  std::ostringstream result;
  result << "Rental Record for " << getName() << "\n";

  // Loop over customer's rentals
  for ( ; iter != iter_end; ++iter ) { //Rental counts

    double thisAmount = 0.;
    Rental each = *iter;
    std::string strGenre = "";          //Add Genre name

    // Determine amounts for each rental
    switch ( each.getMovie().getPriceCode() ) {

      case Movie::REGULAR:                          //If REGULAR?
        thisAmount += 2.;                           //Add 2
        if ( each.getDaysRented() > 2 )             //If more than 3 days? Add 1.5/day
          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ; 
        strGenre = "REGULAR";
        break;

      case Movie::NEW_RELEASE:                      //If NEW_RELEASE?
        thisAmount += each.getDaysRented() * 3;     //Add 3/day
        strGenre = "NEW_RELEASE";
        break;

      case Movie::CHILDRENS:                        //If CHILDERN?
        thisAmount += 1.5;                          //Add 1.5
        if ( each.getDaysRented() > 3 )             //If more than 4 days? Add 1.5/day
          thisAmount += ( each.getDaysRented() - 3 ) * 1.5; 
        strGenre = "CHILDREN";
        break;

      case Movie::EXAMPLE_GENRE:                    //If EXAMPLE_GENRE?
          thisAmount += 4;                          //Add 4
          if (each.getDaysRented() > 2)             //If more than 3 days? Add 4/day
              thisAmount += (each.getDaysRented() - 2) * 4; 
          strGenre = "EXAMPLE_GENRE";
          break; 
    }

    // Add frequent renter points
    frequentRenterPoints++;                         //Add Renatal count (1Rental, 1point)

    // Add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;
    //If NEW_RELEASE for more than 2days? Add 1point
    
    // Show figures for this rental
    result << "\t" << strGenre << "\t" << each.getMovie().getTitle() << "\t"
        << each.getDaysRented() << "\t" << thisAmount << std::endl;
    totalAmount += thisAmount;                        //Total price
  }

  // Add footer lines
  result << "Amount owed is " << totalAmount << "\n"; //Total price
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";                //Total points

  return result.str();
}
