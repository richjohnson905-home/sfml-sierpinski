#include <SFML/window.hpp>
#include <SFML/graphics.hpp>
#include <SFML/system.hpp>
#include <iostream>
#include <cmath>
/*
      t
 a---------b
  \       /
 u \     /  v
    \   /
      c
 */
unsigned int width = 729; // 3^6
unsigned int height = 729;

struct Point {
    float x;
    float y;
};

struct Triangle {
    Point a;
    Point b;
    Point c;
};

void getVertex(Point first, Point second, sf::Vertex v[2]);
void drawTriangle(sf::RenderWindow& window, Triangle triangle);


int main()
{
    sf::RenderWindow window(sf::VideoMode({width, height}), "Simple SFML Example");

    while (window.isOpen()) {

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);

        Triangle t;
        t.a.x = width / 4;
        t.a.y = height / 2;
        t.b.x = (width / 4) * 3;
        t.b.y = height / 2;
        t.c.x = width / 2;
        t.c.y = height;

        drawTriangle(window, t);
        window.display();
        sf::sleep(sf::milliseconds(100));
    }
    return 0;
}

void drawTriangle(sf::RenderWindow& window, Triangle triangle) {
    if (abs(triangle.b.x - triangle.a.x) < 5) {
        return;
    }
    sf::Vertex v1;
    sf::Vertex v2;
    sf::Vertex line[] = {v1, v2};
    getVertex(triangle.a, triangle.b, line);
    window.draw(line, 2, sf::PrimitiveType::Lines);
    getVertex(triangle.b, triangle.c, line);
    window.draw(line, 2, sf::PrimitiveType::Lines);
    getVertex(triangle.c, triangle.a, line);
    window.draw(line, 2, sf::PrimitiveType::Lines);
    Triangle t;
    t.a.x = triangle.a.x + (triangle.c.x - triangle.a.x) / 2;
    t.a.y = triangle.a.y - (triangle.c.y - triangle.a.y) / 2;
    t.b.x = triangle.b.x - (triangle.b.x - triangle.c.x) / 2;
    t.b.y = triangle.b.y - (triangle.c.y - triangle.b.y) / 2;
    t.c.x = triangle.a.x + (triangle.b.x - triangle.a.x) / 2;
    t.c.y = triangle.a.y;
    drawTriangle(window, t);
    Triangle u;
    u.a.x = triangle.a.x - (triangle.c.x - triangle.a.x) / 2;
    u.a.y = triangle.c.y - (triangle.c.y - triangle.a.y) / 2;
    u.b.x = triangle.a.x + (triangle.c.x - triangle.a.x) / 2;
    u.b.y = triangle.c.y - (triangle.c.y - triangle.a.y) / 2;
    u.c.x = triangle.a.x;
    u.c.y = triangle.c.y;
    drawTriangle(window, u);
    Triangle v;
    v.a.x = triangle.b.x - (triangle.b.x - triangle.c.x) / 2;
    v.a.y = triangle.c.y - (triangle.c.y - triangle.b.y) / 2;
    v.b.x = triangle.b.x + (triangle.b.x - triangle.c.x) / 2;
    v.b.y = triangle.c.y - (triangle.c.y - triangle.b.y) / 2;
    v.c.x = triangle.b.x;
    v.c.y = triangle.c.y;
    drawTriangle(window, v);
}

void getVertex(Point first, Point second, sf::Vertex v[2]) {
    sf::Vertex vertex1;
    vertex1.position = {first.x, first.y};
    vertex1.color = sf::Color::White;
    vertex1.texCoords = {0, 0};
    sf::Vertex vertex2;
    vertex2.position = {second.x, second.y};
    vertex2.color = sf::Color::White;
    vertex2.texCoords = {0, 0};
    v[0] = vertex1;
    v[1] = vertex2;
}