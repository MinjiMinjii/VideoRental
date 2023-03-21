// Movie.cpp
#include "Movie.h"

//const int Movie::REGULAR;
//const int Movie::NEW_RELEASE;
//const int Movie::CHILDRENS;
//const int Movie::EXAMPLE_GENRE;

Movie::Movie(const std::string& title, int priceCode) :
	movieTitle(title),
	moviePriceCode(priceCode)
{}

int Movie::getPriceCode() const { return moviePriceCode; }

void Movie::setPriceCode(int arg) { moviePriceCode = arg; }

std::string Movie::getTitle() const { return movieTitle; }
