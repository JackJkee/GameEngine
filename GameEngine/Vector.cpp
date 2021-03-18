#include "Vector.h"

// Vector2d
template <typename T>
GameEngine::Vector2d<T>::Vector2d() {
	x = y = 0;
}

template <typename T>
GameEngine::Vector2d<T>::Vector2d(T x, T y) {
	this->x = x;
	this->y = y;
}

template <typename T>
T GameEngine::Vector2d<T>::getX() {
	return this->x;
}

template <typename T>
T GameEngine::Vector2d<T>::getY() {
	return this->y;
}

// Vector3d

template <typename T>
GameEngine::Vector3d<T>::Vector3d() {
	x = y = z = 0;
}

template <typename T>
GameEngine::Vector3d<T>::Vector3d(T x, T y, T z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

template <typename T>
T GameEngine::Vector3d<T>::getX() {
	return this->x;
}

template <typename T>
T GameEngine::Vector3d<T>::getY() {
	return this->y;
}

template <typename T>
T GameEngine::Vector3d<T>::getZ() {
	return this->z;
}

// Matrix


template <typename T>
GameEngine::Matrix<T>::Matrix() {
	x = y = z = a = 0;
}

template <typename T>
GameEngine::Matrix<T>::Matrix(T x, T y, T z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->a = 0;
}

template <typename T>
GameEngine::Matrix<T>::Matrix(T x, T y, T z, T a) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->a = a;
}

template <typename T>
T GameEngine::Matrix<T>::getX() {
	return this->x;
}

template <typename T>
T GameEngine::Matrix<T>::getY() {
	return this->y;
}

template <typename T>
T GameEngine::Matrix<T>::getZ() {
	return this->z;
}

template <typename T>
T GameEngine::Matrix<T>::getA() {
	return this->a;
}