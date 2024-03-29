#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>

#include <initializer_list>

/*
template <typename T>
class List;
 */

template <typename T>
struct ListNode {
  T         value = T();
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
  ListNode(){}
  ListNode(T input):value(input){}
  ListNode(T input, ListNode* parent, ListNode* child): value(input), prev(parent), next(child){}
};

template <typename T>
struct ListIterator {
  using Self              = ListIterator<T>;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;
  using difference_type   = ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;

  ListNode<value_type>* itr;

  ListIterator(): itr(nullptr) {}
  ListIterator(ListNode<value_type>* ptr): itr(ptr){}

  /* returns the reference to the iterator object */ 
  reference  operator*()  const {
    assert(itr != nullptr);
    return itr->value;
  } 

  /* returns the pointer of iteractor object */
  pointer operator->() const {
  	  	assert(itr != nullptr);
        return pointer(itr);
  }

  /* increments interator pre usage */
  ListIterator<T>& operator++() {
  	assert(itr != nullptr);
    itr = itr->next;
    return *this;
  } //PREINCREMENT

  /* increments interator post usage */
  ListIterator<T> operator++(int i) {
  	assert(itr != nullptr);
    ListIterator tmp(*this);
    itr = itr->next;
    return tmp;
  } //POSTINCREMENT (signature distinguishes)

  /* tests equality to ListIterator x (value comparison) */
  bool operator==(ListIterator<T> const& x) const {
  	return itr == x.itr;
  }

  /* tests inequality to ListIterator x (value comparison) */
  bool operator!=(ListIterator<T> const& x) const {
  	return itr != x.itr;
  }

  /* returns the next node or nullptr if it is the back*/
  ListIterator<T> next() const {
    if (nullptr != node) {
      return ListIterator{node->next};
    } else {
      return ListIterator{nullptr};
    }
  }
  ListNode <T>* node = nullptr;
};



template <typename T>
class List {
  public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    // not implemented yet
    // do not forget about the initialiser list !
  	/* default Constructor */
    List():first_(nullptr) {}

    /* Constructor initialiser list*/
    List(ListNode<T>* first): first_(first), last_(first){}

    /* Copy-Konstruktor using Deep-Copy semantics */
    List(List<value_type> const&  rhs){
      first_ = new ListNode<value_type>(rhs.first_->value);
      ListNode<value_type>* tooAdd = new ListNode<value_type>();
      tooAdd = rhs.first_;
      while (tooAdd->next != NULL) {
        tooAdd = tooAdd->next;
        push_back(tooAdd->value);
      }
    }

  	/* Move-Konstruktor */
    reference operator=(T x){ 
      x.swap(*this);
      return *this; 
    }
    void swap(reference);
    friend void swap(reference lhs, reference rhs){ 
      lhs.swap(rhs); 
    }   
    List(List<value_type>&& rhs):first_(rhs.first_), last_(rhs.last_) { 
      rhs.first_= nullptr;
      rhs.last_ = nullptr;
    }


    //TODO: Initializer-List Konstruktor (4.14)
  	/* Initializer-List Konstruktor */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* Assignment operator */
    //TODO: Assignment operator (Aufgabe 4.12)

  	/* Test equality to to List (Value comparison) */
    bool operator==(List<value_type> const& rhs){
      ListNode<value_type>* mainListNode = new ListNode<value_type>();
      ListNode<value_type>* rhsListNode = new ListNode<value_type>();
      mainListNode = first_;
      rhsListNode = rhs.first_; 
      while(mainListNode->next != NULL) {
        if(mainListNode != NULL && rhsListNode != NULL && mainListNode->value == rhsListNode->value){
          mainListNode = mainListNode->next;
          rhsListNode = rhsListNode->next;
        }
        else{
          return false;
        }        
      }
      return true;
    }

  	/* Test inequality to to List (Value comparison) */
    bool operator!=(List<value_type> const& rhs){
      ListNode<value_type>* mainListNode = new ListNode<value_type>();
      ListNode<value_type>* rhsListNode = new ListNode<value_type>();
      mainListNode = first_;
      rhsListNode = rhs.first_; 
      while(mainListNode->next != NULL) {
        if(mainListNode != NULL && rhsListNode != NULL && mainListNode->value != rhsListNode->value){
          return true;          
        }
        else{
          mainListNode = mainListNode->next;
          rhsListNode = rhsListNode->next;
        } 
      }
      return false;   
      
    }

