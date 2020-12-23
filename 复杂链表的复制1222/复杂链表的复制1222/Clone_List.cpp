#include <iostream>
#include <list>
using namespace std;

//��ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)������һ����������
//�ڸ��������У�ÿ���ڵ������һ��m_pNextָ��ָ����һ���ڵ㣬����һ��m_pSiblingָ��ָ�������е�����ڵ����nullptr
struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

//����ԭʼ���������ڵ�N�������½ڵ�N'���ٰ�N'���ӵ�N�ĺ���
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		//����һ��ȫ�µĽڵ�������ÿһ�θ��ƽڵ�Ĺ���
		ComplexListNode* pCloned = new ComplexListNode();
		//���ƽڵ��ֵ��ԭ�ڵ��ֵ���
		pCloned->m_nValue = pNode->m_nValue;
		//���ƽڵ��m_pNextָ����һ�����Ǽ���Ҫ���ƵĽڵ�
		pCloned->m_pNext = pNode->m_pNext;
		//��һ�����Ȱ�m_pSibling�ÿգ�֮���ڽ��ж���ָ�����
		pCloned->m_pSibling = nullptr;

		//����Ҫ���ƵĽڵ㣬��Ϊ���Ǹ��ƽڵ����һ���ڵ�
		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}

//���ԭʼ�����ϵĽڵ�N��m_pSiblingָ��S��������Ӧ�ĸ��ƽڵ�N'��m_pSiblingָ��S�ĸ��ƽڵ�S'
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		//��pCloned���������ǵĸ��ƽڵ�
		ComplexListNode*pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != nullptr)
		{
			//���ƽڵ��m_pSiblingָ��Ϊ����ԭ�ڵ��m_pSibling��ָ��ĸ��ƽڵ�
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		//����������Ҫ��m_pSibling�Ľڵ�
		pNode = pCloned->m_pNext;
	}
}

//�ѵڶ����õ��������ֳ�������������λ���ϵĽڵ����ԭʼ������ż��λ���ϵĽڵ���ɸ��Ƴ���������
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	//����ڵ��������渴�������ͷ�ڵ�
	ComplexListNode* pClonedHead = nullptr;
	//���帴�ƽڵ������и�������Ľڵ�仯
	ComplexListNode* pClonedNode = nullptr;

	if (pNode != nullptr)
	{
		//���¸��������ͷ�ڵ��Լ��������ڵ�ı仯
		pClonedHead = pClonedNode = pNode->m_pNext;
		//pNode��������ԭʼ����Ľڵ�任(ԭʼ�����ԭʼ�ڵ�������һ���ڵ�ĸ��ƽڵ��next��)
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != nullptr)
	{
		//���帴�ƽڵ��nextָ��
		pClonedNode->m_pNext = pNode->m_pNext;
		//���ø��ƽڵ�
		pClonedNode = pClonedNode->m_pNext;
		//����ԭʼ�ڵ��nextָ��(������һ�����ƽڵ����һ��nextָ��)
		pNode->m_pNext = pClonedNode->m_pNext;
		//����ԭʼ�ڵ�
		pNode = pNode->m_pNext;
	}
	//���ظ��������ͷ�ڵ㼴��
	return pClonedHead;
}

//������������Ϊ�����������������
ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

int main()
{

	system("pause");
	return 0;
}