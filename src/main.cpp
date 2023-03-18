#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
/*
      t
 a---------b
  \       /
 u \     /  v
    \   /
      c
 */
int width = 729; // 3^6
int height = 729;

struct Point {
    int x;
    int y;
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
    sf::RenderWindow window(sf::VideoMode(width, height), "Simple SFML Example");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
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
    window.draw(line, 2, sf::Lines);
    getVertex(triangle.b, triangle.c, line);
    window.draw(line, 2, sf::Lines);
    getVertex(triangle.c, triangle.a, line);
    window.draw(line, 2, sf::Lines);
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
    v[0] = sf::Vertex(sf::Vector2f(first.x, first.y));
    v[1] = sf::Vertex(sf::Vector2f(second.x, second.y));
}
