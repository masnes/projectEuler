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
  int counter = 1;
  for (int i = 1; i <= 15; i++) {
    for (int j = 1; j <= i; j++) {
      myfile >> set;
      val_array[counter] = set;
      printf(" %d ", val_array[counter]);
      counter++;
    }
    printf("\n");
  }
  /* graph display for each numbers */
  // 120 numbers, 2 children per number (0 and 1)
  // array storing the 
  int lineoffset[15];
  counter = 1;
  for (int i = 0; i <= 14; i++) {
    for (int j = 1; j <= i; j++) {
      counter++;
    }
    lineoffset[i] = counter;
    // printf("lineoffset at %d = %d \n", i, lineoffset[i]);
  }
  int graph[105][1];
  int line = 1;
  int column = 0;
  // 105 numbers before the last row
  for (int i = 1; i <= 105; i++) {
    if (column >= line) {
      line++;
      column = 0;
    } else {
      column++;
    }
    printf("line: %d, column: %d\n", line, column);
    graph[i][0] = lineoffset[line+0] + column - 1;
    graph[i][1] = lineoffset[line+1] + column;
  }
  for (int i = 0; i <= 105; i++) {
    printf("graph[%d][%d] = %d | ", i, 0, graph[i][0]);
    printf("graph[%d][%d] = %d\n", i, 1, graph[i][1]);
  }

  /* iterate through array changing values to tree */
  // TODO: iterate array into a tree
  // TODO: do dfs through tree
  // DONE: iterate through array finding 4 highest consecutive values
  // counters tro track the through-array dfs
}
