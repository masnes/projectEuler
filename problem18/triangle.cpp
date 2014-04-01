#include "triangle.h"

using namespace std;

int main(void) {

  /* read numbers in triangles file into an array */
  fstream myfile("./triangle.txt", ios_base::in);
  int set;
  // there are 120 numbers in the triangles file
  int val_array[120];
  int counter = 0;
  for (int i = 1; i <= 15; i++) {
    for (int j = 1; j <= i; j++) {
      myfile >> set;
      val_array[counter] = set;
      // for debugging (should print out triangle of numbers)
      // be sure to uncomment the next cout statement as well
      // cout << counter << ":" << val_array[counter] << "  ";
      counter++;
    }
    // for debugging (should print out triangle of numbers)
    // be sure to uncomment the previous cout statement as well
    // cout << endl;
  }

  /* detect what each offset of the val_array that
   * represents the start of a new line of values:
   *
   * we're using a linear array to store the triangle data
   * we need some way to find this offset
   * will be used as tool for populating a graph
   * that properly links between each value and its
   * two children values (in the next line)
   */
  int lineoffset[15];
  counter = 0;
  for (int i = 0; i <= 15; i++) {
    for (int j = 1; j <= i; j++) {
      counter++;
    }
    lineoffset[i] = counter;
    // printf("lineoffset at %d = %d \n", i, lineoffset[i]);
  }

  /*
   * build a graph that links between each value and the values
   * below it
   */
  // only using graph[i][0] and graph[i][1], but the extra padding seems to avoid a bug (array space overflow issues?)
  // 120 numbers, 2 children per number (0 and 1) except for last row
  // 105 numbers before last row
  int graph[105][2];
  int line = 0;
  int column = 0;
  // 105 numbers before the last row
  for (int i = 0; i <= 104; i++) {
    if (column > line) {
      line++;
      column = 0;
    }
    // printf("line: %d, lineoffset: %d, column: %d\n", line, lineoffset[line], column);
    graph[i][0] = lineoffset[line+1] + column;
    graph[i][1] = lineoffset[line+1] + column + 1;
    column++;
  }

  /*
  // test to see if "graph" contains the correct values
  for (int i = 0; i <= 104; i++) {
    cout << i << ": " << graph[i][0] << " " << graph[i][1] << endl;
  }
  */
  int maximum = findmax(val_array, graph, 0, 0);
  cout << "The maximum value found is: " << maximum << endl;
}

int findmax(int val_array[120], int graph[105][2], int curposition, int curval) {
  int max1 = -1;
  int max2 = -1;
  curval = curval + val_array[curposition];
  // there are 105 numbers before the last row of numbers
  if (curposition <= 104) {
    max1 = findmax(val_array, graph, graph[curposition][0], curval);
    max2 = findmax(val_array, graph, graph[curposition][1], curval);
  }
  else {
    return curval;
  }
  if (max1 == -1 || max2 == -1) {
    cerr << "Error, max values not initialized in recursive function \n";
    return -1;
  }
  return max1 > max2 ? max1 : max2;
}

  /* iterate through array changing values to tree */
  // DONE: iterate array into a tree
  // TODO: do full iteration through each tree
  // DONE: iterate through array finding 4 highest consecutive values
  // counters to track the through-array dfs
