#pragma once
namespace GameEngine {
	template<typename T>
	class Vector2d
	{
	private:
		T x, y;		
	public:
		Vector2d();
		Vector2d(T x, T y);

		T getX();
		T getY();
	};

	template<typename T>
	class Vector3d
	{
	private:
		T x, y, z;
	public:
		Vector3d();
		Vector3d(T x, T y, T z);

		T getX();
		T getY();
		T getZ();
	};

	template <typename T>
	class Matrix {
	private:
		T x, y, z, a;
	public:
		Matrix();
		Matrix(T, T, T);
		Matrix(T, T, T, T);
		
		T getX();
		T getY();
		T getZ();
		T getA();
	};
}


