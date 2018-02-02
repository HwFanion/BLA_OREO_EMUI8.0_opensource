
/******************************************************************************

				  版权所有 (C), 2014, 华为技术有限公司

 ******************************************************************************
  文 件 名   : Emcom_xengine.h
  版 本 号   : 初稿
  作	者   : z00371705
  生成日期   : 2017年03月13日
  最近修改   :
  功能描述   : 处理快抢技术Kernel层事件
  函数列表   :
  修改历史   :
  1.日	期   : 2017年03月13日
	作	者   : z00371705
	修改内容   : 建立文件

******************************************************************************/
#ifndef __EMCOM_XENGINE_H__
#define __EMCOM_XENGINE_H__
/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

/*****************************************************************************
  2 宏定义
*****************************************************************************/


#define UID_APP                 (10000)
#define UID_INVALID_APP         (0)


#define EMCOM_XENGINE_IsUidValid(uid)	((uid) > 10000)

#define EMCOM_XENGINE_SetAccState(sk, value) \
	{ \
		(sk)->acc_state = (value); \
	}

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

typedef enum {
	EMCOM_XENGINE_ACC_NORMAL = 0,
	EMCOM_XENGINE_ACC_HIGH,
} Emcom_Xengine_acc_state;


/*****************************************************************************
  4 结构定义
*****************************************************************************/

struct Emcom_Xengine_acc_app_info {
	uid_t     lUid; /* The uid of accelerate Application */
	uint16_t  ulAge;
	uint16_t  reverse;
};

/*****************************************************************************
  5 类定义
*****************************************************************************/

/*****************************************************************************
  6 UNION定义
*****************************************************************************/

/*****************************************************************************
  7 全局变量声明
*****************************************************************************/

/*****************************************************************************
  8 函数声明
*****************************************************************************/
void Emcom_Xengine_Init(void);
int Emcom_Xengine_clear(void);
#if defined(CONFIG_PPPOLAC) || defined(CONFIG_PPPOPNS)
bool Emcom_Xengine_Hook_Ul_Stub(struct sock *pstSock);
#endif



void Emcom_Xengine_EvtProc(int32_t event, uint8_t *pdata, uint16_t len);

/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/
#endif
