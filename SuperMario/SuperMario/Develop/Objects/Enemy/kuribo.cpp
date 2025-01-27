#include "kuribo.h"

#include "../../Utility/ResourceManager.h"

#include "DxLib.h"

kuribo* kuribo::instance = nullptr;

kuribo::kuribo():
	move_animation(),
	kuribo_state(eKuriboState::WALK)
{

}

kuribo::~kuribo()
{

}

void kuribo::Initialize()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	move_animation = rm->GetImages("Resource/images/Enemy/kuribo.png", 3, 3, 1, 32, 32);

	image = move_animation[0];

	//�G���[�`�F�b�N
	if (image == -1)
	{
		throw("�N���{�[�̉摜������܂���\n");
	}

	velocity.x = -0.1;

}


void kuribo::Update(float delta_second)
{
	velocity.x = -0.1;
	location += velocity;

	switch (kuribo_state)
	{
	case WALK:
		// �A�j���[�V��������
		AnimeCount(delta_second);
		break;
	case STEP:
		break;
	default:
		break;
	}

}

void kuribo::Draw(const Vector2D& screen_offset) const 
{
	__super::Draw(screen_offset);
}

void kuribo::Finalize()
{

}

void kuribo::AnimeCount(float delta_second)
{
	// �ړ����̃A�j���[�V����
	animation_time += delta_second;
	if (animation_time >= (1.0f / 8.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 2)
		{
			animation_count = 0;
		}
		// �摜�̐ݒ�
		image = move_animation[animation_num[animation_count]];
	}
}

void kuribo::Movement(float delta_second)
{

}

kuribo* kuribo::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new kuribo();
	}
	return instance;
}

void kuribo::SetVelocity(float velo)
{
	location.x -= velo;
}