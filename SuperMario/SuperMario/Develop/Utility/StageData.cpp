#include "StageData.h"

#include "../Utility/ResourceManager.h"
#include "../Utility/InputManager.h"
#include "DxLib.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

//#include "../Objects/GameObjectBase.h"

//#define D_OBJECT_SIZE	(24.0f)			// �ǂ̃T�C�Y

StageData* StageData::instance = nullptr;

/// <summary>
/// �X�e�[�W�f�[�^��ǂݍ���
/// </summary>
void StageData::Load()
{
	//�t�@�C�����J��(.csv)
	FILE* fp = NULL;
	std::string file_name = "Resource/Map/StageMap.csv";
	//�w�肵���t�@�C�����J��
	errno_t result = fopen_s(&fp, file_name.c_str(), "r");

	// �G���[�`�F�b�N
	if (result != 0)
	{
		throw (file_name + "���J���܂���");
	}

	//���P�s�S������悤��
	char buffer[435];

	
	int y = 0;
	ResourceManager* rm = ResourceManager::GetInstance();

	//fgets�Ńt�@�C������P�s�����o��
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{

		int x = 0;   //x���W(��ԍ�)

		//1�s�̃f�[�^��1����������������
		for(char* p = buffer; *p != '\0'; ++p)
		{
			const float block_size = 32.0f;
			if (*p == ',')
			{
				continue;
			}
			if (*p == '\n')
			{
				break;
			}

			Vector2D generate_location = Vector2D((float)x, (float)y) * block_size;
			//�Ώۂ̕��������邩�m�F
			//��
			if (*p == 's')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/sora.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�R�P
			if (*p == 'm')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/mountain_left.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�R�Q
			if (*p == '1')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/mountain_right.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�R�R
			if (*p == '2')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/mountain_surface.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�R4
			if (*p == '3')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/mountain_surface1.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�R5
			if (*p == '4')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/mountain_surface2.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�R�U
			if (*p == '5')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/mountain_up.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�_
			if (*p == 'c')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/cloud1.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�_�P
			if (*p == '6')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/cloud2.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�_�Q
			if (*p == '7')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/cloud3.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�_�R
			if (*p == '8')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/cloud4.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�_�S
			if (*p == '9')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/cloud5.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�_�T
			if (*p == 'a')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/cloud6.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�͂��ςP
			if (*p == 'h')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/ha0.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�͂��ςQ
			if (*p == 'b')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/ha1.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�͂��ςR
			if (*p == 'd')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/ha2.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//��
			if (*p == 'f')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/floor.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}


			//�u���b�N
			if (*p == 'B')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/Block.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�n�e�i�u���b�N
			if (*p == 'H')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/hatena.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�N���{�[
			if (*p == 'C')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/�z�u�f��/�N���{�[.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�L�m�R
			if (*p == 'K')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/�z�u�f��/�L�m�R�z�u.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�΃m�R
			if (*p == 'M')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/�z�u�f��/�΃m�R.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�X�^�[
			if (*p == 'S')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/�z�u�f��/�X�^�[�z�u.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//1up
			if (*p == 'U')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/�z�u�f��/1up�z�u.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�R�C��
			if (*p == 'A')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/�z�u�f��/�R�C���z�u.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�t���O�P
			if (*p == 'F')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/flag.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�t���O�Q
			if (*p == 'G')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/flag_siro.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�|�[��
			if (*p == 'P')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/pole.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'p')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/pole_down.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//��
			if (*p == 'I')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/siro1.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�K�i
			if (*p == 'v')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/kai_block.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//����H
			if (*p == 'w')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/kara_block.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//���y��
			if (*p == 'Y')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/yokodokan_left_down.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'j')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/yokodokan_left_up.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'n')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/yokodokan_middle_down.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'o')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/yokodokan_middle_up.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'q')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/yokodokan_right_down.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'r')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/yokodokan_right_up.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�c�y��
			if (*p == 'D')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/dokan_left_down.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'e')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/dokan_left_up.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'g')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/dokan_right_down.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			if (*p == 'i')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/dokan_right_up.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}


			//�n����
			if (*p == 'T')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/blackblock.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�n����
			if (*p == 't')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/tika_floor.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}
			//�������Ⴂ���
			if (*p == 'V')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Block/bloak_1.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//�������Ⴂ���
			if (*p == 'z')
			{
				//�Ώۂ̕���������΁u�Q�������W�v�Ɓu�摜���v���o����
				int image_sora = rm->GetImages("Resource/images/Item/star.png").at(0);
				DrawGraph((int)generate_location.x + velocity.x, (int)generate_location.y, image_sora, TRUE);
			}

			//���̗�
			x++;

		}

		//���̍s
		y++;
		
	}
	
	
	//�t�@�C�������
	fclose(fp);
}

void StageData::Draw()
{
	
}


StageData* StageData::GetInstance()
{
	if (instance ==nullptr)
	{
		instance = new StageData();
	}
	return instance;
}

void StageData::Update(float delta_second)
{
	if (velocity.x <= -6100)
	{
		velocity.x = -6100;
	}
}

Vector2D StageData::GetVelocity()
{
	return velocity;
}

void StageData::SetVelocity(float velo)
{
	velocity.x -= velo;
}