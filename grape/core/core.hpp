#ifndef GRAPEENGINE_CORE_HPP
#define GRAPEENGINE_CORE_HPP

#include <string>
#include <vector>

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

using i8 = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;

using f32 = float;
using f64 = double;

struct GameConfig {
	std::string title;
	u32 width, height;
};

#endif