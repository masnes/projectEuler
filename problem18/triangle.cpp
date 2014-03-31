#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <sstream>

using namespace std;

struct node {
  node* parent = NULL;
  node* leftchild = NULL;
  node* rightchild = NULL;
  int val = INT_MAX;
};

int main(void) {
  fstream myfile("./triangle.txt", ios_base::in);
  /* read numbers in triangles file into an array */
  int set;
  // there are 120 numbers in the triangles file
  int a[120];
  int counter = 1;
  for (int i = 1; i <= 15; i++) { 
    for (int j = 1; j <= i; j++) {
      myfile >> set;
      a[counter] = set;
      printf(" %d ", a[counter]);
      counter++;
    }
    printf("\n");
  }

  /* iterate through array in a dfs */
  // TODO: iterate array into a tree
  // TODO: do dfs through tree
  // DONE: iterate through array finding 4 highest consecutive values
  // counters tro track the through-array dfs
  int count = 0;
  // maximum found value
  int maxvalfound = 0;
  // values for current path
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  int val4 = 0;
  // some of values for current path
  int curvalsum = 0;
  // locational placers to track the different items being looked at
  int count1 = 0;
  int count2 = 0;
  int count3 = 0;
  int count4 = 0;
  // locational placers to track the highest set of numbers yet
  int val1location = 0;
  int val2location = 0;
  int val3location = 0;
  int val4location = 0;
  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= i; j++) {
      count1++;
      val1 = a[count1];
      for (int k = 0; k <=1; k++) {
        count2 = count1 + i + k;
        val2 = a[count2];
        for (int l = 0; l <=1; l++) {
          count3 = count2 + i+1 +l;
          val3 = a[count3];
          for (int m = 0; m <=1; m++) {
            count4 = count3 + i+2 + m;
            val4 = a[count4];
            curvalsum = val1 + val2 + val3 + val4;
            if (curvalsum > maxvalfound) { 
              maxvalfound = curvalsum;
              val1location = count1;
              val2location = count2;
              val3location = count3;
              val4location = count4;
            }
          }
        }
      }
    }
  }
  printf("\nThe maximum value found is: %d\n", maxvalfound);
  printf("These values were found at array locations: %d,%d,%d,%d\n", val1location, val2location, val3location, val4location);
  printf("And are equal to: %d,%d,%d,%d\n", a[val1location], a[val2location], a[val3location], a[val4location]);
  return 0;
}
