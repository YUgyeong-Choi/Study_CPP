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
	cout << "���� ȭ��" << endl;
	setColor(RED);
	cout << " ! ���� !"; setColor(GRAY);
	cout << "�� �����Ǿ� �ֽ��ϴ�" << endl;
	cout << "�̱��� ����Ʈ" << endl; setColor(YELLOW);
	cout << "1.��������" << endl;
	cout << "2.���� �ҷ�����" << endl; setColor(GRAY);
	cout << "�ƹ� ��ư�̳� �����ּ���" << endl;
	system("pause");

	m_pLogin = new Login;
	m_pLogin->Update();
}

void MainGame::Release()
{
	SAFE_DELETE<Login*>(m_pLogin);
}
