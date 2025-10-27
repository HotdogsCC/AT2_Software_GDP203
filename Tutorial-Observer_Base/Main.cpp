#include "PlayerShip.h"
#include "Asteroid.h"
#include <raylib-cpp.hpp>
#include <time.h>

int main() {
	// Initialisation
	// ------------------------------------------------------------------------------------------
	Vector2 screenSize{ 1920 * 0.75f,1080 * 0.75f };
	raylib::Window window(screenSize.x, screenSize.y, "Tutorial-Observer");
	SetTargetFPS(60);

	srand((unsigned int)time(NULL));

	PlayerShip* player = new PlayerShip("res/spaceship.png", "res/blast.png");

	// . . . Previous code above
	Asteroid::ASTEROID_TEXTURE = new Texture2D(LoadTexture("res/asteroid.png"));
	Asteroid* asteroids[Asteroid::MAX_ASTEROIDS];
	
	float asteroidRate = 2.5f;
	float asteroidTimer = 2.5f;
	// ------------------------------------------------------------------------------------------

	// Main Game Loop
	bool gameEnd = true;
	while (window.ShouldClose() == false) {
		if(gameEnd){
            for (int i = 0; i < Asteroid::MAX_ASTEROIDS; i++) {
                if (i < Asteroid::MAX_ASTEROIDS * 0.1f) {
                    Vector2 randPos = Vector2Scale(Vector2Normalize({ (rand() % 100) - 50.0f, (rand() % 100) - 50.0f }),
                        screenSize.x * 0.5f);
                    Vector2 direc = Vector2Normalize(Vector2Negate(randPos));
                    asteroids[i] = new Asteroid(randPos, direc);
                }
                else {
                    asteroids[i] = nullptr;
                }
            }
            player->reset();
            gameEnd = false;
        }
        
        // Update
		// ------------------------------------------------------------------------------------------
		// Spawn Asteroids
		asteroidTimer -= GetFrameTime();
		if (asteroidTimer <= 0) {
			asteroidTimer += asteroidRate;
			for (int i = 0; i < Asteroid::MAX_ASTEROIDS; i++) {
				if (asteroids[i] == nullptr) {
					Vector2 randPos = Vector2Scale(Vector2Normalize({ (rand() % 100) - 50.0f, (rand() % 100) - 50.0f }),
						screenSize.x * 0.5f);
					Vector2 direc = Vector2Normalize(Vector2Negate(randPos));
					asteroids[i] = new Asteroid(randPos, direc);
					break;
				}
				else if (asteroids[i]->getActive() == false) {
					Vector2 randPos = Vector2Scale(Vector2Normalize({ (rand() % 100) - 50.0f, (rand() % 100) - 50.0f }),
						screenSize.x * 0.5f);
					Vector2 direc = Vector2Normalize(Vector2Negate(randPos));
					asteroids[i]->spawn(randPos, direc);
					break;
				}
			}
		}

		// Call update
		for (int i = 0; i < Asteroid::MAX_ASTEROIDS; i++) {
			if (asteroids[i] != nullptr) {
				asteroids[i]->update();
			}
		}
		player->update();
		// Check Bullet Out of Bounds
		for (int i = 0; i < player->MAX_BULLETS; i++) {
			if (player->m_bullets[i] != nullptr) {
				if (player->m_bullets[i]->getActive() == true) {
					if (player->m_bullets[i]->getPos().x < -screenSize.x || player->m_bullets[i]->getPos().x > screenSize.x ||
						player->m_bullets[i]->getPos().y < -screenSize.y || player->m_bullets[i]->getPos().y > screenSize.y) {
						// Off the screen
						player->m_bullets[i]->setActive(false);
					}
				}
			}
		}

		// . . . Previous code above
		for (int i = 0; i < Asteroid::MAX_ASTEROIDS; i++) {
			if (asteroids[i] != nullptr) {
				if (asteroids[i]->getActive() == true) {
					if (asteroids[i]->getPos().x < -screenSize.x || asteroids[i]->getPos().x > screenSize.x ||
						asteroids[i]->getPos().y < -screenSize.y || asteroids[i]->getPos().y > screenSize.y) {
						// Off the screen
						asteroids[i]->setActive(false);
						continue;
					}

					// Asteroid x Player
					if (asteroids[i]->checkCollision(player) == true) {
						player->destroy();
						gameEnd = true;
					}

					// Asteroid x Asteroid
					for (int j = i + 1; j < Asteroid::MAX_ASTEROIDS; j++) {
						if (asteroids[j] != nullptr) {
							if (asteroids[j]->getActive() == true) {
								if (asteroids[i]->checkCollision(asteroids[j]) == true) {
									asteroids[i]->addVelocity(Vector2Negate(Vector2Scale(asteroids[i]->getVelocity(), 2)));
									asteroids[j]->addVelocity(Vector2Negate(Vector2Scale(asteroids[j]->getVelocity(), 2)));
								}
							}
						}
					}

					// Asteroid x Bullet
					for (int j = 0; j < player->MAX_BULLETS; j++) {
						if (player->m_bullets[j] != nullptr) {
							if (asteroids[i]->checkCollision(player->m_bullets[j]) == true) {
								asteroids[i]->destroy();
								player->m_bullets[j]->setActive(false);
								break;
							}
						}
					}
				}
			}
		}
		// ------------------------------------------------------------------------------------------

		// Draw
		// ------------------------------------------------------------------------------------------
		BeginDrawing();

		window.ClearBackground(BLACK);

		for (int i = 0; i < Asteroid::MAX_ASTEROIDS; i++) {
			if (asteroids[i] != nullptr) {
				asteroids[i]->draw(screenSize);
			}
		}
		player->draw(screenSize);

		EndDrawing();
		// ------------------------------------------------------------------------------------------
	}

	// De-Initialise
	// ------------------------------------------------------------------------------------------
	UnloadTexture(*Asteroid::ASTEROID_TEXTURE);
	delete Asteroid::ASTEROID_TEXTURE;
	Asteroid::ASTEROID_TEXTURE = nullptr;
	for (int i = 0; i < Asteroid::MAX_ASTEROIDS; i++) {
		delete asteroids[i];
	}
	delete player;
	// ------------------------------------------------------------------------------------------
	return 0;
}