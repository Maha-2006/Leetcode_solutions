class Solution {
    private static final int MOD = 1000000007;

    public int countPaths(int n, int[][] roads) {
        // Step 1: Build the adjacency list
        List<List<long[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Creating undirected edges for the graph
        for (int[] road : roads) {
            adj.get(road[0]).add(new long[]{road[1], road[2]});
            adj.get(road[1]).add(new long[]{road[0], road[2]});
        }

        // Step 2: Initialize Dijkstra's algorithm data structures
        PriorityQueue<long[]> minHeap = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        minHeap.offer(new long[]{0, 0}); // {cost, node}: Source is node 0

        boolean[] processed = new boolean[n];
        long[] countWays = new long[n]; // Count total ways to reach a node from start (0)
        countWays[0] = 1; // There is 1 way to reach the start node

        long[] minCost = new long[n];
        Arrays.fill(minCost, Long.MAX_VALUE);
        minCost[0] = 0; // Initialize min_cost for the source node

        // Step 3: Run Dijkstra's algorithm to find the shortest path
        while (!minHeap.isEmpty()) {
            long[] curr = minHeap.poll();
            long cost = curr[0];
            int currNode = (int) curr[1];

            if (processed[currNode]) continue; // Skip if already processed
            processed[currNode] = true;

            // Explore neighbors
            for (long[] neighbor : adj.get(currNode)) {
                int nbr = (int) neighbor[0];
                long weight = neighbor[1];

                // If this path gives the same minimum cost, count the ways
                if (!processed[nbr]) {
                    if (cost + weight == minCost[nbr]) {
                        // Found another shortest path
                        countWays[nbr] = (countWays[nbr] + countWays[currNode]) % MOD;
                    } else if (cost + weight < minCost[nbr]) {
                        // Found a shorter path
                        minCost[nbr] = cost + weight;
                        countWays[nbr] = countWays[currNode];
                        minHeap.offer(new long[]{minCost[nbr], nbr});
                    }
                }
            }
        }

        // Step 4: Return the total number of ways to reach the last node (n-1)
        return (int) countWays[n - 1];
    }
}
