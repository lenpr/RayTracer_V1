/*
 * vector.hpp
 *
 *  Created on: 28.01.2012
 *      Author: LENPR
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
#include <cstddef>


template <std::size_t N=3, typename T=float>
class Vectors {
private:
       T values[N];

public:
       Vectors();
       Vectors(T x, T y, T z);
       template < typename Iterator >
       Vectors(Iterator iter);

       T& operator[] (std::size_t idx);
       Vectors<N,T>& operator* (Vectors<N,T> vec);

       // if defined outside, all hell breaks loose, really not well incorporated in c++
       friend std::ostream& operator<< (std::ostream& stream, const Vectors<N,T>& vec) {
    	   stream << '(';
    	   for(std::size_t i = 0; i < N; ++i){
    		   stream << vec.values[i] << " ";
    	   }
    	   stream << ')';
    	   return stream;
       }
};

// fall-back constructor
template <std::size_t N, typename T>
Vectors<N,T>::Vectors() {
       for(std::size_t i = 0; i < N; ++i){
               values[i] = 0;
       }
}

template <std::size_t N, typename T>
Vectors<N,T>::Vectors(T x, T y, T z) {
       values[0] = x;
       values[1] = y;
       values[2] = z;
}

template <std::size_t N, typename T>
template < typename Iterator >
Vectors<N,T>::Vectors(Iterator iter) {
       for(std::size_t i = 0; i < N; ++i){
               values[i] = *iter++;
       }
}

template <std::size_t N, typename T>
T& Vectors<N,T>::operator[](std::size_t i){
       return values[i % N];
}

// diese Funktion geht auch für dim(v1) != dim(v2), design Entscheidung
template <std::size_t N, typename T>
Vectors<N,T>& Vectors<N,T>::operator*(Vectors<N,T> vec){
       for(std::size_t i = 0; i < N; ++i){
               values[i] *= vec[i];
       }
       return *this;
}


#endif /* VECTORS_HPP_ */

/*
Notes:

Bei der Definition dürfen keine default Werte mehr in den Header:
<std::size_t N=3, typename T=float>, führt zu Fehlern!
template (ohne <) erzwingt explizite Instanziierung des Template, egal
ob es irgendwo in dieser Auspr√§gung verwendet wird.

 */
