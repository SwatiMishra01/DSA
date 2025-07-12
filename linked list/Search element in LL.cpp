#include <iostream>
#include <vector>
using namespace std;
struct Node{
public:
     int data; // Har node mein ek data value hoti hai
    Node*next;  // Aur ek pointer jo next node ko point karta hai

//  Constructor #1: Jab aap data aur next dono specify karte ho
public:
   Node(int data1, Node*next1){
     data=data1;
     next=next1;
   }

//  Constructor #2: Jab sirf data dete ho aur next nullptr hota hai
public:
   Node(int data1){
     data=data1;
     next=nullptr;
   }
};
// Function to convert an array to a linked list
Node*convertarray2linkedlist(vector<int>arr){
  Node*head=new Node(arr[0]);
  Node*temp=head;
  for(int i=1;i<arr.size();i++){
    Node*newNode=new Node(arr[i]);
    temp->next=newNode;
    temp=temp->next;
  }
  return head;
}

// Function to print the length of linked list
int length(Node*head){
  int len=0;
  Node*temp=head;
  while(temp!=nullptr){
    len++;
    temp=temp->next;
  }
  return len;
}

// Function to search element in the linked list
int search(Node*head, int val){
  Node*temp=head;
  while(temp){
    if(temp->data==val)
      return 1;
    temp=temp->next;
  }
  return 0;
}
int main() {
  vector<int>arr={2,5,8,7};
 Node*head=convertarray2linkedlist(arr);
cout<<search(head,7);  //output-> 1
    
}
