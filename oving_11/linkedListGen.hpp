#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <ostream>
#include <cassert>

// test code 
void testLinkedList();


// namespace LinkedList {
template<typename T>
class Node {
private:
    T value;    // The data held by the LinkedList
    std::unique_ptr<Node> next; // unique_ptr to the next node
    Node* prev;                 // raw (non-owning) ptr to the previous node
public:
    Node() : value(), next(nullptr), prev(nullptr) {}
    // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
    Node(const std::string& value, std::unique_ptr<Node> next, Node* prev)
        : value(value)
        , next(std::move(next))
        , prev(prev)
    {}
    // We can use the default constructor, since unique_ptr takes care of deleting memory
    ~Node() = default;
    // return the value of the node
    T getValue() const { return value; }

    // return a raw (non-owning) pointer to the next node
    Node* getNext() const { return next.get(); }
    // return a raw (non-owning) pointer to the previous node
    Node* getPrev() const { return prev; }

    // write the value of the node to the ostream
    friend std::ostream & operator<<(std::ostream & os, const Node & node);

    friend class LinkedList;
};

template<typename T>
class LinkedList {
private:
    // ptr to the first node
    std::unique_ptr<Node<T>> head;
    // a raw pointer to the last node, the last node is always a dummy node
    // this is declared as a const ptr to a Node, so that tail never can
    // point anywhere else
    Node<T>* const tail;
public:
    //create the dummy node, and make tail point to it
    LinkedList()
        : head(std::make_unique<Node<T>>())
        , tail(head.get())
    {}
    ~LinkedList() = default;

    //if next is a nullptr (i.e. head is the dummy node), the list is emtpy
    bool isEmpty() const { return head->next == nullptr; }

    //return a pointer to first element
    Node<T>* begin() const { return head.get(); }
    //return a pointer to beyond-end element
    Node<T>* end() const { return tail; }

    // The insert function takes a pointer to node (pos) and a string (value). It creates a new
    // node which contains value. The new node is inserted into the LinkedList BEFORE the
    // node pointed to by pos. Returns a pointer to the new Node
    Node<T>* insert(Node<T> *pos, const std::string& value){
        
        assert(pos != nullptr);

        if (pos == begin()){
            head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
            pos->prev = begin();
        }
        else {
            pos->prev->next = std::make_unique<Node<T>>(value, std::move(pos->prev->next), pos->prev);
            pos->prev = pos->prev->getNext();
        }
        return pos->prev;

    }

    // The find function traverses the linked list and returns a pointer to the first node
    // that contains the value given.
    // If the value isn't in the list, find returns a pointer to the dummy node at the end
    // of the list.
    Node<T>* find(const std::string& value){
        for (auto it = begin(); it!= end(); it = it->getNext()){
            if (it->getValue() == value){
                return it;
            }
        }
        return end();
    }

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node<T>* remove(Node<T>* pos){
        // DEBUG("[prev<-pos->next] " << pos->prev << " <- " << pos << " -> " << pos->getNext());
        
        assert(pos != nullptr);
        assert(pos != end());

        if (pos == begin()){
            head = std::move(pos->next);
            head->prev = nullptr;
            return begin();
        } else { 
            auto nextNode = pos->getNext();
            // correct (pos +1)->prev = (pos-1), skipping pos
            nextNode->prev = pos->prev;
            // moving (pos-1)->next = (pos+1), skipping pos
            pos->prev->next = std::move(pos->next);
            // think pos deletes itself when it gets overwriten. 
            
            return nextNode;
        }
    
    }

    // The remove function takes a string and removes the first node which contains the value.
    void remove(const std::string& value){
        auto removeNode = find(value);
        if (removeNode != end()){
            remove(removeNode);
        }
    }

    // write a string representation of the list to the ostream
    friend std::ostream & operator<<(std::ostream & os, const LinkedList& list);
};
// }// namespace LinkedList


// template<typename T>
// inline std::ostream& operator<<(std::ostream &os, const Node<T> &node){
//     os << node.value;
//     return os;
// }

// template<typename T>
// inline std::ostream & operator<<(std::ostream & os, const LinkedList<T>& list){

//     Node *iterator = list.begin();
//     os << "[";
//     while (iterator != list.end()){
//         os << iterator->getValue() << ", ";
//         iterator = iterator->getNext();
//     }
//     os << "]";
//     return os;
// }