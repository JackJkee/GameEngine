#include "Point.h"

// Point2d
template<class T> GameEngine::Point2d<T>::Point2d() { setX(0); setY(0); }
template<class T> T& GameEngine::Point2d<T>::getX() { return m_x; }
template<class T> T& GameEngine::Point2d<T>::getY() { return m_y; }
template<class T> void GameEngine::Point2d<T>::setX(T x) { this->m_x = x; }
template<class T> void GameEngine::Point2d<T>::setY(T y) { m_y = y; }
template<class T> void GameEngine::Point2d<T>::setPosition(T x) { setX(x); }
template<class T> void GameEngine::Point2d<T>::setPosition(T x, T y) { setX(x); setY(y); }

// Point3d
template<class T> GameEngine::Point3d<T>::Point3d() { setZ(0); }
template<class T> T& GameEngine::Point3d<T>::getZ() { return m_z; }
template<class T> void GameEngine::Point3d<T>::setZ(T z) { m_z = z; }
template<class T> void GameEngine::Point3d<T>::setPosition(T x, T y, T z) { setX(x); setY(y); setZ(z); }

