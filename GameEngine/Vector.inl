#include "Vector.h"
#include <cmath>

// ==================================== Vector2d
template<typename T> utils::Vector2d<T>::Vector2d() : x(0), y(0) {}

template<typename T> T utils::Vector2d<T>::get_x() { return this->x; }
template<typename T> T utils::Vector2d<T>::get_y() { return this->y; }

template<typename T> utils::Vector2d<T> &utils::Vector2d<T>::set_x(T value) { this->x = value; return this; }
template<typename T> utils::Vector2d<T> &utils::Vector2d<T>::set_y(T value) { this->y = value; return this; }

template<typename T> size_t utils::Vector2d<T>::get_distance(Vector2d pos) {
	return sqrt(pow(pos.get_x() - this->get_x(), 2) + 
				pow(pos.get_y() - this->get_y(), 2));
}

// ==================================== Vector3d
template<typename T> utils::Vector3d<T>::Vector3d() : z(0) { this->x(0); this->y(0); }

template<typename T> T utils::Vector3d<T>::get_z() { return this->z; }

template<typename T> utils::Vector2d<T>& utils::Vector3d<T>::set_z(T value) { this->z = value; return this; }

template<typename T> size_t utils::Vector3d<T>::get_distance(Vector3d pos) {
	return sqrt(pow(pos.get_x() - this->get_x(), 2) +
				pow(pos.get_y() - this->get_y(), 2) + 
				pow(pos.get_z() - this->get_z(), 2));
}


// =================================== static
template <typename T> size_t utils::get_distance(Vector2d<T> pos_one, Vector2d<T> pos_two) {
	sqrt(pow(pos_two.get_x() - pos_one.get_x(), 2) +
		 pow(pos_two.get_y() - pos_one.get_y(), 2));
}

template <typename T> size_t utils::get_distance(Vector3d<T> pos_one, Vector3d<T> pos_two) {
	sqrt(pow(pos_two.get_x() - pos_one.get_x(), 2) +
		 pow(pos_two.get_y() - pos_one.get_y(), 2) +
		 pow(pos_two.get_z() - pos_one.get_z(), 2));
}