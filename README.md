## Explanation
- In this question, the goal is to take the rat from source to destination.
- But there are certain conditions:
<ol>
  <li> '0' represents a blocked cell through which the rat cannot travel. </li>
  
  ```cpp
  int source_x = 0;
  int source_y = 0;
  int destination_x = n-1;
  int destination_y = n-1;
  ```

  <li> The rat at a position can only travel: left, right, up, down</li>
  <li> The rat cannot return to the same position more than once</li>

  ```cpp
  // already visited
  if(visited[new_x][new_y] == true){
      return false;
  }
```

  <li>If the source position is 0, then return an empty list</li>
</ol>

## Solution
- To track the movement of the visit status we have to use a Boolean array for every recursive call.
- Once we find the base case, we recursively return to the element covered in the solution.
- While going up, we must ensure that the Boolean array now marked to 'True' is turned back to 'False.'

```cpp
/* recursion case: up, down, left, right */
// case-1: up- (i-1, j)
int new_x = source_x - 1;
int new_y = source_y;
if(isSafe(new_x, new_y, mat, visited, n)){
    visited[new_x][new_y] = true;
    solve(mat,visited,n,ans,new_x,new_y,destination_x,destination_y,output+"U");
    // backtracking: we have to mark the visited part back as false
    visited[new_x][new_y] = false;
}
```
