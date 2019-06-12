#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>
#include <iterator>
#include <iostream>
#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode{
    T value = T ();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <typename T>
struct ListIterator {
    using Self = ListIterator<T>;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

    //returned den value des Elements, auf das der iterator zeigt
    T& operator*() const{
      return node->value;
    }
    T* operator->() const{
      return &(node->value);
    }

    //returned den nächsten knoten in der Liste, ist der nächste nullptr wird der aktuelle returned
    ListIterator<T> operator++(){
      if(node->next != nullptr){
        node = node->next;
        return *this;
      }
      else{
        return *this;
      }
    }

    //iterator geth eins weiter, vorher wird die node returned
    ListIterator<T> operator++(int){ 
      if(node->next != nullptr){
        node = node->next;
        return *this;
      }
      else{
        return *this;
      }
    }

    //returned true wenn zwei zeiger auf den selben wert zeigen 
    bool operator==(ListIterator<T> const& x) const{
      if(node == x.node){
        return true;
      }
      else{
        return false;
      }
    }

    //returned false wenn zwei zeiger auf den selben wert zeigen 
    bool operator!=(ListIterator<T> const& x) const{
      if(node != x.node){
        return true;
      }
      else{
        return false;
      }
    }
    
    //returned die node, nach der node des aktuellen iteratorstandes
    ListIterator<T> next() const{
        if(nullptr != node){
            return ListIterator{node->next};
        }
        else{
            return ListIterator{nullptr};
        }
    }
    ListNode<T>* node = nullptr;
};

template <typename T>
class List{
    public:
     using value_type = T;
     using pointer = T*;
     using const_pointer = T const*;
     using reference = T&;
     using const_reference = T const&;
     using iterator = ListIterator<T>;

    
  	//leere liste Konstruktor
    List():size_{0}, first_{nullptr}, last_{nullptr} {}


    //deep copy 4.8
    List(List<T> const& list2): 
        last_{nullptr}, 
        first_{nullptr},
        size_{0}{
            ListNode<T>* ptr1 = list2.first_; 
            while(ptr1 != nullptr){ 
                push_back(ptr1->value); 
                ptr1 = ptr1->next; 
            }
        }   
    

  	
    //TODO: Move-Konstruktor (Aufgabe 4.13)
    List(List<T>&& list2):
        first_{list2.first_},
        last_{list2.last_},
        size_{list2.size_}{
            list2.size_ = 0;
            list2.first_ = nullptr;
            list2.last_ = nullptr;
        }

    //TODO: Initializer-List Konstruktor (4.14)
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	//returned true, wenn zwei Listen die selben nodes haben
    bool operator ==(List const& list2) const
    {
      if(size_ != list2.size_)
      {
        return false;
      }
      else
      {
        ListIterator<T> itr;
        ListIterator<T> itr2;
        itr = begin();
        itr2 = list2.begin();

        for (int i = 0; i < size_; i++)
        {
          if(*itr != *itr2)
          {
            return false;
          }
        }
        return true;
      }
    }

  	//returned true, wenn zwei Listen unterschiedliche nodes haben
    bool operator !=(List const& list2) const
    {
       if(size_ == list2.size_)
      {
        return false;
      }
      else
      {
        ListIterator<T> itr;
        ListIterator<T> itr2;
        itr = begin();
        itr2 = list2.begin();

        for (int i = 0; i < size_; i++)
        {
          if(*itr == *itr2)
          {
            return false;
          }
        }
        return true;
      }
    }

  	//Destruktor
    ~List() {
  		clear();
    }

  	//returned einen Zeiger auf das erste Element der Liste
    ListIterator<T> begin() const{
  	  ListIterator<T> itr{first_};
      return itr;
    }

  	//returned einen Zeiger auf das letzte Element der Liste
    ListIterator<T> end() const{
      ListIterator<T> itr{last_};
      return itr;
    }

    //löscht alle Elemente aus der Liste bis size = 0 ist
    void clear() {
  		if(!empty())
      {
        while (size_ > 0)
        {
          pop_back();
        }      
      }
    }

    /* Fügt ein Element an einer bestimmten Position ein */
    //TODO: member function insert

  	/* Dreht den Inhalt der Liste um */
    //TODO: member function reverse
    

    //fügt das Element vorne an die Liste an
    void push_front(T const& element) {
  		if(!empty())
      {
        ListNode<T>* newNode = new ListNode<T>{element, nullptr, first_};
        first_->prev = newNode;
        first_ = newNode;
        size_++;
      }
      else
      {
        ListNode<T>* newNode = new ListNode<T>{element};
        first_ = newNode;
        last_ = newNode;
        size_++;
      }      
    }

    //fügt das Element hinten an die Liste an
    void push_back(T const& element) {	
    	if(!empty())
      {
        ListNode<T>* newNode = new ListNode<T>{element, last_, nullptr};
        last_ = newNode;
        size_++;
      }
      else
      {
        ListNode<T>* newNode = new ListNode<T>{element};

        first_ = newNode;
        last_ = newNode;
        size_++;
      }      
    }

    // löscht das erste Element
    void pop_front() {
    	assert(!empty());
      if(size_ == 1)
      {
        first_ == nullptr;
        last_ == nullptr;
        size_--;
      }
      else
      {
        first_ = first_->next;
        first_->prev = nullptr;
        size_--;
      }
    }
  
    //löscht das letzte Element
    void pop_back() {
    	assert(!empty());
      if(size_ == 1){
        first_ == nullptr;
        last_ == nullptr;
        size_--;
      }
      else
      {
        last_ = last_->prev;
        last_->next = nullptr;
        size_--;
      }
    }

  	//returned den Wert des ersten Elements
    T& front() {
    	assert(!empty());
  		return first_->value;
    }

  	//returned den Wert des letzten Elements
    T& back() {
    	assert(!empty());
      return last_->value;
    }

  	//prüft ob sich Elemente/Nodes in der Liste befinden
    bool empty() const {
      if(size_ == 0){
        return true;
      }
      else{
          return false;
          } 
    };

    //gibt die Anzahl der Elemente aus
    std::size_t size() const{
        return size_;
    };


  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

#endif