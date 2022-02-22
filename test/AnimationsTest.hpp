#ifndef TESTING
#define TESTING

#include "Test.hpp"

#include "Animations.hpp"

class Testing : public Test
{
public:
    static void load();
    static void handleInput();
    static void update();
    static void render();

public:
};

// Add Test objects here
// TODO
class Prop : public sf::Drawable {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string texture_asset;
    Prop(std::string _texture_asset) : texture_asset(_texture_asset)
    {

    }

    void load() 
    {
        if (!texture.loadFromFile(texture_asset))
        {
            std::cout << "Failed to load image" << std::endl;
        }
        sprite.setTexture(texture);
    }

    void update()
    {

    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(sprite);
    }
};

class Actor : public sf::Drawable {
public:
    Animation animations[4];
    AnimatedSprite sprite;
    sf::Texture texture;
    std::string texture_asset;
    Actor(std::string _texture_asset) : texture_asset(_texture_asset)
    { 

    }

    void load()
    {
        if (!texture.loadFromFile(texture_asset))
        {
            std::cout << "Failed to load image" << std::endl;
        }

        // 4 movement animations
        for (int i = 0; i < 4; i++) 
        {
            animations[i].setSpriteSheet(texture);
        }

        // 8 frames per animation
        for (int i = 0; i < 8; i++)
        {
            // down
            animations[0].addFrame(sf::IntRect(i * 50, 0, 50, 50));
            // up
            animations[1].addFrame(sf::IntRect(i * 50, 50, 50, 50));
            // left
            animations[2].addFrame(sf::IntRect(i * 50, 100, 50, 50));
            // right
            animations[3].addFrame(sf::IntRect(i * 50, 150, 50, 50));
        }

        // default animation
        sprite.setAnimation(animations[0]);
        sprite.setFrameTime(sf::seconds(0.062f));
    }

    void setPosition(float x, float y) 
    {
        sprite.setPosition(x, y);
    }

    void setPosition(const sf::Vector2f& position) 
    {
        sprite.setPosition(position);
    }

    void play(int direction = 0)
    {
        switch(direction)
        {
            case 0:
                if (!sprite.isPlaying())
                {
                    sprite.setAnimation(animations[0]);
                    sprite.play();
                }
                break;
            case 1:
                if (!sprite.isPlaying())
                {
                    sprite.setAnimation(animations[1]);
                    sprite.play();
                }
                break;
            case 2:
                if (!sprite.isPlaying())
                {
                    sprite.setAnimation(animations[2]);
                    sprite.play();
                }
                break;
            case 3:
                if (!sprite.isPlaying())
                {
                    sprite.setAnimation(animations[3]);
                    sprite.play();
                }
                break;
            default:
                if (!sprite.isPlaying())
                {
                    sprite.setAnimation(animations[0]);
                    sprite.play();
                }
                break;
        }
    }

    void pause()
    {
        sprite.pause();
    }

    void update(sf::Time deltaTime)
    {
        sprite.update(deltaTime);
    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(sprite);
    }
};


Prop Tree("assets/tree.png");
Actor CrabBot("assets/redAI_spritesheet.png");

void Testing::load()
{
    Test::load();
    // Load
    // TODO
    CrabBot.load();
    Tree.load();
    CrabBot.setPosition(200, 200);
    Tree.sprite.setPosition(500, 500);
    
    
}

void Testing::handleInput()
{
    Test::handleInput();
    // Inputs
    // TODO

    sf::Event curEvent;
    while (m_window.pollEvent(curEvent))
    {
        switch (curEvent.type)
        {
        case sf::Event::Closed:
            m_isQuitting = true;
            break;
        case sf::Event::KeyPressed:
            switch (curEvent.key.code)
            {
            case sf::Keyboard::Escape:
                m_isQuitting = true;
                break;
            case sf::Keyboard::W:
                CrabBot.play(1);
                break;
            case sf::Keyboard::S:
                CrabBot.play(0);
                break;
            case sf::Keyboard::A:
                CrabBot.play(2);
                break;
            case sf::Keyboard::D:
                CrabBot.play(3);
                break;
            default:
                break;
            }
            break;
        case sf::Event::KeyReleased:
            switch (curEvent.key.code)
            {
            case sf::Keyboard::W:
                CrabBot.pause();
                break;
            case sf::Keyboard::S:
                CrabBot.pause();
                break;
            case sf::Keyboard::A:
                CrabBot.pause();
                break;
            case sf::Keyboard::D:
                CrabBot.pause();
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }
    }

    
}

void Testing::update()
{
    Test::update();
    // Update
    // TODO
    std::cout << m_time.asSeconds() << std::endl;
    CrabBot.update(m_time);
}

void Testing::render()
{
    m_window.clear();
    // Draw
    // TODO
    m_window.draw(Tree);
    m_window.draw(CrabBot);
    m_window.display();
}

#endif