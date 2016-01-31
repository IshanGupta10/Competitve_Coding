#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x){val = x; next = NULL};	
};

ListNode* mergeLL(ListNode *A, ListNode *B)
{
	ListNode *result = NULL;
	if(A == NULL)
		return B;
	else if(B == NULL)
		return A;
	if(A->val >= B->val)
	{
		result = B;
		result->next = mergeLL(A,B->next);
	}
	else
	{
		result = A;
		result->next = mergeLL(A->next,B);
	}
	return result;
}