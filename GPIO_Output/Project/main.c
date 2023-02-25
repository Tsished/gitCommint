/***************************************************************************//**
  �ļ�: main.c
  ����: Zhengyu https://gzwelink.taobao.com
  �汾: V1.0.0
  ʱ��: 202101201
	ƽ̨:MINI-GD32F303RCT6������
	΢�ź�:gzwelink

*******************************************************************************/

#include "gd32f30x.h"
#include "systick.h"
#include <stdio.h>

int main(void)
{
  rcu_ahb_clock_config(RCU_AHB_CKSYS_DIV1);//������Ƶ120M(#define __SYSTEM_CLOCK_120M_PLL_HXTAL           (uint32_t)(120000000),8M�ⲿ����  (#define HXTAL_VALUE    ((uint32_t)8000000))
	systick_config();//1ms systick
	rcu_periph_clock_enable(RCU_AF); //AFʱ��ʹ�� 
	delay_1ms(1000);//�ȴ�1000ms
	gpio_pin_remap_config(GPIO_SWJ_NONJTRST_REMAP, ENABLE);//���ؿ�NJTRST���ŵ�����ͨI/O��
	rcu_periph_clock_enable(RCU_GPIOB);//PBʱ��ʹ��
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4);//PB4���ó����
	//zhiwen add 23 - 02 - 25
	gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4);//PA4���ó����
	gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5);//PA4���ó����
    while(1)
    {
        delay_1ms(1000);//�ȴ�1000ms
        gpio_bit_set(GPIOA, GPIO_PIN_4);//�����
		gpio_bit_set(GPIOA, GPIO_PIN_5);//�����
		gpio_bit_set(GPIOB, GPIO_PIN_4);//�����
        delay_1ms(1000);
		
        gpio_bit_reset(GPIOA, GPIO_PIN_4);//�����
		gpio_bit_reset(GPIOA, GPIO_PIN_5);//�����
		gpio_bit_reset(GPIOB, GPIO_PIN_4);//�����
    }
    return 0;
}
