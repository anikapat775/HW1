#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
 
ULListStr::ULListStr()
{
 head_ = NULL;
 tail_ = NULL;
 size_ = 0;
}
 
ULListStr::~ULListStr()
{
 clear();
}
 
bool ULListStr::empty() const
{
 return size_ == 0;
}
 
size_t ULListStr::size() const
{
 return size_;
}
 
// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
 if(tail_==NULL){
   tail_ = new Item();
   tail_->val[0]=val;
   tail_->last++;
   head_ = tail_;
 }
 else if(tail_->last == ARRSIZE){
   Item* newItem = new Item();
   newItem->val[0]= val;
   newItem->last++;
   newItem->prev = tail_;
   tail_->next = newItem;
   tail_ = newItem;
 }
 else{
   tail_->val[tail_->last] = val;
   tail_->last++;
 }
 size_++;
}
 /**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
 void ULListStr::pop_back(){
   if(size_==0){
     return;
   }
   else if(tail_->last==1){
     Item *temp = tail_->prev;
     if(temp!=NULL){
       temp->next = NULL;
     }
     delete tail_;
     tail_ = temp;
   }
   else{
     tail_->last--;
     tail_->val[tail_->last] = "";
   }
   size_--;
  
 }
  /**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise,
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
 void ULListStr::push_front(const std::string& val){
   if(tail_==NULL){
   tail_ = new Item();
   tail_->val[0]=val;
   tail_->last++;
   head_ = tail_;
 }
 else if(head_->first == 0){
   Item* newItem = new Item();
   newItem->val[ARRSIZE-1]= val;
   newItem->last = ARRSIZE;
   newItem->first = ARRSIZE - 1;
   newItem->next = head_;
   head_->prev = newItem;
   head_ = newItem;
 }
 else{
   head_->first--;
   head_->val[head_->first] = val;
 }
 size_++;
 }
 /**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
 void ULListStr::pop_front(){
   if(size_==0){
     return;
   }
   else if(head_->first== ARRSIZE-1){
     Item *temp = head_->next;
     if(temp!=NULL){
       temp->prev = NULL;
     }
     delete head_;
     head_ = temp;
   }
   else{
     head_->val[head_->first] = "";
     head_->first++;
   }
   size_--;
 }
  /**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
 std::string const & ULListStr::back() const
 {
   if(size_==0){
     return NULL;
   }
   return tail_->val[tail_->last-1];
 }
 /**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
 std::string const & ULListStr::front() const
 {
   if(size_==0){
     return NULL;
   }
   return head_->val[head_->first];
 }
 
void ULListStr::set(size_t loc, const std::string& val)
{
 std::string* ptr = getValAtLoc(loc);
 if(ptr == NULL){
   throw std::invalid_argument("Bad location");
 }
 *ptr = val;
}
 
std::string& ULListStr::get(size_t loc)
{
 std::string* ptr = getValAtLoc(loc);
 if(ptr == NULL){
   throw std::invalid_argument("Bad location");
 }
 return *ptr;
}
 
std::string const & ULListStr::get(size_t loc) const
{
 std::string* ptr = getValAtLoc(loc);
 if(ptr == NULL){
   throw std::invalid_argument("Bad location");
 }
 return *ptr;
}
 
void ULListStr::clear()
{
 while(head_ != NULL){
   Item *temp = head_->next;
   delete head_;
   head_ = temp;
 }
 tail_ = NULL;
 size_ = 0;
}
/**
  * Returns a pointer to the item at index, loc,
  *  if loc is valid and NULL otherwise
  *   - MUST RUN in O(n)
  */
 std::string* ULListStr::getValAtLoc(size_t loc) const
 {
   if(loc<0 || loc>=size_){
     return NULL;
   }
   Item* temp = head_;
   int index = head_->first;
   for(unsigned int i=0; i<loc; i++){
     if(index == ARRSIZE-1){
       temp = temp->next;
       index = 0;
     }
     else{
       index++;
     }
   }
   return &(temp->val[index]);
 }
