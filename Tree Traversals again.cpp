//Tree Traversals again
//根据前序和中序得到后序遍历
 
void solve(int preL, int inL, int postL, int n){
	if(n == 0) return;
	if(n == 1) {post[postL] = pre[preL]; return;}
	
	root = pre[preL]; //找到根结点 
	post[postL + n - 1] = root;
	for(i = 0; i < n; i++){
		if(in[inL + i] == root){
			break; //以根结点为中心将中序遍历分成左右两边，再递归调用函数 
		}
	}
	L = i;
	R = n - L - 1;
	//递归 
	solve(preL + 1, inL, postL, L); //解决左边 
	solve(preL + L + 1, inL + L + 1, postL + L, R); //解决右边 
}
