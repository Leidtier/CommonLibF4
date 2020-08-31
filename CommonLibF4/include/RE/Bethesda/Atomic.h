#pragma once

namespace RE
{
	template <class T>
	class BSTAtomicValue
	{
	public:
		static_assert(std::is_integral_v<T>);

		using value_type = T;

		constexpr BSTAtomicValue() noexcept = default;

		constexpr BSTAtomicValue(T a_rhs) noexcept :
			_value(a_rhs)
		{}

		inline T operator++()
		{
			stl::atomic_ref value{ _value };
			return ++value;
		}

		[[nodiscard]] inline T operator++(int)
		{
			stl::atomic_ref value{ _value };
			return value++;
		}

		inline T operator--()
		{
			stl::atomic_ref value{ _value };
			return --value;
		}

		[[nodiscard]] inline T operator--(int)
		{
			stl::atomic_ref value{ _value };
			return value--;
		}

		// members
		value_type _value{};  // 0
	};

	extern template class BSTAtomicValue<std::int32_t>;
	extern template class BSTAtomicValue<std::uint32_t>;
	extern template class BSTAtomicValue<std::int64_t>;
	extern template class BSTAtomicValue<std::uint64_t>;
}