  	/* Destructor */
    ~List() {
  		clear();
    }

  	/* get first element of List */
    ListIterator<T> begin() {
      if(first_ != nullptr){
        return iterator(first_);
      }
      else{
        return nullptr;
      }
    	
    }

  	/* get last element of List */
    ListIterator<T> end() {
      if(last_ != nullptr){
        return iterator(first_);
      }
      else{
        return nullptr;
      }
    }

    /* remove all elements from list, clear storage */
    void clear() {
  		while(first_ != nullptr){
        pop_back();
      }
    }

    /* insert at position i */
    //TODO: member function insert
    ListIterator<value_type> insert(ListNode<value_type> const& tooInsert, ListIterator<value_type> const& position){
      position.itr->prev->next = tooInsert.operator*();
      position.itr->prev = tooInsert.operator*();
      tooInsert->prev = position.itr->prev;
      tooInsert->next = position.itr.operator*();
    }

  	/* reverse order of List */
    void reverse(){
      ListNode<value_type> *temp = nullptr;  
      ListNode<value_type> *current = first_;        
      while (current != nullptr){          
          temp = current->prev;  
          current->prev = current->next;  
          current->next = temp;              
          current = current->prev;  
      }  
      if(temp != nullptr ){
        first_ = temp->prev;  
      }
    }

    /* put element at first position, edit possible previous first */
    void push_front(value_type const& element) {
      ListNode<value_type>* new_node = new ListNode<value_type>(element); 
      new_node->next = first_; 
      new_node->prev = nullptr;   
      if (first_ != nullptr) {
        first_->prev = new_node; 
      }
      first_ = new_node;
      updateLast();
      }

    /* add element to end of List, change previous last element */
    void push_back(T const& element) {
  		ListNode<value_type>* new_node = new ListNode<value_type>(element); 
      ListNode<value_type>* last = first_; 
      new_node->next = nullptr; //will be new end, is default... but sanity
      if (first_ == nullptr) { //if the List is empty
        new_node->prev = nullptr;  //set prev and next null
        first_ = new_node; //and make it Head
        last_ = new_node;
        return; //leave, nothing else to do
      } 
      while (last->next != nullptr) {//else go to the last_ node
        last = last->next; 
      } 
      last->next = new_node;
      new_node->prev = last;
      last_ = new_node; //update variable

    }

    /* remove first element, edit second element */
    void pop_front() {
    	assert(!empty());
  		if(first_->next == nullptr){
        first_ = nullptr;
        last_ = nullptr;
        return;
      }
      else{
        first_->next->prev = nullptr;
        first_ = first_->next;
      }
    }

    /* remove last element, edit new last element */
    void pop_back() {
    	assert(!empty());
      if(last_->prev == nullptr){
        first_ = nullptr;
        last_ = nullptr;
        return;
      }
      else{
        last_->prev->next = nullptr;
        last_ = last_->prev;
      }
		  
    }

  	/* get first element */
    T& front() {
    	assert(!empty());    	
    	return reference(first_->value);
    }

  	/* get last element */
    T& back() {
    	assert(!empty());    	
    	return reference(last_->value);
    }

    /* utility to make sure pushFront updates all variales*/
    void updateLast(){
      ListNode<value_type>* last = new ListNode<value_type>();
      last = first_; 
      while (last->next != NULL) {
        last = last->next; 
      }
      last_ = last;
    }

  	/* return if List is empty */
    bool empty() const {
      return (first_ == nullptr);
    };

    /* returns number of elements in List */
     std::size_t size(){
       ListNode<value_type>* node = first_;
      size_ = 0;
      while (node != nullptr)  
      {   
        size_ = size_+1;
        node = node->next;  
      }
      return size_;
    }

    /* utility to prove existence */
    bool exists() const{
      return true;
    }

    /* debug utility */
    void printList(){
      ListNode<value_type>* node = first_;
      while (node != nullptr)  
      {   
        cout<<" "<<node->value<<"\n";  
        node = node->next;  
      } 
      cout<<"\n";
    }  


  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

/* reverse order */
//TODO: Freie Funktion reverse

/* ... */
//TODO: Freie Funktion operator+ (4.14)

#endif // # define BUW_LIST_HPP
