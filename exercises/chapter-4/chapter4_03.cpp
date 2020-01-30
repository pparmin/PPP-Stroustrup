#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* Exercise 3: Calculate distances between points 

Description:
Read a sequence of double values into a vector. Think of each value as the distance
between two cities along a given route. Compute and print the total distance. Find
and print the smallest and greatest distance between two neighboring cities. Find
and print the mean distance between two neighboring cities. 

*/

int main() 
{
  vector<double> distances;
  double sum;
  double smallest_distance;
  double largest_distance;
  double distance;

  for(double distance; cin >> distance;) {
    if (distances.size() == 0) {
      cout << "No distances entered.\n";
      return 0;
    }

    distances.push_back(distance);
  }

  for (int i = 0; i < distances.size(); i++) {
    // compute total distance
    sum += distances[i];

    if (i == 0) {
      smallest_distance = distances[i];
      largest_distance = distances[i];
    }

    distance = abs(distances[i] - distances[i - 1]);

    if (distance < smallest_distance) {
      smallest_distance = distance;
    } else if (distance > largest_distance) {
      largest_distance = distance;
    }

  }

  cout << "Sum of all distances: " << sum << endl;
  cout << "Largest Distance: " << largest_distance << endl;
  cout << "Smallest Distance: " << smallest_distance << endl; 
}