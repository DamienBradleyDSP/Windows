#pragma once
#include <vector>
#include <math.h>

namespace DB { namespace DSP {
class windows
{
public:
	static void applyHamming(std::vector<float>* data);
	static void applyHann(std::vector<float>* data);
	static void applyBartlett(std::vector<float>* data);
	static void applyBlackman(std::vector<float>* data);
};

}}

