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

namespace avalon_motor_controller
{
    struct PIDSettings
    {
        double p;
        double i;
        double d;
        double min;
        double max;
#ifndef __orogen
        PIDSettings()
            : p(0), i(0), d(0), min(0), max(0) {}

        bool operator == (PIDSettings const& other) const
        { return p == other.p && i == other.i && d == other.d &&
            min == other.min && max == other.max; }
        bool operator != (PIDSettings const& other) const
        { return !(*this == other); }
#endif
    };

}

#endif
