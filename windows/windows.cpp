#include "windows.h"

namespace DB { namespace DSP {

	void DSP::windows::applyHamming(std::vector<float>* data)
	{
		float dataLength = data->size();

		float sampleNum = 0;
		for (auto&& sample : *data )
		{
			sample *= 0.54 - 0.46*cos(2.0 * 3.141592654*sampleNum/dataLength); 
			sampleNum++;
		}
	}

	void windows::applyHann(std::vector<float>* data)
	{
		float dataLength = data->size();

		float sampleNum = 0;
		for (auto&& sample : *data)
		{
			sample *= 0.5 - 0.5*cos(2.0 * 3.141592654*sampleNum/dataLength);
			sampleNum++;
		}
	}

	void windows::applyBartlett(std::vector<float>* data)
	{
		float dataLength = data->size();

		float sampleNum = 0;
		for (auto&& sample : *data)
		{
			if (sampleNum <= dataLength / 2.0) sample *= 2.0 * sampleNum/dataLength;
			else sample *= 2.0 - 2.0*sampleNum / dataLength;
			sampleNum++;
		}
	}

	void windows::applyBlackman(std::vector<float>* data)
	{
		float dataLength = data->size();

		float sampleNum = 0;
		for (auto&& sample : *data)
		{
			sample *= 0.42 - 0.5*cos(2.0 * 3.141592654*sampleNum / dataLength)+0.08*cos(4.0*3.141592654*sampleNum/dataLength);
			sampleNum++;
		}
	}


}
}