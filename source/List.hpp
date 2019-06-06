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


  /* DESCRIPTION  operator*() */
  T&  operator*()  const {
  	//not implemented yet
  	return {};
  } 

  /* DESCRIPTION  operator->() */
  T* operator->() const {
  	//not implemented yet
  	return nullptr;
  }

  /* increments interator by 1 */
  ListIterator<T>& operator++() {
  	//not implemented yet
  	return {};
  } //PREINCREMENT

  /* increments interator by argument */
  ListIterator<T> operator++(int) {
  	//not implemented yet
  	return {};
  } //POSTINCREMENT (signature distinguishes)

  /* tests equality to ListIterator x (value comparison) */
  bool operator==(ListIterator<T> const& x) const {
  	//not implemented yet
  }

  /* tests inequality to ListIterator x (value comparison) */
  bool operator!=(ListIterator<T> const& x) const {
  	//not implemented yet
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
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)

  	/* Move-Konstruktor */
    //TODO: Move-Konstruktor (Aufgabe 4.13)

    //TODO: Initializer-List Konstruktor (4.14)
  	/* Initializer-List Konstruktor */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* Assignment operator */
    //TODO: Assignment operator (Aufgabe 4.12)

  	/* Test equality to to List (Value comparison) */
    //TODO: operator== (Aufgabe 4.7)

  	/* Test inequality to to List (Value comparison) */
    //TODO: operator!= (Aufgabe 4.7)

  	/* ... */
    ~List() {
  		//TO IMPLEMENT PROPERLY
    }

  	/* get first element of List */
    ListIterator<T> begin() {
  		////not implemented yet
    	return ListIterator<T>{};
    }

  	/* get last element of List */
    ListIterator<T> end() {
  		////not implemented yet
    	return ListIterator<T>{};
    }

    /* remove all elements from list, clear storage */
    void clear() {
  		////not implemented yet
    }

    /* insert at position i */
    //TODO: member function insert
  	/* reverse order of List */
    //TODO: member function reverse

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
      new_node->next = nullptr; //will be new end
      if (first_ == nullptr) { //if the List is empty
        new_node->prev = nullptr;  //set prev and next null
        first_ = new_node; //and make it Head
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
  		//not implemented yet
    }

    /* remove last element, edit new last element */
    void pop_back() {
    	assert(!empty());
		//not implemented yet
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
    std::size_t size() const{
      return size_;
    };

    /* utility to prove existence */
    bool exists() const{
      return true;
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
