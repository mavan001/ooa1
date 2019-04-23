#ifndef _PQUEUE_H
#define _PQUEUE_H

using namespace std;

class MyException {
};

template <typename T>
struct pqentry{
    float priority;
    T value;
    pqentry(float getPriority, T getValue);
}

class PriorityQueue {
private:
    int _size;
    int _last;
    pqentry **_entrys; //Array aus pqentry<T> Pointern
    bool isFull(void);
    bool isAlmostFull(void);
    void changeArray(int Richtung);
public:
    PriorityQueue(int size = 100);
    ~PriorityQueue(void);
    void insert(string value, float priority);
    string extractMin(void);
    void decreaseKey(string value, float priority);
    void remove(string value);
    bool isEmpty(void);
    void print();
};

#endif
