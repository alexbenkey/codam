#pragma once
#include <iostream>
#include <cstdlib>

#define MAX 1000

template <typename T> 
class Array{
	public:
	Array(): _size(0){};
	Array(unsigned int n): _size(n), _content(new T[n]) {
		for (unsigned int i = 0; i < n; i++)
			_content[i] = 0;
	};
	Array(const Array &rhs): _size(rhs._size), _content(new T[rhs._size]) {
		for (unsigned int i = 0; i < _size; i++)
			_content[i] = rhs._content[i];
	};
	Array & operator=(Array const &rhs){
		if ( this != &rhs){
			delete [] _content;
			_content = new T[rhs._size];
			_size = rhs._size;
			for (unsigned int i = 0; i < _size; i++)
				_content[i] = rhs._content[i];
		}
		return *this;
	};
	unsigned int size() const{
		return _size;
	};
	void get_vals() const{
		for (unsigned int i = 0; i < _size; i++)
			std::cout <<_content[i] << " ";
	};
	T& operator[](unsigned int i ) const {
        if ( i >= _size )
            throw OutOfBoundsException();
        return _content[i];
    }

    ~Array( void ) {
		delete [] _content;
	}

    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() { 
				return "Out of bounds";
			}
    };

	private:
		unsigned int		_size;
		T *					_content;

};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}
