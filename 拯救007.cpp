//����007
//С�������㡢�԰����Ƕ���

//����ⲻ�����ڽӾ�����ڽӱ���ã���Ϊ��������ǲ���֪��
//��Щ�����������Ҫ��������֮������жϡ�DFSʱ���ж��Ƿ�
//�ܵ������ܾ� return true�����ܾ͵ݹ��ܹ�������û�С����ʡ�
//�������㣬�ݹ鷵�ص�ֵΪtrue������һ��ͷ���true, �����
//���ݹ���һ���ܹ�������û�С����ʡ��������㡣Ҫ�ҵ��ܹ���
//�������㣬ѭ��ÿһֻ���㼴�ɣ��������ڽӱ�Ҳ��Ҫѭ��ÿһ
//ֻ���㣬���ܵõ���һֻ�������ڵ��������㡣

void ListComponent(Graph G){
	for(each V in G){
		if(!visited[V]){
			DFS(V);
		}
	}
} 

void Save007(Graph G){
	for(each V in G){
		if(!visited[V] && FirstJump(V)){ //��һ�����ڰ뾶��ͬ��Ҫ�������� 
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
	if(IsSafe(V)){ //����ܵ��԰� 
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
