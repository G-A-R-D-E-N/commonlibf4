#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class __declspec(novtable) RunHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::RunHandler };
		static constexpr auto VTABLE{ VTABLE::RunHandler };

		std::uint16_t unk20;
		std::byte     padding22[6];
		bool          isRunning;
	};
	static_assert(sizeof(RunHandler) == 0x30);
}
