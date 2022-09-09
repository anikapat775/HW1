/* Write your test code for the ULListStr in this file */
 
#include <iostream>
#include "ulliststr.h"
using namespace std;
 
int main(int argc, char* argv[])
{
 ULListStr* list = new ULListStr();
 cout << "pushing back 'A'" << endl;
 list->push_back("A");
 cout << "size: "<< list->size() << endl;
 cout << "list at index 0: " << list->get(0) << endl;
 cout << "pushing back 11 items "<< endl;
 for(int i=0; i<ARRSIZE+1; i++){
   list->push_back(to_string(i));
 }
 cout << "size: "<< list->size() << endl;
 cout << "list: ";
 for(unsigned int i=0; i<list->size(); i++){
   cout << list->get(i) << " ";
 }
 cout << endl;
 
 cout << "popping back " << endl;
 list->pop_back();
 cout << "size: "<< list->size() << endl;
 cout << "popping back 12 items" << endl;
 for(int i=0; i<ARRSIZE+2; i++){
   list->pop_back();
   if(list->size()>0){
     cout << "front: " << list->front()<< endl;
     cout << "back: " << list->back()<< endl;
   }
   cout << "list: ";
   for(unsigned int i=0; i<list->size(); i++){
   cout << list->get(i) << " ";
   }
   cout << endl;
 }
 cout << "size: " << list->size() << endl;
 
 cout << "pushing front 'A'" << endl;
 list->push_front("A");
 cout << "size: "<< list->size() << endl;
 cout << "list at index 0: " << list->get(0) << endl;
 cout << "pushing front 11 items "<< endl;
 for(int i=0; i<ARRSIZE+1; i++){
   list->push_front(to_string(i));
 }
 cout << "size: "<< list->size() << endl;
 cout << "list: ";
 for(unsigned int i=0; i<list->size(); i++){
   cout << list->get(i) << " ";
 }
 cout << endl;
 
 cout << "popping front " << endl;
 list->pop_front();
 cout << "size: "<< list->size() << endl;
 cout << "popping front 12 items" << endl;
 for(int i=0; i<ARRSIZE+2; i++){
   list->pop_front();
   if(list->size()>0){
     cout << "front: " << list->front()<< endl;
     cout << "back: " << list->back()<< endl;
   }
   cout << "list: ";
   for(unsigned int i=0; i<list->size(); i++){
   cout << list->get(i) << " ";
   }
   cout << endl;
 }
 cout << "size: " << list->size() << endl;
 delete list;
 return 0;
}
