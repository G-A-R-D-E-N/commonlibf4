#pragma once

#include "RE/B/BSInputEventUser.h"

namespace RE
{
	class GFxConvertHandler : public BSInputEventUser
	{
	public:
		static constexpr auto RTTI{ RTTI::GFxConvertHandler };
		static constexpr auto VTABLE{ VTABLE::GFxConvertHandler };

		using ButtonEventHandler = void (*)(GFxConvertHandler*, ButtonEvent*);
		using ThumbstickEventHandler = void (*)(GFxConvertHandler*, ThumbstickEvent*);

		[[nodiscard]] ButtonEventHandler GetButtonEventHandler() const
		{
			return reinterpret_cast<ButtonEventHandler>(GetVTable()[8]);
		}

		[[nodiscard]] ThumbstickEventHandler GetThumbstickEventHandler() const
		{
			return reinterpret_cast<ThumbstickEventHandler>(GetVTable()[4]);
		}

	private:
		[[nodiscard]] void* const* GetVTable() const
		{
			return *reinterpret_cast<void* const* const*>(this);
		}
	};

	static_assert(sizeof(GFxConvertHandler) == 0x10);
}
