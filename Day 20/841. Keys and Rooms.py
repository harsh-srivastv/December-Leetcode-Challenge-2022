# https://leetcode.com/problems/keys-and-rooms/

from ast import List

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        # Set of visited rooms
        visited = set()
        # Queue for BFS
        queue = []
        # Add room 0 to the queue and mark it as visited
        queue.append(0)
        visited.add(0)
    
        # While there are rooms in the queue
        while queue:
            # Get the next room
            room = queue.pop(0)
            # Get the keys for the room
            keys = rooms[room]
            # Add the keys to the queue and mark them as visited
            for key in keys:
                if key not in visited:
                    queue.append(key)
                    visited.add(key)
    
        # Return whether all rooms have been visited
        return len(visited) == len(rooms)
        