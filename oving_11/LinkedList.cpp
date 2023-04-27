#include "LinkedList.h"
#include "logger.hpp"

// using namespace LinkedList;

std::ostream& operator<<(std::ostream &os, const LinkedList::Node &node){
    os << node.getValue();
    return os;
}

// std::ostream & operator<<(std::ostream & os, const LinkedList::LinkedList& list){

//     LinkedList::Node *iterator = list.begin();

//     while (iterator != list.end()){
//         os << iterator->getValue() << ", ";
//         iterator = iterator->getNext();
//     }
//     return os;
// }


LinkedList::Node* LinkedList::LinkedList::insert(Node *pos, const std::string& value){

    DEBUG("[INSERT()] pos: " << pos << " pos->next: " << pos->next.get() << " pos->prev: " << pos->prev);
    
    // (pos - 1)->next moved to newNode
    // newNode->prev = (copy) pos->prev
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value, 
            std::move(pos->prev->next), 
            pos->prev);
    
    DEBUG("newNode created: " << newNode.get() << 
    " newNode->next: " << newNode->next.get() << 
    " newNode->prev: " << newNode->prev
    );


    // pos->prev point to newNode
    pos->prev = newNode.get();

    // move newNode to (pos - 1)->next
    pos->prev->next = std::move(newNode);

    return newNode.get();
} 


