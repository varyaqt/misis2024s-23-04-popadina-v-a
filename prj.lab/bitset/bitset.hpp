#pragma once
#ifndef BITSET_HPP
#define BITSET_HPP

#include <algorithm>
#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
public:
	BitSet() = default;
	BitSet(const BitSet& rhs) = default;
	BitSet(BitSet&& rhs) = default;
	explicit BitSet(const std::int32_t size) : size_(size), bits_(size) {}
	~BitSet() = default;
	BitSet& operator=(const BitSet& rhs) = default;
	BitSet& operator=(BitSet&& rhs) = default;
	[[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
	[[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;
	std::int32_t Size() const noexcept { return size_; }
	void Resize(const std::int32_t size); // 0 < size

	[[nodiscard]] bool Get(const std::int32_t idx) const;

	void Set(const std::int32_t idx, const bool val);
	void Fill(const bool val) noexcept;

	[[nodiscard]] BitSet& operator&=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator|=(const BitSet& rhs);
	[[nodiscard]] BitSet& operator^=(const BitSet& rhs);
	[[nodiscard]] BitSet operator~();
	std::vector<std::uint32_t> same_size(const BitSet& v1, const BitSet& v2);

private:
	std::int32_t size_ = 0;
	std::vector<uint32_t> bits_;
};


[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif
