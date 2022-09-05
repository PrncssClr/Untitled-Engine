#ifndef BUTTON_H
#define BUTTON_H

#include "Sprite.hpp"
#include <functional>

class Button : public Sprite
{
public:

    Button() = delete;
    Button(std::string);

    std::function<void(void)> OnPress = []{};
    virtual bool OnUpdate();

    bool IsActive = true;
};

#endif