public static int bfs(boolean[][] graph, int nodeCount, int start, int goal){
	boolean[] visited = new boolean[nodeCount];
	int[] dist = new int[nodeCount];
	Queue<Integer> q = new LinkedList<Integer>();
	q.add(start);
	visited[start] = true;
	while(!q.isEmpty()){
		int cur = q.remove();
		if(cur == goal)
			break;
		for(int i = 0; i < nodeCount; i++){
			if(graph[cur][i] && !visited[i]){
				q.add(i);
				visited[i] = true;
				dist[i] = dist[cur] + 1;
			}
		}
	}
	return dist[goal];
}
