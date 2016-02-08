public static void main(String args[]){
	Map<Integer, ArrayList<Edge>> adjList = new HashMap<Integer, ArrayList<Edge>>();
	//Initialization
	int nodeCount = 0;
	for(int i = 0; i < nodeCount; i++){
		adjList.put(i, new ArrayList<Edge>());
	}
	//Add edge
	int a = 0, b = 0, weight = 0;
	adjList.get(a).add(new Edge(a, b, weight));
}

public static class Edge implements Comparable<Edge>{
	int source, target, cost;
	Edge(int source, int target, int cost){
		this.source = source;
		this.target = target;
		this.cost = cost;
	}
	@Override
	public int compareTo(Edge e) {
		return cost - e.cost; 
	}
}
