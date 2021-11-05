#ifndef QUAD_HPP
#define QUAD_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <vector>

template <typename T>
class Node
{
private:
    T m_data;

public:
    float x;
    float y;

    Node()
    {
        x = 0;
        y = 0;
    }

    Node(const T &_data)
    {
        m_data = _data;
        x = 0;
        y = 0;
    }

    Node(const T &_data, float _x, float _y)
    {
        m_data = _data;
        x = _x;
        y = _y;
    }

    Node(const T &_data, sf::Vector2f _pos)
    {
        m_data = _data;
        x = _pos.x;
        y = _pos.y;
    }

    Node(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    Node(sf::Vector2f _pos)
    {
        x = _pos.x;
        y = _pos.y;
    }

    ~Node()
    {
    }

    void data(const T &_data)
    {
        m_data = _data;
    }

    T &data()
    {
        return m_data;
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &_qNode)
    {
        os << "[" << _qNode.x << ", " << _qNode.y << "]\n";
        return os;
    }
};

template <typename T>
class Quad 
{
public:
    
    float left;
    float top;
    float right;
    float bottom;
    
    Node<T> *node;
    Quad *tLQuad, *tRQuad, *bLQuad, *bRQuad;

    std::string getTabs(int count)
    {
        std::string retStr = "";
        for (int i = 0; i < count; i++)
        {
            retStr += "\t";
        }
        return retStr;
    }

    void printQuads(int count = 1)
    {
        if (count == 1)
        {
            std::cout << "root -->";
        }
        std::cout << "{ (" << left << ", " << top << ") \\_ (" << right << ", " << bottom << ") }";
        if (node == nullptr)
        {
            std::cout << "[/]\n";
            if (tLQuad != nullptr)
            {
                std::cout << getTabs(count) << "TL -->";
                tLQuad->printQuads(count + 1);
            }
            if (tRQuad != nullptr)
            {
                std::cout << getTabs(count) << "TR -->";
                tRQuad->printQuads(count + 1);
            }
            if (bLQuad != nullptr)
            {
                std::cout << getTabs(count) << "BL -->";
                bLQuad->printQuads(count + 1);
            }
            if (bRQuad != nullptr)
            {
                std::cout << getTabs(count) << "BR -->";
                bRQuad->printQuads(count + 1);
            }
        }
        else
        {
            std::cout << *node;
            if (tLQuad != nullptr)
            {
                std::cout << getTabs(count) << "TL -->";
                tLQuad->printQuads(++count);
            }
            if (tRQuad != nullptr)
            {
                std::cout << getTabs(count) << "TR -->";
                tRQuad->printQuads(++count);
            }
            if (bLQuad != nullptr)
            {
                std::cout << getTabs(count) << "BL -->";
                bLQuad->printQuads(++count);
            }
            if (bRQuad != nullptr)
            {
                std::cout << getTabs(count) << "BR -->";
                bRQuad->printQuads(++count);
            }
        }
    }

    Quad()
    {
        left, top, right, bottom = 0;
        node = nullptr;
        tLQuad = nullptr;
        tRQuad = nullptr;
        bLQuad = nullptr;
        bRQuad = nullptr;
    }

    Quad(float _left, float _top, float _right, float _bottom) 
    {
        left = _left;
        top = _top;
        right = _right;
        bottom = _bottom;
        node = nullptr;
        tLQuad = nullptr;
        tRQuad = nullptr;
        bLQuad = nullptr;
        bRQuad = nullptr;
    }

    Quad(sf::FloatRect _quadRect)
    {
        left = _quadRect.left;
        top = _quadRect.top;
        right = _quadRect.left + _quadRect.width;
        bottom = _quadRect.top + _quadRect.height;
        node = nullptr;
        tLQuad = nullptr;
        tRQuad = nullptr;
        bLQuad = nullptr;
        bRQuad = nullptr;
    }

    ~Quad()
    {
        if (node) 
            delete node;
        if (tLQuad) 
        {
            delete tLQuad;
        }
        if (tRQuad) 
        {
            delete tRQuad;
        }
        if (bLQuad) 
        {
            delete bLQuad;
        }
        if (bRQuad) 
        {
            delete bRQuad;
        }
    }
    
