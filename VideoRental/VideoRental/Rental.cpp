#include "Rental.h"

Rental::Rental(const Movie& movie, int daysRented) :
	rentedMovie(movie),
	nDaysRented(daysRented) {}

int Rental::getDaysRented() const { return nDaysRented; }

const Movie& Rental::getMovie() const { return rentedMovie; }