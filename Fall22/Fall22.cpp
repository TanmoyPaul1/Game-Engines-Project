/*
	Inherit a class from LeafApp. Override method OnUpdate in it.
	Feed the name of your class to START_LEAF_GAME macro.

*/

#include "Leaf.h"
// include all game files

class Fall22Game : public Leaf::LeafApp
{
public:
	Fall22Game()
	{
		Leaf::LeafWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Leaf::KeyPressedEvent& event) { OnKeyPress(event);  });

		Leaf::LeafWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const Leaf::KeyReleasedEvent& event) { OnKeyRelease(event);  });
	}
	void OnUpdate() override
	{
		//Leaf::Picture pic1{ "Assets/Textures/background.gif" };
		//Leaf::Shader shade{ "Assets/Shaders/defaultLeafVertex.glsl", "Assets/Shaders/defaultLeafFragment.glsl" };

		//Leaf::Renderer::Draw(pic1, 210, 200, 11, shade);

	}

private:
	//Leaf::Picture m_Background{ "Assets/Textures/background.gif " };
	//Leaf::Unit m_Character{ "Assets/Textures/man.png", 1 };
	std::vector<Leaf::Unit> m_Enemies;
	int m_Speed{ 10 };
	int m_Score{ 0 };
	int m_Frames{ 0 };

	// the game objects

	enum class CharState {
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN,
		STAY_STILL
	} m_State{ CharState::STAY_STILL };

	void OnKeyPress(const Leaf::KeyPressedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case LEAF_KEY_LEFT:
			m_State = CharState::MOVE_LEFT;
			break;
		case LEAF_KEY_RIGHT:
			m_State = CharState::MOVE_RIGHT;
			break;
		case LEAF_KEY_UP:
			m_State = CharState::MOVE_UP;
			break;
		case LEAF_KEY_DOWN:
			m_State = CharState::MOVE_DOWN;
			break;
		default:
			m_State = CharState::STAY_STILL;
			break;
		}
	}

	void OnKeyRelease(const Leaf::KeyReleasedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case LEAF_KEY_LEFT:
			m_State = CharState::STAY_STILL;
			break;
		case LEAF_KEY_RIGHT:
			m_State = CharState::STAY_STILL;
			break;
		case LEAF_KEY_UP:
			m_State = CharState::STAY_STILL;
			break;
		case LEAF_KEY_DOWN:
			m_State = CharState::STAY_STILL;
			break;
		default:
			m_State = CharState::STAY_STILL;
			break;
		}
	}

};

START_LEAF_GAME(Fall22Game);
