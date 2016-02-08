public static int PrimsEVLogV(Map<Integer, ArrayList<Edge>> graph, int root, int nodeCount, int edgeCount){
	boolean[] visited = new boolean[nodeCount];
	int[] prev = new int[nodeCount]; //connecting path of node
	int[] weight = new int[nodeCount]; //weight of connecting path
	int mst = 0;
	PriorityQueue<Edge> q = new PriorityQueue<>();
	q.add(new Edge(root, root, 0));
	while(!q.isEmpty()){
		Edge cur = q.remove();
		if(visited[cur.target])
			continue;
		visited[cur.target] = true;
		prev[cur.target] = cur.source;
		weight[cur.target]  = cur.cost;
		mst += cur.cost;
		for(Edge e : graph.get(cur.target)){
			if(!visited[e.target])
				q.add(e);
		}
	}
	
	for(int i = 0; i < nodeCount; i++){
		if(!visited[i]) //Use v^2 to find minimum spanning forest if needed
			return -1; //That means an mst cannot be created
	}
	
	return mst;
}
