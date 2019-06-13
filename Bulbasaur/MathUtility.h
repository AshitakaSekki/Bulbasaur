#ifndef	MATHUTILITY_H
#define MATHUTILITY_H

#include <SDL.h>
#include <math.h>
#include <random>

#include "Vector3.h"
#include "Vector4.h"

// �����ֵ��t Ϊ [0, 1] ֮�����ֵ
template <typename T>
T inline LinearInterpolate(const T& x1, const T& x2, T t)
{
	return x1 + (x2 - x1) * t;
}

template <class T>
T inline Clamp(T value, T min, T max)
{
	if (value < min)
	{
		return min;
	}
	else if (value > max)
	{
		return max;
	}
	else
	{
		return value;
	}
}


namespace Random
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<Uint32> i(0, 0xFFFFFFFF);
	static std::uniform_real_distribution<float> r(0.0f, 1.0f);

	static Uint32 GetUint32()
	{
		return i(e);
	}

	static float GetNormalizedFloat()
	{
		return r(e);
	}
};


#endif // !MATHUTILITY_H
