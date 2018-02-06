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
	
//  链表创建和遍历 
	/* 头指针, 活动指针， 尾指针 */ 
	ListNode *l1, *p1, *s1;
	/* c初始化头指针 */
	l1 = new ListNode(0); 
	/* p为活动指针 */ 
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
	/* c初始化头指针 */
	l2 = new ListNode(0); 
	/* p为活动指针 */ 
	p2 = l2;
	int m2;
	while(cin >> m2 && m2 != 0)
	{
		s2 = new ListNode(m2);
		s2->next = p2->next;
		p2->next = s2;
		p2 = s2;
	} 
	/* 相加 */
	
    ListNode* res = new ListNode(0);
    ListNode* res_tmp = res;
    int carry = 0; //进位
    while(l1 != NULL || l2 != NULL)
    {
        //对是否为空条件的判断
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
        // 创建一个节点
        ListNode* next = new ListNode(0);
        next->val = tmp;
        next->next = res_tmp->next;
        res_tmp->next = next;
        res_tmp = next;  
    } 
    // 跳出循环后
    if(carry)
    {
        ListNode* next = new ListNode(0);
        next->val = 1;
        next->next = res_tmp->next;
        res_tmp->next = next;
        res_tmp = next;     
    }
    // 删除头部节点
    ListNode *node;
    node = res;
    res = res->next;
    free(node);
    /* 遍历 */
	while(res != NULL)
	{
		cout << res->val << " " ;
		res = res->next;	
	}
	return 0;
}
