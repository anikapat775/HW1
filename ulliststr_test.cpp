/* Write your test code for the ULListStr in this file */
 
#include <iostream>
#include "ulliststr.h"
using namespace std;
 
int main(int argc, char* argv[])
{
 ULListStr* list = new ULListStr();
 //testing pushback 
 cout << "pushing back 'A'" << endl;
 list->push_back("A");
 cout << "size: "<< list->size() << endl;
 cout << "list at index 0: " << list->get(0) << endl;
 //pushback multiple times in a row
 cout << "pushing back 11 items "<< endl;
 for(int i=0; i<ARRSIZE+1; i++){
   list->push_back(to_string(i));
 }
 //display current list info
 cout << "size: "<< list->size() << endl;
 cout << "list: ";
 for(unsigned int i=0; i<list->size(); i++){
   cout << list->get(i) << " ";
 }
 cout << endl;
 //test popback
 cout << "popping back " << endl;
 list->pop_back();
 cout << "size: "<< list->size() << endl;
 //popback multiple times
 cout << "popping back 12 items" << endl;
 for(int i=0; i<ARRSIZE+2; i++){
   list->pop_back();
	 //print list info on each iteration
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
 //test pushfront
 cout << "pushing front 'A'" << endl;
 list->push_front("A");
 cout << "size: "<< list->size() << endl;
 cout << "list at index 0: " << list->get(0) << endl;
 //test pushfront multiple times
 cout << "pushing front 11 items "<< endl;
 for(int i=0; i<ARRSIZE+1; i++){
   list->push_front(to_string(i));
 }
//print current list info
 cout << "size: "<< list->size() << endl;
 cout << "list: ";
 for(unsigned int i=0; i<list->size(); i++){
   cout << list->get(i) << " ";
 }
 cout << endl;
 //test popfront
 cout << "popping front " << endl;
 list->pop_front();
 cout << "size: "<< list->size() << endl;
 //test popfront multiple times
 cout << "popping front 12 items" << endl;
 for(int i=0; i<ARRSIZE+2; i++){
   list->pop_front();
	 //print list info at each iteration
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
 //delete allocated memomory
 delete list;
 return 0;
}
