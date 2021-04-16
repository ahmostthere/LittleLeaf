
#ifndef HUD_ITEM
#define HUD_ITEM
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>

class HUDItem : public sf::Drawable
{
private:
    sf::Texture m_Texture;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        // target.draw();
    }

public:
    virtual void load() = 0;
};

#endif //HUD_ITEM