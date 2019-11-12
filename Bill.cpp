#include <string>

#include "Bill.hpp"

/************************************************
** Member function definitions
************************************************/


Bill::Bill(const std::string & name,
		const double & dues,
		const unsigned int & month,
		const unsigned int & day) {} //BILL default constructor


bool Bill::isOverdue(const unsigned int &currMonth,
		     const unsigned int& currDay ) {
if(due_month_ < currMonth) //if due month is less than current month -> true
		return true;
if (due_month_ == currMonth) { //if due month is the same as current month, check if the due day is less than current date
	if (due_day_ < currDay) {
		return true;
	}
}

return false;
}

// This function member implementation is complete
unsigned int Bill::daysOverdue(const unsigned int &currMonth,
			       const unsigned int& currDay ) {
  // computes the number of days elapsed between the due date
  // of the bill and the date (month and day) given as parameters
  if (due_month_ > currMonth )
    return 0;
  if (due_month_ == currMonth ) {
    if (due_day_ >= currDay)
      return 0;
    else
      return (currDay - due_day_);
  }
  unsigned int counter=0;
  unsigned int tempMonth=due_month_;
  unsigned int tempDay = due_day_;
  while (tempMonth < currMonth) {
    switch (tempMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      counter = counter + 31 - tempDay;
      break;
    case 2:
      counter = counter + 28 - tempDay;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      counter = counter + 30 - tempDay;
    }
    tempDay = 0;
    tempMonth++;
  }
  counter = counter + currDay;

  return counter;
}
