#pragma once

#include "Key.h"

enum class EventType {
    None,
    Closed,
    KeyPressed,
    KeyReleased
};

struct Event {
    EventType type;
    Key key;
};