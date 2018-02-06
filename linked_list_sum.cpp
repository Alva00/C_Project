#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

int main()
{
	
//  �������ͱ��� 
	/* ͷָ��, �ָ�룬 βָ�� */ 
	ListNode *l1, *p1, *s1;
	/* c��ʼ��ͷָ�� */
	l1 = new ListNode(0); 
	/* pΪ�ָ�� */ 
	p1 = l1;
	int m1;
	while(cin >> m1 && m1 != 0)
	{
		s1 = new ListNode(m1);
		s1->next = p1->next;
		p1->next = s1;
		p1 = s1;
	} 
	ListNode *l2, *p2, *s2;
	/* c��ʼ��ͷָ�� */
	l2 = new ListNode(0); 
	/* pΪ�ָ�� */ 
	p2 = l2;
	int m2;
	while(cin >> m2 && m2 != 0)
	{
		s2 = new ListNode(m2);
		s2->next = p2->next;
		p2->next = s2;
		p2 = s2;
	} 
	/* ��� */
	
    ListNode* res = new ListNode(0);
    ListNode* res_tmp = res;
    int carry = 0; //��λ
    while(l1 != NULL || l2 != NULL)
    {
        //���Ƿ�Ϊ���������ж�
        int tmp;
        if(l1 != NULL && l2 != NULL)
        {
            tmp = carry + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;

        }
        else if(l1 != NULL && l2 == NULL)
        {
            tmp = carry + l1->val;
            l1 = l1->next;
            
        }
        else if(l1 == NULL && l2 != NULL)
        {
            tmp = carry + l2->val;
            l2 = l2->next;
            
        }
        
        if(tmp >= 10)
        {
            carry = 1;
            tmp = tmp - 10;
        }
        else
        {
        	carry = 0;
		}
        // ����һ���ڵ�
        ListNode* next = new ListNode(0);
        next->val = tmp;
        next->next = res_tmp->next;
        res_tmp->next = next;
        res_tmp = next;  
    } 
    // ����ѭ����
    if(carry)
    {
        ListNode* next = new ListNode(0);
        next->val = 1;
        next->next = res_tmp->next;
        res_tmp->next = next;
        res_tmp = next;     
    }
    // ɾ��ͷ���ڵ�
    ListNode *node;
    node = res;
    res = res->next;
    free(node);
    /* ���� */
	while(res != NULL)
	{
		cout << res->val << " " ;
		res = res->next;	
	}
	return 0;
}
