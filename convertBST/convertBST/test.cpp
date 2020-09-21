//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//
//#include<iostream>
//using namespace std;
//struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	int sum = 0;
//	TreeNode* convertBST(TreeNode* root) {
//		if (root != NULL)
//		{
//			convertBST(root->right);
//			sum += root->val;
//			root->val = sum;
//			convertBST(root->left);
//		}
//		return root;
//	}
//};
//
//int main()
//{
//	return 0;
//}



//#include<iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//bool iscf(string& s)
//{
//	unordered_map<char, int> m;
//	for (int i = 0; i < s.size(); i++)
//	{
//		m[s[i]]++;
//	}
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (m[s[i]] > 1)
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	string ret;
//	int j = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		for (int j = 1; j < s.size(); j++)
//		{
//			string tmp = s.substr(i, j - i);
//			if (iscf(tmp))
//			{
//				if (tmp.size() > ret.size())
//					ret = tmp;
//			}
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;

void splits(string& s, string& s1, string& s2)
{
	int i;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			break;
	}
	s1 = s.substr(0, i);
	s2 = s.substr(i + 1, s.size() - i - 1);
}

bool istrue(const char* s1, const char* s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return true;
	if (*s1 == '\0' || *s2 == '\0')
		return false;
	//if (*s1 == *s2 || *s2 == '.')
	//{
	//	return istrue(s1 + 1, s2 + 1);
	//}
	//else
	//{
	//	if (*s1 == *(s2 - 1))
	//		return istrue(s1 + 1, s2) || istrue(s1 + 1, s2 + 1);
	//	else
	//		return istrue(s1, s2 + 1);
	//}

	if (*(s2 + 1) == '*')
	{
		if (*s1 == *s2 || *s2 == '.')
		{
			return istrue(s1 + 1, s2) || istrue(s1 + 1, s2 + 2) || istrue(s1, s2 + 2);
		}
		else
			return istrue(s1, s2 + 2);
		
	}

	else
	{
		if (*s1 == *s2 || *s2 == '.')
			return istrue(s1 + 1, s2 + 1);
		else
			return false;
	}

}

int main()
{
	string s1, s2;
	
	while (cin >> s1 >> s2)
	{

		//splits(s, s1, s2);

		if (istrue(s1.c_str(), s2.c_str()))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}