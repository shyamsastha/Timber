// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	// Is the bee currently moving?
	bool beeActive = false;

	// How fast can the bee fly
	float beeSpeed = 0.0f;

	// make 3 cloud sprites from 1 texture
	Texture textureCloud;

	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");

	// 3 New sprites withe the same texture
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	// Position the clouds off screen
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 150);
	spriteCloud3.setPosition(0, 300);

	// Are the clouds currently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	// How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	// Variables to control time itself
	Clock clock;

	// Track whether the game is running
	bool paused = true;

	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;

		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		if (!paused)
		{
			Time dt = clock.restart();

			// Setup the bee
			if (!beeActive)
			{

				// How fast is the bee
				srand((int)time(0) * 10);
				beeSpeed = (rand() % 200) + 200;

				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;

			}
			else
				// Move the bee
			{

				spriteBee.setPosition(
					spriteBee.getPosition().x -
					(beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);

				// Has the bee reached the right hand edge of the screen?
				if (spriteBee.getPosition().x < -100)
				{
					// Set it up ready to be a whole new cloud next frame
					beeActive = false;
				}
			}

			// Manage the clouds
			// Cloud 1
			if (!cloud1Active)
			{

				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);

				// How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;


			}
			else
			{

				spriteCloud1.setPosition(
					spriteCloud1.getPosition().x +
					(cloud1Speed * dt.asSeconds()),
					spriteCloud1.getPosition().y);

				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud1.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud1Active = false;
				}
			}
			// Cloud 2
			if (!cloud2Active)
			{

				// How fast is the cloud
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);

				// How high is the cloud
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;


			}
			else
			{

				spriteCloud2.setPosition(
					spriteCloud2.getPosition().x +
					(cloud2Speed * dt.asSeconds()),
					spriteCloud2.getPosition().y);

				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud2.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud2Active = false;
				}
			}

			if (!cloud3Active)
			{

				// How fast is the cloud
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);

				// How high is the cloud
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;


			}
			else
			{

				spriteCloud3.setPosition(
					spriteCloud3.getPosition().x +
					(cloud3Speed * dt.asSeconds()),
					spriteCloud3.getPosition().y);

				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud3.getPosition().x > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud3Active = false;
				}
			}
		}

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last frame
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);

		// Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		// Draw the tree
		window.draw(spriteTree);

		// Drawraw the insect
		window.draw(spriteBee);

		// Show everything we just drew
		window.display();


	}

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
