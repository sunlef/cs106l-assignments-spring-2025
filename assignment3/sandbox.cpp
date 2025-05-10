/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"
#include <iostream>

void sandbox() {
  Accumulator<double> x;
  x.add(3);
  x.add(3.14);
  x.add(100);
  x.add(-99);
  std::cout << x.getMin() << " " << x.getMax() << " " << x.getCount() << " "
            << x.getSum() << " " << x.getMean() << "\n";
}