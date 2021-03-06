#pragma once
#include "oasis.h"

constexpr float kDeathScreenTimer = 3.f;

class Death : public Oasis::IState
{
public:
    Death();

    virtual void Init() override;
    virtual void Close() override;

    virtual void OnEvent(const Oasis::Event& event) override;
    virtual Oasis::IState * Update() override;
private:
    Oasis::Sprite m_background;

    // timers
    float m_deathScreenTimer;

    // transition timers
    bool m_buttonPressed;
    float m_fadeInTimer;
    const float m_fadeInTime = 3.f;
    float m_fadeOutTimer;
    const float m_fadeOutTime = 1.f;
};