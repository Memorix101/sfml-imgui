#include "stdafx.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ImGui test!");
	ImGui::SFML::SetWindow(window);
	ImGui::SFML::InitImGui();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed) window.close();
		}
		window.clear(sf::Color::Black); // to prevent clipping ;)
		ImGui::SFML::UpdateImGui();
		static bool ui = true;
		if (ImGui::Begin("Test!", &ui, ImVec2(10, 10)))
		{
			ImGui::Text("Hello, world!");
		}
		ImGui::End();
		ImGui::Render();
		window.display();
	}
	return 0;
}