    bool contains(sf::Vector2f point)
    {
        return (left <= point.x &&
                right >= point.x &&
                top <= point.y &&
                bottom >= point.y);
    }

    bool contains(float _x, float _y)
    {
        return (left <= _x &&
                right >= _x &&
                top <= _y &&
                bottom >= _y);
    }

    void insert(Node<T> *_node)
    {
        if (_node == nullptr)
        {
            return;
        }

        if (!contains(_node->x, _node->y))
        {
            return;
        }

        if (right - left <= 1 && bottom - top <= 1)
        {
            if (node == nullptr)
            {
                node = _node;
                std::cout << "inserted" << std::endl;
            }
            return;
        }

        if (_node->y <= top + ((bottom - top) / 2))
        { // T
            if (_node->x <= left + ((right - left) / 2))
            { // L
                if (tLQuad == nullptr)
                {
                    tLQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(left, top),
                            sf::Vector2f((right - left) / 2, (bottom - top) / 2)));
                }
                tLQuad->insert(_node);
            }
            else
            { // R
                if (tRQuad == nullptr)
                {
                    tRQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(left + ((right - left) / 2), top),
                            sf::Vector2f((right - left) / 2, (bottom - top) / 2)));
                }
                tRQuad->insert(_node);
            }
        }
        else
        { // B
            if (_node->x <= left + ((right - left) / 2))
            { // L
                if (bLQuad == nullptr)
                {
                    bLQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(left, top + ((bottom - top) / 2)),
                            sf::Vector2f((right - left) / 2, (bottom - top) / 2)));
                }
                bLQuad->insert(_node);
            }
            else
            { // R
                if (bRQuad == nullptr)
                {
                    bRQuad = new Quad(
                        sf::FloatRect(
                            sf::Vector2f(left + ((right - left) / 2), top + ((bottom - top) / 2)),
                            sf::Vector2f((right - left) / 2, (bottom - top) / 2)));
                }
                bRQuad->insert(_node);
            }
        }
    }

    std::vector<Node<T> *> search(float _left, float _top, float _right, float _bottom)
    {
        std::vector<Node<T> *> results;
        if (_bottom < _top) 
        {
            float t = _bottom;
            _bottom = _top;
            _top = t;
        }
        if (_right < _left)
        {
            float t = _left;
            _left = _right;
            _right = t;
        }

        if (_bottom < top)
            return results;
        if (_top > bottom)
            return results;
        if (_right < left)
            return results;
        if (_left > right)
            return results;


        if (_top <= top) 
            _top = top;
        if (_left <= left) 
            _left = left;
        if (_right >= right)
            _right = right;
        if (_bottom >= bottom)
            _bottom = bottom;

        if (node == nullptr) 
        {
            if (tLQuad != nullptr)
            {
                std::vector<Node<T> *> tLResults = tLQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(tLResults), std::end(tLResults));
            }
            if (tRQuad != nullptr)
            {
                std::vector<Node<T> *> tRResults = tRQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(tRResults), std::end(tRResults));
            }
            if (bLQuad != nullptr)
            {
                std::vector<Node<T> *> bLResults = bLQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(bLResults), std::end(bLResults));
            }
            if (bRQuad != nullptr)
            {
                std::vector<Node<T> *> bRResults = bRQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(bRResults), std::end(bRResults));
            }
        }
        else
        {
            if (node->x >= _left &&
                node->x <= _right &&
                node->y >= _top &&
                node->y <= _bottom)
            {
                results.push_back(node);
            }
            if (tLQuad != nullptr)
            {
                std::vector<Node<T> *> tLResults = tLQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(tLResults), std::end(tLResults));
            }
            if (tRQuad != nullptr)
            {
                std::vector<Node<T> *> tRResults = tRQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(tRResults), std::end(tRResults));
            }
            if (bLQuad != nullptr)
            {
                std::vector<Node<T> *> bLResults = bLQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(bLResults), std::end(bLResults));
            }
            if (bRQuad != nullptr)
            {
                std::vector<Node<T> *> bRResults = bRQuad->search(_left, _top, _right, _bottom);
                results.insert(std::end(results), std::begin(bRResults), std::end(bRResults));
            }
        }
        return results;
    }
};

#endif