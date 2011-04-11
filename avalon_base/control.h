#ifndef AVAON_TYPE_CONTROL_H__
#define AVAON_TYPE_CONTROL_H__

namespace avalon {

struct DOFSelection
{
    bool x;
    bool y;
    bool z;
    bool heading;
    DOFSelection()
        : x(0), y(0), z(0), heading(0){};
};

}

#endif
