#pragma once

namespace Scaleform::Render
{
	class Cxform
	{
	public:
		enum class Format : std::int32_t
		{
			kR = 0,
			kG = 1,
			kB = 2,
			kA = 3,

			kTotal = 4
		};

		enum class Type : std::int32_t
		{
			kMult = 0,
			kAdd = 1,

			kTotal = 2
		};

		float data[2][4];
	};
	static_assert(sizeof(Cxform) == 0x20);
}
