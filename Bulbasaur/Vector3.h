#ifndef VECTOR3_H
#define VECTOR3_H

#include "MathUtility.h"

class Vector3
{
public:
	float x, y, z;
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {}

	// ���ظ�ֵ���������������
	Vector3& operator=(const Vector3 &a);

	bool operator==(const Vector3& a) const;

	bool operator!=(const Vector3& a) const;

	// �������,����"|"�����
	float operator|(const Vector3& a) const;

	Vector3 operator-() const;

	Vector3 operator+(const Vector3& a) const;

	Vector3 operator-(const Vector3& a) const;

	// �����������ˣ�����"*"�����
	Vector3 operator*(float a)const;

	Vector3 operator/(float a)const;

	Vector3& operator+=(const Vector3& a);

	Vector3& operator-=(const Vector3& a);

	Vector3& operator*=(float a);

	Vector3& operator/=(float a);

	// ��Ϊ������
	void zero();

	// ������׼��
	void normalize();

	// ����ģ��
	inline float Length()
	{
		return sqrtf(*this | *this);
	}

	// �������
	static inline Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}

	// ��������
	static inline float Distance(const Vector3& a, const Vector3& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		float dz = a.z - a.z;
		return sqrtf(dx * dx + dy * dy + dz * dz);
	}

	// ������ֵ��tȡֵ [0, 1]
	static inline Vector3 Leap(const Vector3& a, const Vector3& b, float t)
	{
		return LinearInterpolate(a, b, t); 
	}
};


// ������ˣ�����"*"�����
Vector3 operator*(float k, const Vector3& v);




#endif // !VECTOR3_H
