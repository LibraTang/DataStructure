//拯救007
//小岛、鳄鱼、对岸都是顶点

//这道题不建立邻接矩阵或邻接表更好，因为这道题我们并不知道
//哪些结点相连，需要计算两点之间距离判断。DFS时先判断是否
//能到岸，能就 return true，不能就递归能够跳到并没有“访问”
//过的鳄鱼，递归返回的值为true函数上一层就返回true, 否则继
//续递归下一个能够跳到并没有“访问”过的鳄鱼。要找到能够跳
//到的鳄鱼，循环每一只鳄鱼即可，而建立邻接表也需要循环每一
//只鳄鱼，才能得到与一只鳄鱼相邻的所有鳄鱼。

void ListComponent(Graph G){
	for(each V in G){
		if(!visited[V]){
			DFS(V);
		}
	}
} 

void Save007(Graph G){
	for(each V in G){
		if(!visited[V] && FirstJump(V)){ //第一跳由于半径不同需要单独考虑 
			answer = DFS(V);
			if(answer = YES){
				break;
			}
		}
	}
	if(answer = YES){
		output("Yes");
	}else{
		output("No");
	}
}

int DFS(Vertex V){
	visited[V] = true;
	if(IsSafe(V)){ //如果能到对岸 
		answer = YES;
	}else{
		for(each W in G){
			if(!visited[W] && Jump(V, W)){
				answer = DFS(W);
				if(answer = YES){
					break;
				}
			} 
		}
	}
	return answer;
}
