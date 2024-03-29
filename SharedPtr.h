//
// Created by hadasswittow on 12/8/19.
//

#ifndef SHAREDPOINTER_SHAREDPTR_H
#define SHAREDPOINTER_SHAREDPTR_H

#include "Counter.h"
#include <cstddef>
#include <iostream>
using std::ostream;
template<typename T>
class SharedPtr {
public:
    explicit SharedPtr(T* other);
    SharedPtr(SharedPtr<T>& sp);
    ~SharedPtr(){ destroyPtr(); }
    //SharedPtr<T>& operator=(T* other); -don't want to allow assignment from raw pointer- it ruins the shared ptr
    SharedPtr<T>& operator=(const SharedPtr<T>& sp);
    T& operator*();
    T* operator->();
    operator bool(){return (m_ptr != NULL);}

    //  we need this so the base ptr can point a derived ptr
//    template<typename U>
//    SharedPtr<T>& operator=(const SharedPtr<U>& sp);
//    template<typename U>
//    friend class SharedPtr;



    friend ostream& operator<<(ostream& os, SharedPtr<T>& sp)
    {
        os << "Address pointed : "
           << sp.m_ptr << "\nValue : " <<*(sp.m_ptr)<<"\nCount : "<<(sp.m_counter->get())<< std::endl;
        return os;
    }
private:
    T* m_ptr;
    Counter* m_counter;
    void destroyPtr();


};
template<typename T>
inline SharedPtr<T>::SharedPtr(T* other)
{
    m_ptr = other;
    m_counter = new Counter();
    if(m_ptr)
        ++(*m_counter);
}
template<typename T>
inline SharedPtr<T>::SharedPtr(SharedPtr<T>& sp){
    m_ptr = sp.m_ptr;
    m_counter  = sp.m_counter;
    ++(*m_counter);
}

template<typename T>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& sp){
    destroyPtr();
    m_ptr = sp.m_ptr;
    m_counter = sp.m_counter;
    if(m_ptr)
        ++(*m_counter);
}
template<typename T>
inline T& SharedPtr<T>::operator*(){
    return *m_ptr;
}
template<typename T>
inline T* SharedPtr<T>::operator->(){
    return m_ptr;
}
template<typename T>
inline void SharedPtr<T>::destroyPtr(){
    --(*m_counter);
    if(m_counter->get() == 0){
        delete(m_ptr);
        delete(m_counter);
    }
}
#endif //SHAREDPOINTER_SHAREDPTR_H
