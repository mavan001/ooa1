#ifndef _PQUEUE_H
#define _PQUEUE_H

using namespace std;

class MyException {
};

typedef struct pqentry{
    float priority;
    string value;
    pqentry(float getPriority, string getValue);
}

class PriorityQueue {
private:
    int _size;
    int _last;
    pqentry **_entrys;
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
