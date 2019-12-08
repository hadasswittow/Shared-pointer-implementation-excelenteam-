//
// Created by hadasswittow on 12/8/19.
//

#ifndef SHAREDPOINTER_COUNTER_H
#define SHAREDPOINTER_COUNTER_H


class Counter {
public:
    Counter(): m_counter(0){};

    Counter& operator=(unsigned int num){ m_counter = num;}
    //Counter(const Counter&);
    //Counter& operator=(const Counter&) = delete;
    ~Counter(){}

    void reset(){ m_counter = 0; }

    unsigned int get(){return m_counter;}
    void operator++()
    {
        m_counter++;
    }
    void operator++(int)
    {
        m_counter++;
    }
    void operator--()
    {
        m_counter--;
    }
    void operator--(int)
    {
        m_counter--;
    }


private:
    unsigned int m_counter;
};


#endif //SHAREDPOINTER_COUNTER_H
