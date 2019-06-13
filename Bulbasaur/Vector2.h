#ifndef VECTOR2_H
#define VECTOR2_H

#include "MathUtility.h"

class Vector2
{
public:
	float x, y;
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(const Vector2& a) : x(a.x), y(a.y) {}
	Vector2(float _x, float _y) :x(_x), y(_y) {}

	// ���ظ�ֵ���������������
	Vector2& operator=(const Vector2& a);

	bool operator==(const Vector2& a) const;

	bool operator!=(const Vector2& a) const;

	// �������,����"|"�����
	float operator|(const Vector2& a) const;

	Vector2 operator-() const;

	Vector2 operator+(const Vector2& a) const;

	Vector2 operator-(const Vector2& a) const;

	// �����������ˣ�����"*"�����
	Vector2 operator*(float a)const;

	Vector2 operator/(float a)const;

	Vector2& operator+=(const Vector2& a);

	Vector2& operator-=(const Vector2& a);

	Vector2& operator*=(float a);

	Vector2& operator/=(float a);

	// ��Ϊ������
	void zero();

	// ������׼��
	void normalize();

	// ����ģ��
	inline float Length()
	{
		return sqrtf(*this | *this);
	}

	// ��������
	static inline float Distance(const Vector2& a, const Vector2& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		return sqrtf(dx * dx + dy * dy);
	}

	// ������ֵ��tȡֵ [0, 1]
	static inline Vector2 Leap(const Vector2& a, const Vector2& b, float t)
	{
		return LinearInterpolate(a, b, t);
	}
};


// ������ˣ�����"*"�����
Vector2 operator*(float k, const Vector2& v);




#endif // !VECTOR2_H
