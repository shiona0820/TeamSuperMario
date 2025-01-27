#include "InGameScene.h"

#include "../Utility/ResourceManager.h"
#include "../Utility/InputManager.h"
#include "../Utility/StageData.h"


#include "../Objects/Mario/Player.h"
#include "../Objects/Enemy/kuribo.h"

#include "DxLib.h"
#include <fstream>



InGameScene::InGameScene()
{
	back_ground_BGM = NULL;
}

InGameScene::~InGameScene()
{
	screen_offset.y = D_OBJECT_SIZE * 3.0f;
}

void InGameScene::Initialize()
{

	ResourceManager* rm = ResourceManager::GetInstance();
	//���C��BGM�̓ǂݍ���
	back_ground_BGM = rm->GetSounds("Resource/Sounds/BGM_MarioGround.wav");

	StageData* Stage = StageData::GetInstance();
	Stage->Load();
	
	//�}���I�̕\��
	player = CreateObject<Player>(Vector2D(100, 403));
	//�N���{�[�̕\��
	Kuribo = CreateObject<kuribo>(Vector2D(750, 403));
	//genelate_location = Vector2D(700.0f, 528.0f);

	//UI�̓ǂݍ���
	mario_ui = rm->GetImages("Resource/images/UI/name_mario.png")[0];
	mario_time = rm->GetImages("Resource/images/UI/time.png")[0];
	mario_world = rm->GetImages("Resource/images/UI/world.png")[0];

}

eSceneType InGameScene::Update(const float& delta_second)
{
	StageData* Stage = StageData::GetInstance();
	Stage->Update(delta_second);

	//BGM������Ă��Ȃ��Ƃ��ɍĐ�
	if (CheckSoundMem(back_ground_BGM) != TRUE)
	{
		//���C��BGM�̍Đ�
		PlaySoundMem(back_ground_BGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	//��ʉE�[�������Ă�Ƃ��ɉ�ʓ���������
	if (player->GetLocation().x >= 640 / 2 && player->GetPlayerState() == ePlayerState::MOVE)
	{
		//-45100
		Stage->SetVelocity(player->GetVelocity().x);
		if (Stage->GetVelocity().x <= -5100)
		{
			player->SetScrollEnd();
		}

		//�N���{�[�p
		Kuribo->SetVelocity(player->GetVelocity().x);
	}




	////�I�Չ�ʃX�N���[�����~�߂�
	//if (scroll <= 1000)
	//{
	//	scroll = 1000;

	//	player->SetScrollEnd();
	//}



	// �e�N���X�̍X�V�������Ăяo��
	return __super::Update(delta_second);
}

void InGameScene::Draw() const 
{
	StageData* Stage = StageData::GetInstance();
	Stage->Load();

	//�^�C�g��UI�̕`��
	DrawGraph(340, 10, mario_world, TRUE);
	DrawGraph(480, 10, mario_time, TRUE);
	DrawGraph(100, 10, mario_ui, TRUE);

	__super::Draw();

}

void InGameScene::Finalize()
{
	//�e�N���X�̏I�����������Ăяo��
	__super::Finalize();
}

const eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType ::in_game;
}