// Author Sean Davis

#include <iostream>
#include "CPUTimer.h"

using namespace std;

class ListNode
{
public:
  int data;
  ListNode* next;
  ListNode(int d, ListNode* n) : data(d), next(n){}
};

int main(int argc, char** argv)
{
  CPUTimer ct;
  int i,j, ar[100], *iptr;
  ListNode *ptr = new ListNode(0, NULL);
  ListNode *head = ptr;
  
  for(i = 0; i < 100; i++)
  {
    ar[i] = i;
    ptr = ptr->next = new ListNode(i, NULL);
  }
  
  ptr->next = head; // makes list circular
  ct.reset();
  
  for(i = 0; i < 100000; i++)
    for(j = 0; j < 100; j++)
      ptr = ptr->next;
   
  cout << "Linked list CPU time: " << ct.cur_CPUTime() << endl;
  ct.reset();
  
  for(i = 0; i < 100000; i++)
    for(j = 0; j < 100; j++)
      iptr = &ar[j];
  

  cout << "Array CPU time: " << ct.cur_CPUTime() << endl; 
  cout << *iptr << ' ' << ptr->data << endl;
  return 0;
} // main()

