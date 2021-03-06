#pragma once

#include <vector>
#include "Maths/Vector3.hpp"

namespace acid
{
	class ACID_EXPORT IVertex
	{
	public:
		virtual const Vector3 &GetPosition() const = 0;

		virtual void SetPosition(const Vector3 &position) = 0;
	};
}
