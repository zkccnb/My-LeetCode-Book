#include"inorderTraversal.cpp"
using namespace std;
int main() {
	int arr[] = { 3,9,20,null,null,15,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	TreeNode* root = new TreeNode(arr, size);
	cout << root << endl;
	/*vector<int> ret= Solution().inorderTraversal(root);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}*/
}
//int main() {
//	cout << Solution().isValidSerialization("1,#,#,#,#") << endl;
//}