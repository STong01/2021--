#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct TreeNode
{
	int m_Value;
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode* m_father;
};

//bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path)
//{
//	if (pRoot == pNode)
//	{
//		return true;
//	}
// 
//    path.push_back(pRoot);
// 
//    bool found = false;
//
//    vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
//    while(!found && i < pRoot->m_vChildren.end())
//    {
//        found = GetNodePath(*i, pNode, path);
//        ++i;
//    }
// 
//	if (!found)
//	{
//		path.pop_back();
//	}
// 
//    return found;
//}
//
//const TreeNode* GetLastCommonNode(const list<const TreeNode*>& path1, const list<const TreeNode*>& path2)
//{
//    list<const TreeNode*>::const_iterator iterator1 = path1.begin();
//    list<const TreeNode*>::const_iterator iterator2 = path2.begin();
//    
//    const TreeNode* pLast = nullptr;
// 
//    while(iterator1 != path1.end() && iterator2 != path2.end())
//    {
//		if (*iterator1 == *iterator2)
//		{
//			pLast = *iterator1;
//		}
// 
//        iterator1++;
//        iterator2++;
//    }
// 
//    return pLast;
//}
//
//const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2)
//{
//	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
//	{
//		return nullptr;
//	}
// 
//    list<const TreeNode*> path1;
//    GetNodePath(pRoot, pNode1, path1);
// 
//    list<const TreeNode*> path2;
//    GetNodePath(pRoot, pNode2, path2);
// 
//    return GetLastCommonNode(path1, path2);
//}


int main()
{

	system("pause");
	return 0;
}