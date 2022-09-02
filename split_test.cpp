#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main()
{
  Node* odds = NULL;
  Node* evens = NULL;
  Node* in = new Node(2, new Node(3,new Node(6, new Node(7, NULL))));
  split(in, odds, evens);
  Node* temp = odds;
  while(temp != NULL){
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
  temp = evens;
   while(temp != NULL){
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
  while(in != NULL){
    cout << in->value << " ";
    in = in->next;
  }
  cout << endl;
  
  temp = evens;
  //cout << "HERE";
  while(temp !=NULL){
    //cout << temp->value; 
    Node* next = temp->next;
    delete temp;
    temp = next; 
  }
  evens = NULL;
  temp = odds;
  while(temp !=NULL){
    //cout << temp->value; 
    Node* next = temp->next;
    delete temp;
    temp = next; 
  }
  odds = NULL;
}