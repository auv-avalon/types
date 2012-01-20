#ifndef AVAON_TYPE_audio_data_H__
#define AVAON_TYPE_audio_data_H__
#include <base/time.h>
#include <vector>
namespace avalon {

struct audio_data{
    std::vector<float> left;
    std::vector<float> right;
    base::Time timeLeft;
    base::Time timeRight;
};

}

#endif
