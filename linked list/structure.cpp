#include <iostream>
#include <vector>
using namespace std;
class Node{
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
int main() {
  vector<int>arr={2,5,8,7};
  Node * x=new Node(10);
  cout<<x->data;  // o/p-> 10
}

