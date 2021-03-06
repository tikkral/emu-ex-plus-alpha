#pragma once

/*  This file is part of Imagine.

	Imagine is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Imagine is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Imagine.  If not, see <http://www.gnu.org/licenses/> */

#include <cmath>
#include <imagine/util/bits.h>
#include <imagine/util/typeTraits.hh>
#include <imagine/util/assume.h>

namespace IG
{

template<class T>
static T fls(T x)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	if(sizeof(T) <= sizeof(int))
		return ::fls(x);
	else
		return ::flsl(x);
}

template<class T>
static T roundUpPowOf2(T x)
{
	static_assert(std::is_unsigned<T>::value, "expected unsigned parameter");
	return 1 << fls(x - 1);
}

template<class T>
static T roundDownPowOf2(T x)
{
	static_assert(std::is_unsigned<T>::value, "expected unsigned parameter");
	return 1 << (fls(x) - 1);
}

template <typename T>
static T pow(T base, T exp)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	T result = 1;
	while(exp)
	{
		if(exp & 1) // exp % 2 == 1
		{
			result *= base;
		}
		exp >>= 1; // exp /= 2
		base *= base;
	}
	return result;
}

template<class T>
constexpr static bool isEven(T x)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	return x % 2 == 0;
}

template<class T>
constexpr static bool isOdd(T x)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	return !isEven(x);
}

template<class T>
constexpr static T makeEvenRoundedUp(T x)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	return isEven(x) ? x : x+1;
}

template<class T>
constexpr static T makeEvenRoundedDown(T x)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	return isEven(x) ? x : x-1;
}

template <class T>
static constexpr bool isPowerOf2(T x)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	return x && !( (x-1) & x );
	// return ((x != 0) && ((x & (~x + 1)) == x)); // alternate method
}

template <class T>
static T alignRoundedUp(T addr, unsigned int align)
{
	static_assert(std::is_unsigned<T>::value, "expected unsigned parameter");
	assumeExpr(isPowerOf2(align));
	return (addr+(align-1)) & ~(align-1);
}

// divide integer rounding-upwards
template<class T>
constexpr static T divRoundUp(T x, T y)
{
	static_assert(std::is_integral<T>::value, "expected integral parameter");
	return (x + (y - 1)) / y;
}

// divide rounding to closest integer
template<class T>
constexpr static T divRoundClosest(T x, T y)
{
	if constexpr(std::is_unsigned<T>::value)
	{
		return (x > 0) ?
			(x + (y / 2)) / y :
			(x - (y / 2)) / y;
	}
	else if constexpr(std::is_floating_point<T>::value)
	{
		return std::round(x / y);
	}
	else
	{
		// error
	}
}

}
