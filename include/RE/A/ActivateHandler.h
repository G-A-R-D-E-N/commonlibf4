#pragma once

#include "RE/B/BSInputEnableLayer.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class __declspec(novtable) ActivateHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::ActivateHandler };
		static constexpr auto VTABLE{ VTABLE::ActivateHandler };

		void DisableInput()
		{
			using func_t = decltype(&ActivateHandler::DisableInput);
			static REL::Relocation<func_t> func{ ID::ActivateHandler::DisableInput };
			return func(this);
		}

		std::uint16_t                                                         unk20;
		BSTSmartPointer<BSInputEnableLayer, BSTSmartPointerIntrusiveRefCount> inputEnableLayer;
		std::uint32_t                                                         unk30;
		bool                                                                  unk34;
	};
	static_assert(sizeof(ActivateHandler) == 0x38);
}
