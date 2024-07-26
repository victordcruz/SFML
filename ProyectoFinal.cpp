#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>


int main(){

    sf::RenderWindow window(sf::VideoMode(1920,1080),"Proyecto");

    //Figura 1
    sf::RectangleShape jugador1(sf::Vector2f (35.0,160.0));
    jugador1.setFillColor(sf::Color::White);
    jugador1.setPosition(200, 550);

    //Figura 2
    sf::RectangleShape jugador2(sf::Vector2f (35.0,160.0));
    jugador2.setFillColor(sf::Color::White);
    jugador2.setPosition(1700,550);

    //Pelota
    sf::CircleShape ball(25.0f);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(window.getSize().x /2 - ball.getRadius(), window.getSize().y /2 - ball.getRadius());

    //Red
    sf::RectangleShape red0(sf::Vector2f (30,50));
    red0.setFillColor(sf::Color::White);
    red0.setPosition(960, 10);

    sf::RectangleShape red1(sf::Vector2f (30,50));
    red1.setFillColor(sf::Color::White);
    red1.setPosition(960, 80);

    sf::RectangleShape red2(sf::Vector2f (30,50));
    red2.setFillColor(sf::Color::White);
    red2.setPosition(960, 150);

    sf::RectangleShape red3(sf::Vector2f (30,50));
    red3.setFillColor(sf::Color::White);
    red3.setPosition(960, 220);

    sf::RectangleShape red4(sf::Vector2f (30,50));
    red4.setFillColor(sf::Color::White);
    red4.setPosition(960, 290);

    sf::RectangleShape red5(sf::Vector2f (30,50));
    red5.setFillColor(sf::Color::White);
    red5.setPosition(960, 360);

    sf::RectangleShape red6(sf::Vector2f (30,50));
    red6.setFillColor(sf::Color::White);
    red6.setPosition(960, 430);

    sf::RectangleShape red7(sf::Vector2f (30,50));
    red7.setFillColor(sf::Color::White);
    red7.setPosition(960, 500);

    sf::RectangleShape red8(sf::Vector2f (30,50));
    red8.setFillColor(sf::Color::White);
    red8.setPosition(960, 570);

    sf::RectangleShape red9(sf::Vector2f (30,50));
    red9.setFillColor(sf::Color::White);
    red9.setPosition(960, 640);

    sf::RectangleShape red10(sf::Vector2f (30,50));
    red10.setFillColor(sf::Color::White);
    red10.setPosition(960, 710);

    sf::RectangleShape red11(sf::Vector2f (30,50));
    red11.setFillColor(sf::Color::White);
    red11.setPosition(960, 780);

    sf::RectangleShape red12(sf::Vector2f (30,50));
    red12.setFillColor(sf::Color::White);
    red12.setPosition(960, 850);

    sf::RectangleShape red13(sf::Vector2f (30,50));
    red13.setFillColor(sf::Color::White);
    red13.setPosition(960, 920);

    sf::RectangleShape red14(sf::Vector2f (30,50));
    red14.setFillColor(sf::Color::White);
    red14.setPosition(960, 990);

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
        return -1;
    }

    int score1 = 0;
    int score2 = 0;

    sf::Text scoreText1;
    scoreText1.setFont(font);
    scoreText1.setCharacterSize(30);
    scoreText1.setFillColor(sf::Color::White);
    scoreText1.setPosition(window.getSize().x / 4, 20);

    sf::Text scoreText2;
    scoreText2.setFont(font);
    scoreText2.setCharacterSize(30);
    scoreText2.setFillColor(sf::Color::White);
    scoreText2.setPosition(3 * window.getSize().x / 4, 20);

    //Velocidad
    float moveSpeed = 0.2f;

    //Velocidad Pelota
    sf::Vector2f ballVelocity(600.0f,600.0f);

    sf::Clock clock;


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

        }

        float deltaTime = clock.restart().asSeconds();

        //Posicion
        sf::Vector2f position1 = jugador1.getPosition();
        sf::Vector2f position2 = jugador2.getPosition();

        //Movimiento
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(position1.y - moveSpeed >=0){
                jugador1.move(0.0f, -moveSpeed);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (position1.y + jugador1.getSize().y + moveSpeed <= window.getSize().y){
                jugador1.move(0.0f, moveSpeed);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (position2.y - moveSpeed >=0){
                jugador2.move(0.0f, -moveSpeed);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (position2.y + jugador2.getSize().y + moveSpeed <=window.getSize().y){
                jugador2.move(0.0f, moveSpeed);
            }
        }

        //Movimiento pelota
        ball.move(ballVelocity * deltaTime);

        //Colision Pelota
        if(ball.getPosition().y - 25.0f < 0 || ball.getPosition().y + 25.0f > window.getSize().y)
        {
            ballVelocity.y = -ballVelocity.y;
        }

        if (ball.getGlobalBounds().intersects(jugador1.getGlobalBounds()) || ball.getGlobalBounds().intersects(jugador2.getGlobalBounds()))
        {
            ballVelocity.x = -ballVelocity.x;
        }

        if(ball.getPosition().x - 25.0f < 0 || ball.getPosition().x + 25.0f > window.getSize().x)
        {
            score2++;
            ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            ballVelocity = sf::Vector2f (400.0f,400.0f);
        }
        else if (ball.getPosition().x + 25.0f > window.getSize().x) {
            score1++;
            ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            ballVelocity = sf::Vector2f(400.0f, 400.0f);
        }

        scoreText1.setString(std::to_string(score1));
        scoreText2.setString(std::to_string(score2));

        window.clear(sf::Color::Black);
        window.draw(jugador1);
        window.draw(jugador2);
        window.draw(ball);
        window.draw(red0);
        window.draw(red1);
        window.draw(red2);
        window.draw(red3);
        window.draw(red4);
        window.draw(red5);
        window.draw(red6);
        window.draw(red7);
        window.draw(red8);
        window.draw(red9);
        window.draw(red10);
        window.draw(red11);
        window.draw(red12);
        window.draw(red13);
        window.draw(red14);
        window.draw(scoreText1);
        window.draw(scoreText2);
        window.display();
    }
    return 0;
}