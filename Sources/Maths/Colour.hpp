#pragma once

#include <ostream>
#include <string>
#include "Serialized/Metadata.hpp"
#include "Engine/Exports.hpp"

namespace acid
{
	class Vector3;
	class Vector4;

	/// <summary>
	/// Holds a RGBA colour.
	/// </summary>
	class ACID_EXPORT Colour
	{
	public:
		/// <summary>
		/// Constructor for colour.
		/// </summary>
		/// <param name="r"> The new R value. </param>
		/// <param name="g"> The new G value. </param>
		/// <param name="b"> The new B value. </param>
		/// <param name="a"> The new A value. </param>
		Colour(const float &r = 0.0f, const float &g = 0.0f, const float &b = 0.0f, const float &a = 1.0f);

		/// <summary>
		/// Constructor for colour.
		/// </summary>
		/// <param name="hex"> The new values from HEX. </param>
		/// <param name="a"> The new A value. </param>
		Colour(const std::string &hex, const float &a = 1.0f);

		/// <summary>
		/// Constructor for colour.
		/// </summary>
		/// <param name="source"> Creates this colour out of a existing vector. </param>
		/// <param name="a"> The new A value. </param>
		Colour(const Vector3 &source, const float &a = 1.0f);

		/// <summary>
		/// Constructor for colour.
		/// </summary>
		/// <param name="source"> Creates this colour out of a existing vector. </param>
		Colour(const Vector4 &source);

		/// <summary>
		/// Adds this colour to another colour.
		/// </summary>
		/// <param name="other"> The other colour. </param>
		/// <returns> The resultant colour. </returns>
		Colour Add(const Colour &other) const;

		/// <summary>
		/// Subtracts this colour to another colour.
		/// </summary>
		/// <param name="other"> The other colour. </param>
		/// <returns> The resultant colour. </returns>
		Colour Subtract(const Colour &other) const;

		/// <summary>
		/// Multiplies this colour with another colour.
		/// </summary>
		/// <param name="other"> The other colour. </param>
		/// <returns> The resultant colour. </returns>
		Colour Multiply(const Colour &other) const;

		/// <summary>
		/// Divides this colour by another colour.
		/// </summary>
		/// <param name="other"> The other colour. </param>
		/// <returns> The resultant colour. </returns>
		Colour Divide(const Colour &other) const;

		/// <summary>
		/// Scales this colour by a scalar.
		/// </summary>
		/// <param name="scalar"> The scalar value. </param>
		/// <returns> The scaled colour. </returns>
		Colour Scale(const float &scalar) const;

		/// <summary>
		/// Calculates the linear interpolation between this colour and another colour.
		/// </summary>
		/// <param name="other"> The other quaternion. </param>
		/// <param name="progression"> The progression. </param>
		/// <returns> Left lerp right. </returns>
		Colour Lerp(const Colour &other, const float &progression) const;

		/// <summary>
		/// Normalizes this colour.
		/// </summary>
		/// <returns> The normalized colour. </returns>
		Colour Normalize() const;

		/// <summary>
		/// Gets the length squared of this colour.
		/// </summary>
		/// <returns> The length squared. </returns>
		float LengthSquared() const;

		/// <summary>
		/// Gets the length of this colour.
		/// </summary>
		/// <returns> The length. </returns>
		float Length() const;

		/// <summary>
		/// Gradually changes this colour to a target.
		/// </summary>
		/// <param name="target"> The target colour. </param>
		/// <param name="rate"> The rate to go from current to the target. </param>
		/// <returns> The changed colour. </returns>
		Colour SmoothDamp(const Colour &target, const Colour &rate) const;

		/// <summary>
		/// Gets a colour representing the unit value of this colour.
		/// </summary>
		/// <returns> The unit colour. </returns>
		Colour GetUnit() const;

		/// <summary>
		/// Gets the hex code from this colour.
		/// </summary>
		/// <returns> The hex code. </returns>
		std::string GetHex() const;

		const float &GetR() const { return m_r; }

		void SetR(const float &r) { m_r = r; }

		const float &GetG() const { return m_g; }

		void SetG(const float &g) { m_g = g; }

		const float &GetB() const { return m_b; }

		void SetB(const float &b) { m_b = b; }

		const float &GetA() const { return m_a; }

		void SetA(const float &a) { m_a = a; }

		void Decode(const Metadata &metadata);

		void Encode(Metadata &metadata) const;

		bool operator==(const Colour &other) const;

		bool operator!=(const Colour &other) const;

		bool operator<(const Colour &other) const;

		bool operator<=(const Colour &other) const;

		bool operator>(const Colour &other) const;

		bool operator>=(const Colour &other) const;

		bool operator==(const float &value) const;

		bool operator!=(const float &value) const;

		const float &operator[](const uint32_t &index) const;

		float &operator[](const uint32_t &index);

		ACID_EXPORT friend Colour operator+(const Colour &left, const Colour &right);

		ACID_EXPORT friend Colour operator-(const Colour &left, const Colour &right);

		ACID_EXPORT friend Colour operator*(const Colour &left, const Colour &right);

		ACID_EXPORT friend Colour operator/(const Colour &left, const Colour &right);

		ACID_EXPORT friend Colour operator+(const float &value, const Colour &left);

		ACID_EXPORT friend Colour operator-(const float &value, const Colour &left);

		ACID_EXPORT friend Colour operator*(const float &value, const Colour &left);

		ACID_EXPORT friend Colour operator/(const float &value, const Colour &left);

		ACID_EXPORT friend Colour operator+(const Colour &left, const float &value);

		ACID_EXPORT friend Colour operator-(const Colour &left, const float &value);

		ACID_EXPORT friend Colour operator*(const Colour &left, const float &value);

		ACID_EXPORT friend Colour operator/(const Colour &left, const float &value);

		Colour &operator+=(const Colour &other);

		Colour &operator-=(const Colour &other);

		Colour &operator*=(const Colour &other);

		Colour &operator/=(const Colour &other);

		Colour &operator+=(const float &value);

		Colour &operator-=(const float &value);

		Colour &operator*=(const float &value);

		Colour &operator/=(const float &value);

		ACID_EXPORT friend std::ostream &operator<<(std::ostream &stream, const Colour &colour);

		std::string ToString() const;

		static const Colour Clear;
		static const Colour Black;
		static const Colour Grey;
		static const Colour Silver;
		static const Colour White;
		static const Colour Maroon;
		static const Colour Red;
		static const Colour Olive;
		static const Colour Yellow;
		static const Colour Green;
		static const Colour Lime;
		static const Colour Teal;
		static const Colour Aqua;
		static const Colour Navy;
		static const Colour Blue;
		static const Colour Purple;
		static const Colour Fuchsia;

		union
		{
			struct
			{
				float m_elements[4];
			};

			struct
			{
				float m_r, m_g, m_b, m_a;
			};
		};
	};
}
