//Tree Traversals again
//����ǰ�������õ��������
 
void solve(int preL, int inL, int postL, int n){
	if(n == 0) return;
	if(n == 1) {post[postL] = pre[preL]; return;}
	
	root = pre[preL]; //�ҵ������ 
	post[postL + n - 1] = root;
	for(i = 0; i < n; i++){
		if(in[inL + i] == root){
			break; //�Ը����Ϊ���Ľ���������ֳ��������ߣ��ٵݹ���ú��� 
		}
	}
	L = i;
	R = n - L - 1;
	//�ݹ� 
	solve(preL + 1, inL, postL, L); //������ 
	solve(preL + L + 1, inL + L + 1, postL + L, R); //����ұ� 
}
