#pragma once

#include <cstdint>

namespace RE
{
	class ScaleformMenuEvent
	{
	public:
		[[nodiscard]] std::uint32_t GetType() const { return type; }
		[[nodiscard]] std::uint32_t GetKey() const { return key; }

	private:
		std::uint32_t type{ 0 };
		std::uint32_t pad04{ 0 };
		std::uint32_t key{ 0 };
		std::byte     reserved[0x14]{};
	};
	static_assert(sizeof(ScaleformMenuEvent) == 0x20);
}
