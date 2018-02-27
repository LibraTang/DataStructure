//六度空间

//对每个节点，进行广度优先搜索
//搜索过程中累计访问的节点数
//需要记录“层”数，仅计算6层以内的节点数 

void SDS(){
	for(each V in G){
		count = BFS(V);
		output(count/N); 
	}
}

int BFS(Vertex V){
	visited[V] = true;
	count = 1;
	level = 0; last = V;
	Enqueue(V, Q);
	while(!IsEmpty(Q)){
		V = Dequeue(Q);
		for(each W of V){ //对V的每个邻接点 
			if(!visited[W]){
				visited[W] = true;
				Enqueue(W, Q);
				count++;
				tail = W; //下一层的起点 
			}
		}
		if(V == last){ //如果是这一层的最后一个结点 
				level++; //层数加一 
				last = tail; //下一层的起点 
			}
	}
	return count;
}
