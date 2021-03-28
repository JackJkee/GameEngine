#pragma once
#include <cmath>

namespace utils {

	template <typename T>
	class Vector2d
	{
	private:
		T x, y;
	public:
		//constructors
		Vector2d();
		//getters
		T get_x();
		T get_y();		
		//methods
		virtual size_t get_distance(Vector2d);
	};

	template <typename T> 
	class Vector3d : public Vector2d<T> {
	private:
		T z;
	public:
		//constructors
		Vector3d();
		//getters
		T get_z();
		//methods
		size_t get_distance (Vector3d) override;
	};

	// Get distance between vectors (2D)
	template <typename T> size_t get_distance(Vector2d<T> pos_one, Vector2d<T> pos_two);
	// Get distance between vectors (3D)
	template <typename T> size_t get_distance(Vector3d<T> pos_one, Vector3d<T> pos_two);
}

