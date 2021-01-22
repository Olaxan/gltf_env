#pragma once
//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015-2018 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"

namespace efiilj
{
	class application final : public core::app
	{
	private:

		Display::Window* window_;
		
	public:

		application();
		~application();

		bool open() override;
		void run() override;

	};
}
