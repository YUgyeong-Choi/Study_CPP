#include "MainGame.h"
#include "Define.h"
#include "pch.h"
#include "Color.h"

MainGame::MainGame():m_pLogin(nullptr)
{}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Update()
{
	cout << " .___________._______ ___   ___. ___________..______.      ______     _______ " << endl;
	cout << "|           ||   ____|\\  \\ /  / |           ||   _  \\     |   _  \\   /  _____|" << endl;
	cout << "`---|  |----`|  |__    \\  V  /  `---|  |----`|  |_)  |    |  |_)  | |  |  __  " << endl;
	cout << "    |  |     |   __|    >   <       |  |     |      /     |   ___/  |  | |_ | " << endl;
	cout << "    |  |     |  |____  /  .  \\      |  |     |  |\\  \\----.|  |      |  |__| | " << endl;
	cout << "    |__|     |_______|/__/ \\__\\     |__|     | _| `._____|| _|       \\______| " << endl;
                                                                              

	setColor(RED);
	cout << " ! 전사 !"; setColor(GRAY);
	cout << "만 구현되어 있습니다" << endl;
	system("pause");

	m_pLogin = new Login;
	m_pLogin->Update();
}

void MainGame::Release()
{
	SAFE_DELETE<Login*>(m_pLogin);
}
