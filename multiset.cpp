#include "multiset.h"
#include <iostream>
#include <exception>
using namespace std;


Multiset::Multiset()
{
    head = nullptr;
    nodeCount = 0;
}


Multiset::~Multiset()
{
    Node *p = head;
    //p 
    
    while (p != nullptr)
    {
        Node *n = p->next;
        delete p;
        p = n;
    }
    nodeCount = 0;
}


Multiset::Multiset(const Multiset& other)
{
    this->head = nullptr;
    
    nodeCount = other.nodeCount;
    Multiset* copyMulti = new Multiset;
    
    for (int i = 0; i < other.uniqueSize(); i++)
    {
        int x = other[i];
        int n = other.count(x);
        
        for (int i = 0; i < n; i++)
        {
            copyMulti->insert(x);
        }
    }
    
    copyMulti->swap(*this);
    delete copyMulti;
}


Multiset& Multiset::operator=(const Multiset& src)
{
    if (this != &src){
        Multiset temp(src);
        swap(temp);
    }
    
    return (*this);
}


Multiset Multiset::operator-(Multiset const& ms) 
{
    Multiset difference;
    Multiset it = *this;

    for (int i = 0; i < it.uniqueSize(); i++) 
    {
        int new_item_count = it.count(it[i]) - ms.count(it[i]);
        for (int j = new_item_count; j > 0; j--) 
        {
            difference.insert(it[i]);
        }
    }

    return difference;
}


Multiset Multiset::operator+(Multiset const& ms) 
{
    Multiset sum(*this);

    for (int i = 0; i < ms.uniqueSize(); i++) 
    {
        int new_item_count = abs(ms.count(ms[i]) - sum.count(ms[i]));
        for (int j = new_item_count; j > 0; j--) 
        {
            sum.insert(ms[i]);
        }
    }

    return sum;
}


Multiset Multiset::operator*(Multiset const& ms) 
{
    Multiset cross;
    Multiset it = *this;

    for (int i = 0; i < it.uniqueSize(); i++) 
    {
        int new_item_count = 0;
        int ms_count = ms.count(it[i]);
        int it_count = it.count(it[i]); 
        ms_count <= it_count ? new_item_count = ms_count : new_item_count = it_count; 

        for (int j = new_item_count; j > 0; j--) 
        {
            cross.insert(it[i]);
        }
    }

    return cross;
}


int Multiset::operator[](int i) const
{
    Node *p;
    p = head;

    if (i >= 0 && i < uniqueSize())
    {
        for (int j = 0; j < i; j++){
            p = p->next;
        }
        
        return p->item;
    }

    return -1;
}


bool Multiset::empty() const
{
    if (head == nullptr){
        return true;
    }
    return false;
}


int Multiset::size() const
{
    Node *p;
    p = head;   // указатель на первый элемент
    int counter = 0; 
    
    while (p != nullptr)
    {
        counter += p->itemCount;  
        p = p->next;
    }
    
    return counter;
}


int Multiset::uniqueSize() const
{
    Node *p;
    p = head;
    int counter = 0;        
    
    while (p != nullptr)
    {
        if (p->itemCount > 0){
            counter++;       
        }
        p = p->next;
    }
    return counter;
}


bool Multiset::insert(const int& value)
{
    if (head == nullptr)
    {
        Node* hi;
        try 
        {
            hi = new Node;
        }
        catch (exception& e)
        {
            return false;
        }
        hi->item = value;
        hi->itemCount = 1;
        hi->next = nullptr;
        hi->previous = nullptr;
        head = hi;
        nodeCount++;
        return true;
    }
    // Выделение памяти под первый элемент множества.
    
    Node *p;
    p = head;
    
    while (p != nullptr)
    {
        if (p->item == value){
            p->itemCount += 1;
            return true;
        }
        p = p->next;
    }
    // Увеличение количества вхождений элемента в мультимножество, если элемент уже содержался в нём ранее.

    try 
    {
        p = new Node;
    }
    catch (exception& e)
    {
        return false;
    }

    nodeCount++;
    // Выделение памяти под новых элемент и увеличение счётчика количества элементов.
    
    p->item = value;
    p->itemCount = 1;
    // Присваивание элементу значения и определения счётчика вхождений элемента равному еденице.
    
    p->next = head;
    p->previous = nullptr;
    head->previous = p;
    
    head = p;
    // Указатель возвращается на следующий элемент
    
    return true;
}

int Multiset::count(const int& value) const
{
    Node *p;
    p = head;
    int counter = 0;
    
    while (p != nullptr)
    {
        if (p->item == value){
            counter = p->itemCount;
        }
        p = p->next;
    }
    
    return counter;
}

void Multiset::swap(Multiset& other)
{
    Node* p3 = head;
    head = other.head;    
    other.head = p3;
    
    int temp = nodeCount;
    nodeCount = other.nodeCount;
    other.nodeCount = temp;
}


ostream& operator<<(ostream& os, const Multiset& ms)
{
    os << "{ ";
    for (int i = 0; i < ms.uniqueSize(); i ++)
    {        
        for (int j = 1; j <= ms.count(ms[i]); j++) 
        {
            os << ms[i] << ' ';    
        }
    }
    os << " }";

    return os;
}
