#include "triangle.h"

using namespace std;

/*
 * struct node {
 *   node* leftparent = NULL;
 *   node* rightparent = NULL;
 *   node* leftchild = NULL;
 *   node* rightchild = NULL;
 *   int val = INT_MAX;
 * };
 */

class nullNodePassed
{
  public:
    int level;
    int column;
    int val;
    nullNodePassed(int level, int column, int val);
};

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
      cout << counter << ":" << val_array[counter] << "  ";
      counter++;
    }
    cout << endl;
  }
  /* graph display for each numbers */
  // 120 numbers, 2 children per number (0 and 1) except for last row
  // 105 numbers before last row
  // array storing the offset to the beginning of each line
  int lineoffset[15];
  counter = 0;
  for (int i = 0; i <= 15; i++) {
    for (int j = 1; j <= i; j++) {
      counter++;
    }
    lineoffset[i] = counter;
    printf("lineoffset at %d = %d \n", i, lineoffset[i]);
  }
  // only using graph[i][0] and graph[i][1], but the extra padding seems to avoid a bug (array space overflow issues?)
  int graph[105][2];
  int line = 0;
  int column = 0;
  // 105 numbers before the last row
  for (int i = 0; i <= 104; i++) {
    if (column >= line) {
      line++;
      column = 0;
    }
    // printf("line: %d, lineoffset: %d, column: %d\n", line, lineoffset[line], column);
    graph[i-1][0] = lineoffset[line] + column - 1;
    graph[i-1][1] = lineoffset[line] + column;
    // if (i > 1)
    //   cout << graph[i-2][0] << " " << graph[i-2][1] << endl;
    // cout << graph[i-1][0] << " " << graph[i-1][1] << endl;
    column++;
  }

  for (int i = 0; i <= 104; i++) {
    cout << i << ": " << graph[i][0] << " " << graph[i][1] << endl;
  }

  /*
  for (int i = 0; i <= 104; i++) {
    printf("graph[%d][%d] = %d | ", i, 0, graph[i][0]);
    printf("graph[%d][%d] = %d\n", i, 1, graph[i][1]);
  }
  */

  /* iterate through array changing values to tree */
  // TODO: iterate array into a tree
  // TODO: do dfs through tree
  // DONE: iterate through array finding 4 highest consecutive values
  // counters tro track the through-array dfs
}
