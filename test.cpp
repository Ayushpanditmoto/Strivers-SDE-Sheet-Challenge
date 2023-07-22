// There is a farm containing trees numbered from 1 to N.  Milky believes in god, so she thinks that a tree can only be cut down if it's height is a Prime number. The height of the trees increases by 1 unit every day. So every day she goes to the farm and starts cutting trees whose height is a prime number. If there are multiple such trees in a day, she cuts them down in increasing order of the index.

// Print the order of trees in which they will be cut down.

// Explanation
// First day trees numbered 1 and 5 will be cut down, now the height of trees 2,3,4 will remains same.

// Second day trees numbered 2 and 4 will be cut down, as there height will be 13 and 5 , now the height of tree 3 will be 99 it will remain there.

// Third day no tree will be cut down as the height of the remaining tree is 100.

// Fourth day tree 3 will be cut down as its height will be 101.

#include <bits/stdc++.h>
using namespace std;
int 