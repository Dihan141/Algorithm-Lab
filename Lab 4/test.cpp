  #include<iostream> 
  #include<bits/stdc++.h> 
  using namespace std;  
    
  // Sets the maximum number of houses 
  const int N = 100; 
    
  // Stores the distances between each house 
  int dist[N][N]; 
    
  // Function to calculate the overall cost 
  int calculateCost(int n) 
  { 
      // Stores the house with lowest cost 
      int cost[N];
    
      cost[0] = 0; 
    
      // Calculates the cost for each house 
      for (int i = 1; i < n; i++) { 
          cost[i] = INT_MAX; 
    
          for (int j = 0; j < i; j++) { 
              if (cost[i] > dist[i][j] + cost[j]) 
                  cost[i] = dist[i][j] + cost[j]; 
          } 
      } 
    
      // Returns the total cost 
      return cost[n - 1]; 
  } 
    
  // Driver code 
  int main() 
  { 
      int n, m; 
    
      // Reads the inputs 
      cin >> n >> m; 
    
      // Sets the distances to -1 
      memset(dist, -1, sizeof(dist)); 
    
      // Stores each edge with its distance in the matrix 
      for (int i = 0; i < m; i++) { 
          int a, b, c; 
          cin >> a >> b >> c; 
          dist[a][b] = c; 
          dist[b][a] = c; 
      } 
    
      // Prints the total cost 
      cout << calculateCost(n) << endl; 
    
      return 0; 
  } 
  