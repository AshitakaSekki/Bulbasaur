#ifndef VECTOR4_H
#define VECTOR4_H

#include "MathUtility.h"

class Vector4
{
public:
	float x, y, z, w;
	Vector4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
	Vector4(const Vector4& a) : x(a.x), y(a.y), z(a.z), w(a.w) {}
	Vector4(float _x, float _y, float _z) :x(_x), y(_y), z(_z), w(1.0f) {}

	// ���ظ�ֵ���������������
	//Vector4& operator=(const Vector4 &a);

	bool operator==(const Vector4& a) const;

	bool operator!=(const Vector4& a) const;

	// �������,����"*"�����
	float operator*(const Vector4 & a) const;

	Vector4 operator-() const;

	Vector4 operator+(const Vector4 & a) const;

	Vector4 operator-(const Vector4 & a) const;

	// �����������ˣ�����"*"�����
	Vector4 operator*(float a)const;

	Vector4 operator/(float a)const;

	Vector4& operator+=(const Vector4 & a);

	Vector4& operator-=(const Vector4 & a);

	Vector4& operator*=(float a);

	Vector4& operator/=(float a);

	// ��Ϊ������
	void zero();

	// ������׼��
	void normalize();

	// ����ģ��
	static inline float Magnitude(const Vector4& a)
	{
		float sq = a.x * a.x + a.y * a.y + a.z * a.z;
		return sqrtf(sq);
	}

	// �������
	static inline Vector4 Cross(const Vector4& a, const Vector4& b)
	{
		return Vector4(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}

	// ��������
	static inline float Distance(const Vector4& a, const Vector4& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		float dz = a.z - a.z;
		return sqrtf(dx * dx + dy * dy + dz * dz);
	}

	// ������ֵ��tȡֵ [0, 1]
	static inline Vector4 Leap(const Vector4 & a, const Vector4 & b, float t)
	{
		return Vector4(a + (b - a) * t);
	}
};


// ������ˣ�����"*"�����
Vector4 operator*(float k, const Vector4 & v);




#endif // !VECTOR4_H
