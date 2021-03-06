#pragma once

// Project
#include "../common_classes/OpenGLWindow.h"
#include "../common_classes/HUD.h"

/**
 * HUD for tutorial 018 (heightmap pt.1 - random terrain).
 */
class HUD018 : public HUD
{
public:
    HUD018(const OpenGLWindow& window);

    /**
     * Renders HUD.
     */
    void renderHUD() const override {} // Don't need this, but had to override, so that class is not abstract
    void renderHUD(const bool displayNormals) const;
};
