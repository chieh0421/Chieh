/**
 *  A class that stores a variable of type double and generates a hash code for it.
 *
 **/

#include "Double.h"
#include <cmath>
#include <typeinfo>

/**
 *  Construct a new Double with the given variable.
 *  @param d the double variable by which the Double stores.
 */
Double::Double(const double& d) {
    this->d = d;
}

/**
 *  Get the value of the double variable.
 *  @return the stored value.
 */
double Double::getvalue() const {
    return d;
}

/**
 *  Returns true if "this" Double and "db" have identical values.
 *  @param db is the second Double.
 *  @return true if the double values are equal, false otherwise.
 */
bool Double::equals(const Double& db) {
    // Replace the following line with your solution.  Be sure to return false
    //   (rather than throwing a ClassCastException) if "db" is not
    //   a Double.
	if ( typeid(Double) != typeid(db))
		return false;
	if (db.getvalue() == d)
		return true;
    return false;
}

/**
 *  Returns a hash code for this Double.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int Double::hashCode() {
    // Replace the following line with your solution.
	union {
		double dou;
		long long int i;
	}u;
	u.dou = d;
	return pow(u.i, u.i >> 32);
}
