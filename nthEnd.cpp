#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x){val = x; next = NULL;};	
};

ListNode* nthEnd(ListNode *A, int B)
{
	ListNode *ptr1 = A, *ptr2 = A, *temp = A;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if(count < B)
	{
		temp = A;
		A = A->next;
		delete temp;
		return A;
	}
	for (int i = 0; i < B; ++i)
		ptr1 = ptr1->next;
	if(ptr1 == NULL)
	{
		ListNode *temp = A;
		A = A->next;
		delete temp;
		return A;		
	}
	while(ptr1->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr2->next->next;
	return A;
}
int main()
{
	return 0;
}