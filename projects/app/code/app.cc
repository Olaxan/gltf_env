//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "app.h"

#include "asset_srv.h"

#include <chrono>
#include <iostream>
#include <filesystem>
#include <memory>
#include <set>

namespace fs = std::filesystem;

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1200
#define CAMERA_SPEED 0.5f

float randf(float max)
{
	return static_cast<float>(rand()) / static_cast <float>(RAND_MAX) / max;
}

float randf(float min, float max)
{
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));
}

namespace efiilj
{

	application::application()
	: window_(nullptr) { }

	application::~application() = default;

	bool application::open()
	{
		app::open();

		this->window_ = new Display::Window(WINDOW_WIDTH, WINDOW_HEIGHT);

		if (this->window_->Open())
		{

			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);
			glfwSetInputMode(window_->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

			return true;
		}

		return false;
	}

	void application::run()
	{
		asset_server assets;

		assets.open("../res/gltf/Sponza/Sponza.gltf");
	}
}

#undef flase
