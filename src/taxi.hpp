#pragma once
#include "tinclude.hpp"
#include "tutil.hpp"
#include "core/tcore.hpp"
#include "surface/tsurface.hpp"
#include "render/trender.hpp"
#include "event/tevent.hpp"
#include "input/tinput.hpp"
#include "font/tfont.hpp"
#include "tstream/tstream.hpp"
/**
 * Init function, now it directly returns initCore
 * @return the return value of `initCore()`
 */
bool init() {
    return initCore();
}