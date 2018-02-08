#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){
	int nodes;
	int case_number=1;
	while(scanf("%d", &nodes) != EOF && nodes!=0){

		bool map[101][101]={0};
		int distance[101]={0}; //Show distance from START node
		bool inqueue[101]={0};	
		int start_node;
		scanf("%d", &start_node);	
		//Get map
		int p1, p2;
		while(scanf("%d %d", &p1, &p2)){
			if(p1==0&&p2==0) break;
			
			map[p1][p2]=1;
		}
		//Find Longest path
		queue<int> Q;
		Q.push(start_node);
		while(!Q.empty()){
			int from = Q.front();
			Q.pop();
			inqueue[from]=false;
	
			for(int to=1; to<=nodes; to++){
				if(map[from][to]==1 && distance[from]+map[from][to] > distance[to]){
					distance[to] = distance[from] + 1;
					if(!inqueue[to]){
						Q.push(to);
						inqueue[to] = true;
					}
				}
	
			}
		}
		int final_node=0;
		for(int i = 1; i<=nodes; i++){
			if(distance[i]>distance[final_node]){
				final_node = i;
			}
		}	
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", case_number, start_node, distance[final_node], final_node);
		case_number++;
	}
	system("pause");
	return 0;
}