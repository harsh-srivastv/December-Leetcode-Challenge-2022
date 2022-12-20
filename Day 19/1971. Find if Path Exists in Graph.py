# https://leetcode.com/problems/find-if-path-exists-in-graph/

from ast import List

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # create a adjacency list representation of the graph
        adj_list = {}
        for u, v in edges:
            if u not in adj_list:
                adj_list[u] = []
            if v not in adj_list:
                adj_list[v] = []
            adj_list[u].append(v)
            adj_list[v].append(u)

    # mark all vertices as not visited
        visited = [False] * n

    # create a stack for DFS
        stack = []

    # push the source vertex to the stack and mark it as visited
        stack.append(source)
        visited[source] = True

    # while the stack is not empty
        while stack:
        # pop the top vertex from the stack
            u = stack.pop()

        # if the vertex is the destination, return True
            if u == destination:
                return True

        # get the neighbors of the vertex
            neighbors = adj_list.get(u, [])

        # push the unvisited neighbors of the vertex to the stack and mark them as visited
            for v in neighbors:
                if not visited[v]:
                    stack.append(v)
                    visited[v] = True

    # if we reach here, it means there is no path from source to destination
        return False