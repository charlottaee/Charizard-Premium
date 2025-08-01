#pragma once

#include <GL/gl.h>

namespace GLUtils {
    void setupRenderState();
    void restoreRenderState();
    void drawRect(float x, float y, float width, float height, unsigned int color);
    void drawRoundedRect(float x, float y, float width, float height, float radius, unsigned int color);
}
