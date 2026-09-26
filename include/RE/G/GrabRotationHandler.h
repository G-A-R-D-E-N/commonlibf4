#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class __declspec(novtable) GrabRotationHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::GrabRotationHandler };
		static constexpr auto VTABLE{ VTABLE::GrabRotationHandler };

		std::uint16_t unk20;
		std::byte     padding22[6];
		std::uint8_t  rotationAxis;
	};
	static_assert(sizeof(GrabRotationHandler) == 0x30);
}
