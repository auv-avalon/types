#ifndef AVALON_AUDIO_SAMPLES_H__
#define AVALON_AUDIO_SAMPLES_H__
#include <base/time.h>
#include <vector>

namespace avalon
{

struct PingerSamples {
    int sample_frequency;
    base::Time timestamp;
    std::vector<float> data;
    
    PingerSamples() : sample_frequency(0), timestamp(base::Time::now()) {};
    
    bool isValid()
    {
        if(data.size() != 0 && sample_frequency > 0)
            return true;
        return false;
    };
    
    void clear()
    {
        data.clear();
        sample_frequency = 0;
        timestamp = base::Time::now();
    };
};

struct AudioSamples {
    std::vector<float> left_channel;
    std::vector<float> right_channel;
    int sample_frequency;
    base::Time timestamp;
    
    AudioSamples() : sample_frequency(0), timestamp(base::Time::now()) {};

    bool isValid()
    {
        if(left_channel.size() == right_channel.size() && sample_frequency > 0)
            return true;
        return false;
    };
    
    void clear()
    {
        left_channel.clear();
        right_channel.clear();
        sample_frequency = 0;
        timestamp = base::Time::now();
    };
};

}

#endif
