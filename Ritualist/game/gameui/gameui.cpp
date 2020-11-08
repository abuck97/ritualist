#include "gameui.hpp"

#include "game.hpp"
#include "entities/player.hpp"

GameUI::GameUI()
    : m_healthUISprite("res/ui_assets/player_health_ui.png")
{
    
}

void GameUI::Init() 
{

}

void GameUI::Close() 
{

}

bool GameUI::HandleEvent(const Oasis::Event& event) 
{
    return false;
}

Oasis::IState * GameUI::Update()  
{
    {   // Render the player health bar
        Ref<Player> player = GameService::GetPlayer();
        float percent = player->GetHealth() / player->GetHealthCapacity();
        constexpr float x = 10.f + 1.f;
        constexpr float y = 10.f + 1.f;
        constexpr float w = 300.f - 2.f;
        constexpr float h = 50.f - 2.f;
        Oasis::Renderer::DrawQuad(x, y, w * percent, h, Oasis::Colours::RED);
        m_healthUISprite.SetPos(10.f, 10.f);
        m_healthUISprite.SetDimensions(300.f, 50.f);
        Oasis::Renderer::DrawSprite(&m_healthUISprite);
    }

    {   // Render the boss health bar
        Ref<Entity> boss = GameService::GetBoss();
        if (boss)
        {
            float percent = boss->GetHealth() / boss->GetHealthCapacity();
            const float x = Oasis::WindowService::WindowWidth() / 2 - 350.f;
            const float y = Oasis::WindowService::WindowHeight() - 35.f;
            constexpr float w = 600.f;
            constexpr float h = 15.f;
            Oasis::Renderer::DrawQuad(x, y, w * percent, h, Oasis::Colours::RED);   
        }
    }

    return nullptr;
}
