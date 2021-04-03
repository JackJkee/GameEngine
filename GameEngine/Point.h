#pragma once

#ifndef __POINT__
#define __POINT__

using namespace std;

namespace GameEngine {

	template<class T> class Point2d
	{
	private:
		T m_x, m_y;
	public:
		//constructors
		Point2d();
		//getters
		T& getX();
		T& getY();
		//setters
		void setX(T value);
		void setY(T value);
		void setPosition(T x);
		void setPosition(T x, T y);
	};

	template<class T> class Point3d : public Point2d<T> 
	{
	private:
		T m_z;
	public:
		//constructors
		Point3d();
		//getters
		T& getZ();
		//setters
		void setZ(T value);
		void setPosition(T x, T y, T z);
	};
}

#include "Point.inl"
#endif