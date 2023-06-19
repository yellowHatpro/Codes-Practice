class Solution {
public:

		int find(int node, vector<int>& parent){
			if (parent[node]==node) return node;
			else return find(parent[node], parent);
		}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
				vector<int> parent(n+1);
				for(int i = 1; i<n; i++){
					parent[i] = i;
				}
				for(int i = 0; i<edges.size(); i++){
					int parent1 = find(edges[i][0],parent);
					int parent2 = find(edges[i][1],parent);
					if (parent1==parent2){
						return edges[i];
					} else {
						parent[parent1] = parent2;
					}
				}
				return {};
    }
};