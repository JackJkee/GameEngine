#include "Array.h"

template <typename T>
utils::Array<T>::Array() {
	this->memory_size = default_size;
	array = (T*)malloc(sizeof(T) * default_size);
}

template <typename T>
utils::Array<T>::Array(size_t size) {
	this->memory_size = size;
	array = (T*)malloc(sizeof(T) * size);
}

template <typename T>
size_t utils::Array<T>::getSize() {
	return array_size;
}

template<typename T>
size_t utils::Array<T>::getMemorySize() {
	return memory_size;
}

template <typename T>
utils::Array<T>& utils::Array<T>::Add(T element) {

	if (array_size + 1 > memory_size) {
		//Выделяем новый буффер, который больше в 2 раза предыдущего

		memory_size *= 2;

		T* temp = (T*)malloc(memory_size);

		// Копируем в новый буффер, размер которого в 2 раза больше
		for (size_t i = 0; i < array_size; i++)
		{
			*(temp + i) = *(array + i);
		}

		free(array);
		array = temp;
	}
	else {
		*(array + array_size) = element;
	}
	array_size++;
	return *this;
}

template <typename T>
T utils::Array<T>::getElementByIndex(size_t elementId) {
	if (elementId < 0 || elementId >= array_size)
		throw std::runtime_error("Array out range of point. Index: " + elementId);

	return *(array + elementId);
}

