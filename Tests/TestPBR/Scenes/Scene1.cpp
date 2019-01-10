#include "Scene1.hpp"

#include <Animations/MeshAnimated.hpp>
#include <Helpers/FileSystem.hpp>
#include <Devices/Mouse.hpp>
#include <Lights/Light.hpp>
#include <Materials/MaterialDefault.hpp>
#include <Maths/Visual/DriverConstant.hpp>
#include <Maths/Visual/DriverSlide.hpp>
#include <Meshes/Mesh.hpp>
#include <Meshes/MeshRender.hpp>
#include <Models/Obj/ModelObj.hpp>
#include <Models/Shapes/ModelCube.hpp>
#include <Models/Shapes/ModelSphere.hpp>
#include <Particles/ParticleSystem.hpp>
#include <Renderer/Renderer.hpp>
#include <Scenes/Scenes.hpp>
#include <Scenes/EntityPrefab.hpp>
#include <Shadows/ShadowRender.hpp>
#include <Uis/Uis.hpp>
#include "CameraFps.hpp"
#include "PlayerFps.hpp"

namespace test
{
	static const float UI_SLIDE_TIME = 0.2f;

	Scene1::Scene1() :
		Scene(new CameraFps(), new SelectorJoystick(JOYSTICK_1, 0, 1, {0, 1})),
		m_buttonFullscreen(ButtonKeyboard(KEY_F11)),
		m_buttonCaptureMouse(ButtonCompound::Create<ButtonKeyboard>(KEY_M, KEY_ESCAPE)),
		m_buttonScreenshot(ButtonKeyboard(KEY_F12)),
		m_buttonExit(ButtonKeyboard(KEY_DELETE)),
		m_soundScreenshot(Sound("Sounds/Screenshot.ogg")),
		m_overlayDebug(std::make_unique<OverlayDebug>(Uis::Get()->GetContainer()))
	{
	}

	void Scene1::Start()
	{
		GetPhysics()->SetGravity(Vector3(0.0f, -9.81f, 0.0f));
		GetPhysics()->SetAirDensity(1.0f);

		// Player.
		auto playerObject = GetStructure()->CreateEntity(Transform(Vector3(), Vector3(0.0f, 180.0f, 0.0f)));
	//	playerObject->AddComponent<Rigidbody>(1.0f, 0.4f, Transform::ZERO, Vector3::ZERO, Vector3::ZERO);
	//	playerObject->AddComponent<ColliderCapsule>(0.2f, 1.8f);
		playerObject->AddComponent<PlayerFps>();

		// Skybox.
		auto skyboxObject = GetStructure()->CreateEntity("Objects/SkyboxSnowy/SkyboxSnowy.json", Transform(Vector3(), Vector3(), 1024.0f));

		// Entities.
		auto sun = GetStructure()->CreateEntity(Transform(Vector3(1000.0f, 5000.0f, 4000.0f), Vector3(), 18.0f));
		sun->AddComponent<Light>(Colour::WHITE);

		for (float i = 0.0f; i < 5.0f; i++)
		{
			for (float j = 0.0f; j < 5.0f; j++)
			{
				auto sphere = GetStructure()->CreateEntity(Transform(Vector3(i, j, -6.0f), Vector3(), 0.5f));
				sphere->AddComponent<Mesh>(ModelSphere::Create(30, 30, 1.0f));
				sphere->AddComponent<MaterialDefault>(Colour::WHITE, Texture::Create("Objects/Testing/Diffuse.png"),
					j / 4.0f, i / 4.0f, Texture::Create("Objects/Testing/Material.png"), Texture::Create("Objects/Testing/Normal.png"));
				sphere->AddComponent<MeshRender>();
				sphere->AddComponent<ShadowRender>();

				auto teapot = GetStructure()->CreateEntity(Transform(Vector3(i * 1.6f, j, 6.0f), Vector3(), 0.14f));
				teapot->AddComponent<Mesh>(ModelObj::Create("Objects/Testing/Model_Tea.obj"));
				teapot->AddComponent<MaterialDefault>(Colour::WHITE, nullptr, j / 4.0f, i / 4.0f);
				teapot->AddComponent<MeshRender>();
				teapot->AddComponent<ShadowRender>();
			}
		}

		/*auto dragon = GetStructure()->CreateEntity(Transform(Vector3(6.0f, 0.0f, 0.0f), Vector3(0.0f, 90.0f, 0.0f), 0.4f));
		dragon->AddComponent<Mesh>(ModelObj::Create("Objects/Testing/Model_Dragon.obj"));
		dragon->AddComponent<MaterialDefault>(Colour::WHITE, nullptr, 0.1f, 0.7f);
		dragon->AddComponent<MeshRender>();
		dragon->AddComponent<ShadowRender>();*/
	}

	void Scene1::Update()
	{
		if (m_buttonFullscreen.WasDown())
		{
			Renderer::Get()->GetWindow()->SetFullscreen(!Renderer::Get()->GetWindow()->IsFullscreen());
		}

		if (m_buttonCaptureMouse->WasDown())
		{
			Mouse::Get()->SetCursorHidden(!Mouse::Get()->IsCursorDisabled());
		}

		if (m_buttonScreenshot.WasDown())
		{
			m_soundScreenshot.Play();
			std::string filename = "Screenshots/" + Engine::GetDateTime() + ".png";
			Renderer::Get()->CaptureScreenshot(filename);
		}

		if (m_buttonExit.WasDown())
		{
			Engine::Get()->RequestClose(false);
		}
	}

	bool Scene1::IsPaused() const
	{
		return false;
	}
}
