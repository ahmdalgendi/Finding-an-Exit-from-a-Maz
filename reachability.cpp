/*
Author Ahmed Elgendy
Tanta university 
Ahmd.algendi@gmail.com




*/
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;
int arr[1000];

int reach(vector<vector<int> > &adj, int x, int y)
 {

  if(x == y)
    return 1;

  arr[x] = 1; // marking that the node is visited


   for(vector<int>::iterator it = adj[x].begin() ; it != adj[x].end() ; it++)
      {
          if(arr[*it] == 0) //checking whether the node is visited before or not
          {
          int ret  = reach(adj,*it,  y); // saving the function return

          if(ret == 1 ) // checking the function return
            return ret;
          }
      }

  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
