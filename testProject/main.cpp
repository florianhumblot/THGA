#include "Collision.h"
#include "SFML/Graphics.hpp"
#include "Windows.h"
#include <cmath>
#include <iostream>
using namespace std;
using namespace sf;

typedef sf::Vector2f v2;
typedef sf::Vector2i v2i;


int main() {
  RenderWindow window(VideoMode(1600, 900, 32), "APPLICATION");
  sf::View main_camera;
  window.setVerticalSyncEnabled(true);

  float dt = 1.f / 60.f;   // fixed physics step
  float accumulator = 0.f; // total to consume from
  float ft = 0.0f;         // frame time
  sf::Clock timer;

  sf::Texture tex;
  Collision::CreateTextureAndBitmask(tex, "Assets/background.png");
  Sprite bg(tex);

  sf::Texture tex2;
  Collision::CreateTextureAndBitmask(tex2, "Assets/gradient.png");
  Sprite bg2(tex2);

  sf::Texture char_alpha;
  sf::Texture char_alpha_invert;
  Collision::CreateTextureAndBitmask(char_alpha, "Assets/char_alpha.png");
  Collision::CreateTextureAndBitmask(char_alpha_invert,
                                     "Assets/char_alpha_invert.png");

  sf::Sprite player;
  player.setPosition(v2(100, 100));
  player.setTexture(char_alpha);
  player.setScale(v2(0.15, 0.15));

  main_camera.setCenter(player.getPosition());
  main_camera.setSize(1600, 900);

  sf::Sprite background;
  background.setTexture(tex2);

  sf::Sprite ground;
  ground.setTexture(tex);

  v2 pos = player.getPosition();
  auto velocity = v2(0, 0);
  auto gravity = v2(0, 1);

  while (window.isOpen()) {
    ft = timer.getElapsedTime().asSeconds();
    timer.restart();
    accumulator += ft;
    std::cout << "acc: " << accumulator << std::endl;
    while (accumulator >= dt) {
      // do game stuff
      v2 current_pos = player.getPosition();

      Event ev;
      while (window.pollEvent(ev)) {
        switch (ev.type) {
        case Event::Closed: {
          window.close();
          break;
        }
      }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
          window.close();
        }
        if (ev.type == ev.KeyReleased && ev.key.code == sf::Keyboard::Space) {
          velocity.y = -14;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.setTexture(char_alpha);
        velocity.x = 8;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.setTexture(char_alpha_invert);
        velocity.x = -8;
      } else {
        velocity.x = 0;
      }

      // move on x
      player.move(v2(velocity.x, 0));

      // if we collide, we know it's on the x axis, so we move back and set our
      // x velocity to 0
      if (Collision::PixelPerfectTest(player, ground)) {
        player.move(v2(-velocity.x, 0));
        velocity.x = 0;
      }

      player.move(v2(0, velocity.y));

      if (Collision::PixelPerfectTest(player, ground) && velocity.y > 0) {
        while (Collision::PixelPerfectTest(player, ground)) {
          player.move(v2(0, -0.5));
        }
        velocity.y = 0;
      } else if (Collision::PixelPerfectTest(player, ground) &&
                 velocity.y < 0) {
        while (Collision::PixelPerfectTest(player, ground)) {
          player.move(v2(0, 0.5));
        }
        velocity.y = 0;
      } else {
        velocity += gravity;
      }
      accumulator -= dt;
    }

    if (player.getPosition().y > 4000)
      player.setPosition(v2(100, 100));

    // draw everything
    window.clear();

    window.draw(background);
    window.draw(player);
    window.draw(ground);

    auto center = Collision::GetSpriteCenter(player);
    main_camera.setCenter(center);
    window.setView(main_camera);
    window.display();
  }

  return 0;
}