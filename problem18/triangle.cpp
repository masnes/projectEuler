#include <triangle.h>

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

  /* iterate through array changing values to tree */
  // TODO: iterate array into a tree
  // TODO: do dfs through tree
  // DONE: iterate through array finding 4 highest consecutive values
  // counters tro track the through-array dfs
  try {
    addNode(NULL, 0, 0, 0);
  }
  catch (nullNodePassed) {
    cerr << "Attempted to pass a null node";
  }
  return 0;
}

node* addNode(node* root, int level, int column, int val) {
  if (root == NULL) {
    if (level == 1) {
    }
    else {
      throw nullNodePassed(level, column, val);
      return NULL;
    }
  }
}
