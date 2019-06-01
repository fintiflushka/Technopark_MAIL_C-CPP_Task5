#ifndef MULTISET_H  /* Если имя MULTISET_H ещё не определено */
#define MULTISET_H  /* Определить имя MULTISET_H */

#include <iostream>

using namespace std;


class Multiset
{
    struct Node
    {
        int item;
        int itemCount;
        Node* next;
        Node* previous;
    };
    
    int nodeCount;
    Node* head;

public:
    Multiset();
    // Конструктор. Создаёт пустое мультимножество.
    
    ~Multiset();
    // Деструктор.
    
    Multiset(const Multiset& other);
    // Конструктор копирования.
    
    Multiset& operator=(const Multiset& src);
    // Оператор присваивания.

    Multiset operator-(Multiset const& ms);
    // Разность множеств.

    Multiset operator+(Multiset const& ms);
    // Объединение множеств.

    Multiset operator*(Multiset const& ms);
    // Пересечение множеств.

    int operator[](int i) const;
    // Доступ по индексу к элементу множства. 
    
    bool empty() const;
    // Проверка на пустое множество. Возвращает true, если множество пустое,
    // иначе false.
    
    int size() const;
    // Число элементов множества.
    
    int uniqueSize() const;
    // Число уникальных элементов множества.
    
    bool insert(const int& value);
    // Добавление элемента в множество. Возвращает true, если элемент
    // был успешно добавлен.  Возращает false если элемент добавить не удалось.
    
    int count(const int& value) const;
    // Возвращает количество вхождений элемента в мультимножество.
    
    void swap(Multiset& other);
    // Меняет содержимое множеств друг с другом.

    friend ostream& operator<<(ostream& os, const Multiset& ms);
    // Выводит элементы множества.
};


#endif /* Если имя уже определено, повторно не определять */