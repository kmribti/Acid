#pragma once

#include <Scenes/Scene.hpp>
#include "Uis/Pannable.hpp"

using namespace acid;

namespace test
{
	class Scene1 :
		public Scene
	{
	public:
		Scene1();

		void Start() override;

		void Update() override;

		bool IsPaused() const override;
	private:
		std::unique_ptr<Pannable> m_pannable;
	};
}
