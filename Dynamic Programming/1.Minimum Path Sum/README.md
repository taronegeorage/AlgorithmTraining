Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.   
   
Example   
Example 1:   
	Input:  [[1,3,1],[1,5,1],[4,2,1]]   
	Output: 7   
	   
	Explanation:   
	Path is: 1 -> 3 -> 1 -> 1 -> 1   
  
   
Example 2:  
	Input:  [[1,3,2]]   
	Output: 6   
	   
	Explanation:     
	Path is: 1 -> 3 -> 2   
   
Notice   
you can only go right or down in the path..

   
      
      
      
Solution1.java provides a state transition table to address the problem. Usually they can be solved by the back tracing algorithm (brute force).    
Solution2.java makes use of recurssion formulation to address the problem (similar to the way the recursive algorithm does). Usually two ways to approach: one is recurssion plus 'memorandum' and the other is iterative recurrence. Solution2 is the approach 1, solution1 is the approach 2 but with different track of thoughts.

