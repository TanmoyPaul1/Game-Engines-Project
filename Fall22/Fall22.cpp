#include "Leaf.h"

#define R Leaf::Unit{ "Assets/Textures/red_ball.png", "red" }
#define B Leaf::Unit{ "Assets/Textures/blue_ball.png", "blue" }
#define G Leaf::Unit{ "Assets/Textures/green_ball.png", "green" }
#define Y Leaf::Unit{ "Assets/Textures/yellow_ball.png", "yellow" }

class Fall22Game : public Leaf::LeafApp
{
public:
	Fall22Game()
	{
		Leaf::LeafWindow::GetWindow()->SetKeyPressedCallback( [this](const Leaf::KeyPressedEvent& event) { OnKeyPress(event);  });
		Leaf::LeafWindow::GetWindow()->SetKeyReleasedCallback( [this](const Leaf::KeyReleasedEvent& event) { OnKeyRelease(event);  });
	}
	void OnUpdate() override
	{
		Leaf::Renderer::Draw(m_Background, 0, 0, 1);
		Leaf::Renderer::Draw(m_Fish, 615, 390, 1);

		// Decoration
		m_RandomCounter++;
		if (m_RandomCounter % 15 == 0) m_toprightBall = randomBall();
		m_toprightBall.DrawPicture(1270, 720, 1);
		if (m_RandomCounter % 15 == 0) m_bottomrightBall = randomBall();
		m_bottomrightBall.DrawPicture(1270, 0, 1);
		if (m_RandomCounter % 15 == 0) m_topleftBall = randomBall();
		m_topleftBall.DrawPicture(0, 720, 1);
		if (m_RandomCounter % 15 == 0) m_bottomleftBall = randomBall();
		m_bottomleftBall.DrawPicture(0, 0, 1);

		m_TopArray.DrawArrayTop(0, 560, 1);
		m_BottomArray.DrawArrayBottom(1270, 160, 1);
		m_LeftArray.DrawArrayLeft(240, 720, 1);
		m_RightArray.DrawArrayRight(1030, 0, 1);

		m_playerBall.DrawPicture(640, 400, 1);

		if (m_Win) Leaf::Renderer::Draw(m_WinImage, 375, 95, 1);
	}

	void Shoot() 
	{
		if (m_State == CharState::SHOOT_LEFT && m_LeftArray.Size() > 4)      m_LeftArray.Insert(m_playerBall, 4, m_Score);
		else if (m_State == CharState::SHOOT_RIGHT && m_RightArray.Size() > 5)      m_RightArray.Insert(m_playerBall, 5, m_Score);
		else if (m_State == CharState::SHOOT_UP && m_TopArray.Size() > 8)      m_TopArray.Insert(m_playerBall, 8, m_Score);
		else if (m_State == CharState::SHOOT_DOWN && m_BottomArray.Size() > 8)      m_BottomArray.Insert(m_playerBall, 8, m_Score);

		if (m_State != CharState::DO_NOTHING) 		m_playerBall = randomBall();

		if ( (m_RightArray.Size() <= 5 && m_TopArray.Size() <= 8 && m_LeftArray.Size() <= 4 && m_BottomArray.Size() <= 8)  || m_Score > 500)  m_Win = true;

		m_playerBall.DrawPicture(640, 400, 1);
	}

private:
	Leaf::Picture m_Background{ "Assets/Textures/background.png " };
	Leaf::Picture m_Fish{ "Assets/Textures/fish.png" };
	Leaf::Picture m_WinImage{ "Assets/Textures/win.png " };

	Leaf::Array m_TopArray{ { R, R, G, R, R, B, R, R, Y, R, R, G, R, R, B, R, R } };
	Leaf::Array m_BottomArray{ { B, B, G, B, B, Y, B, B, R, B, B, G, B, B, Y, B, B } };
	Leaf::Array m_LeftArray{ { G, G, R, G, G, Y, G, G, B, G, G, R, G, G, B, G } };
	Leaf::Array m_RightArray{ { Y, Y, R, Y, Y, G, Y, Y, B, Y, Y, R, Y, B, Y, Y } };

	Leaf::Unit m_toprightBall{ "Assets/Textures/red_ball.png", "red" };
	Leaf::Unit m_topleftBall{ "Assets/Textures/blue_ball.png", "blue" };
	Leaf::Unit m_bottomrightBall{ "Assets/Textures/green_ball.png", "green" };
	Leaf::Unit m_bottomleftBall{ "Assets/Textures/yellow_ball.png", "yellow" };

	Leaf::Unit m_playerBall{ "Assets/Textures/red_ball.png", "red" };

	int m_Score{ 0 };
	bool m_Win{ false };
	int m_RandomCounter{ 0 };


	Leaf::Unit randomBall()
	{
		switch (rand() % 4)
		{
		case 0:
			return R;
		case 1:
			return B;
		case 2:
			return G;
		case 3:
			return Y;
		default:
			return R;
			break;
		}
	}

	enum class CharState {
		SHOOT_LEFT,
		SHOOT_RIGHT,
		SHOOT_UP,
		SHOOT_DOWN,
		DO_NOTHING
	} m_State{ CharState::DO_NOTHING };

	void OnKeyPress(const Leaf::KeyPressedEvent& event)
	{
		if (m_Win) return;

		switch (event.GetKeyCode())
		{
		case LEAF_KEY_LEFT:
			m_State = CharState::SHOOT_LEFT;
			break;
		case LEAF_KEY_RIGHT:
			m_State = CharState::SHOOT_RIGHT;
			break;
		case LEAF_KEY_UP:
			m_State = CharState::SHOOT_UP;
			break;
		case LEAF_KEY_DOWN:
			m_State = CharState::SHOOT_DOWN;
			break;
		default:
			m_State = CharState::DO_NOTHING;
			break;
		}
		
		Shoot();
	}

	void OnKeyRelease(const Leaf::KeyReleasedEvent& event)
	{
		if (m_Win) return;

		switch (event.GetKeyCode())
		{
		case LEAF_KEY_LEFT:
			m_State = CharState::DO_NOTHING;
			break;
		case LEAF_KEY_RIGHT:
			m_State = CharState::DO_NOTHING;
			break;
		case LEAF_KEY_UP:
			m_State = CharState::DO_NOTHING;
			break;
		case LEAF_KEY_DOWN:
			m_State = CharState::DO_NOTHING;
			break;
		default:
			m_State = CharState::DO_NOTHING;
			break;
		}
	}
};

START_LEAF_GAME(Fall22Game);
