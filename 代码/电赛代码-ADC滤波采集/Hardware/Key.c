#include "stm32f10x.h" // Device header
#include "Delay.h"

// ��ʼ���������� (GPIOB12-15���͵�ƽ����)
void Key_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // ��������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

// ��ʼ���������� (GPIOA1-5)
void Key_Init_A(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // ���ó�ʼ״̬
    GPIO_ResetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5); // ��ʼ�ر�
    GPIO_SetBits(GPIOA, GPIO_Pin_2);                             // ��ʼ��
}

// ��ⰴ�� 1 �Ƿ��� (�͵�ƽ����)
uint8_t Key_GetNum1(void)
{
    uint8_t KeyNum = 0;
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0) // ���͵�ƽ
    {
        Delay_ms(20); // ����
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0)
        {
            while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0); // �ȴ������ͷ�
            KeyNum = 1;
        }
    }
    return KeyNum;
}

// ��ⰴ�� 2 �Ƿ��� (�͵�ƽ����)
uint8_t Key_GetNum2(void)
{
    uint8_t KeyNum = 0;
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0)
    {
        Delay_ms(20);
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0)
        {
            while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0);
            KeyNum = 1;
        }
    }
    return KeyNum;
}

// ��ⰴ�� 3 �Ƿ��� (�͵�ƽ����)
uint8_t Key_GetNum3(void)
{
    uint8_t KeyNum = 0;
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
    {
        Delay_ms(20);
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
        {
            while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0);
            KeyNum = 1;
        }
    }
    return KeyNum;
}

// ��ⰴ�� 4 �Ƿ��� (�͵�ƽ����)
uint8_t Key_GetNum4(void)
{
    uint8_t KeyNum = 0;
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
    {
        Delay_ms(20);
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0)
        {
            while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0);
            KeyNum = 1;
        }
    }
    return KeyNum;
}
