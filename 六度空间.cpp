//���ȿռ�

//��ÿ���ڵ㣬���й����������
//�����������ۼƷ��ʵĽڵ���
//��Ҫ��¼���㡱����������6�����ڵĽڵ��� 

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
		for(each W of V){ //��V��ÿ���ڽӵ� 
			if(!visited[W]){
				visited[W] = true;
				Enqueue(W, Q);
				count++;
				tail = W; //��һ������ 
			}
		}
		if(V == last){ //�������һ������һ����� 
				level++; //������һ 
				last = tail; //��һ������ 
			}
	}
	return count;
}
