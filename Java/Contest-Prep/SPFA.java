public static int[] spfa(int[][] graph, int nodeCount, int start){
	int[] distance = new int[nodeCount];
	boolean[] contains = new boolean[nodeCount];
	Arrays.fill(distance, Integer.MAX_VALUE);
	
	Queue<Integer> q = new LinkedList<Integer>();
	distance[start] = 0;
	q.add(start);
	
	while(!q.isEmpty()){
		int cur = q.remove();
		contains[cur] = false;
		for(int i = 0; i < nodeCount; i++){
			if(graph[cur][i] != 0 && distance[i] > distance[cur] + graph[cur][i]){
				distance[i] = distance[cur] + graph[cur][i];
				if(!contains[i]){
					q.add(i);
					contains[i] = true;
				}
			}
		}
	}
	return distance;
}
