from collections import defaultdict 
 
class Solution: 
	 
	def countCycle(self, n, pairs): 
		self.graph=defaultdict(list) 
		self.visited=defaultdict(lambda: 0) 
		self.count=0 
		for var1, var2 in pairs: 
			self.addEdge(var1,var2) 
 
		for i in range(n): 
			self.depthFirstSearch(i, 0) 
 
		return self.count 
 
	def addEdge(self, var1, var2): 
		self.graph[var1].append(var2) 
 
	def depthFirstSearch(self,var, ct): 
		#if cycle is detected 

		if self.visited[var]==-1: 
			self.count = max(self.count, ct)
			return  
		#if depth first search has been completed on this variable 
		if self.visited[var]==1: 
			return  
 
		self.visited[var], ct = self.visited[var]-1, ct+1
		for neighb in self.graph[var]: 
			self.depthFirstSearch(neighb, ct) 
	 
		#mark depth first search on this variable as completed 
		self.visited[var]=1 
 
 
 
 
def numOfFriends(N, M, friend): 
	s=Solution() 
	num=s.countCycle(N,friend) 
	return num+1
n=9 
pairs=[(0,1),(1,3),(1,6), (2,3), (2, 4), (3, 1),(4,7),(5, 0), (5, 1), (6, 5), (7,2), (7, 3), (7, 8), (8,3)]
print(numOfFriends(n, 12, pairs))