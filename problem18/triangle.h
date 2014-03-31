#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <sstream>

struct node {
  node* leftparent = NULL;
  node* rightparent = NULL;
  node* leftchild = NULL;
  node* rightchild = NULL;
  int val = INT_MAX;
};

int main(void);

node* addNode(node* root, int level, int column, int val);
