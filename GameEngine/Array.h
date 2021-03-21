#ifndef _ARRAY_
#define _ARRAY_

namespace utils {
	template <typename T> class Array {
	private:
		const size_t default_size = 8;
		size_t array_size = 0;
		size_t memory_size;

		T* array = nullptr;
	public:

		// Constructors
		Array();
		Array(size_t);

		// Methods

		size_t getSize();
		size_t getMemorySize();
		T getElement(size_t);
		Array<T>& Add(T);
	};
}

#include "Array.inl"
#endif