#include <stdio.h>
#include "header.h"

double excessAmount(double allowable, double actual) {
    return (actual > allowable) ? (actual - allowable) : 0.0;
}
double saveAmount(double allowable, double actual) {
    return (actual < allowable) ? (allowable - actual) : 0.0;
}