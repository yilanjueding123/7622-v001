﻿#include "ap_storage_service.h"

MSG_Q_ID StorageServiceQ;
void *storage_service_q_stack[STORAGE_SERVICE_QUEUE_MAX];
static INT8U storage_service_para[STORAGE_SERVICE_QUEUE_MAX_MSG_LEN];

STOR_SERV_PLAYINFO play_info = {0};

extern INT8U usbd_storage_exit;
extern INT8U device_plug_phase;
#ifdef SDC_DETECT_PIN
extern void ap_peripheral_SDC_detect_init(void);
#endif

void task_storage_service_init(void)
{
#ifdef SDC_DETECT_PIN
    ap_peripheral_SDC_detect_init();
#endif
    StorageServiceQ = msgQCreate(STORAGE_SERVICE_QUEUE_MAX, STORAGE_SERVICE_QUEUE_MAX, STORAGE_SERVICE_QUEUE_MAX_MSG_LEN);
    ap_storage_service_init();

    DBG_PRINT(" task_storage_service_init OK!\r\n");
}

void task_storage_service_entry(void *para)
{
    INT32U msg_id;

    task_storage_service_init();
    while(1)
    {
        if (msgQReceive(StorageServiceQ, &msg_id, storage_service_para, STORAGE_SERVICE_QUEUE_MAX_MSG_LEN) == STATUS_FAIL)
        {
            continue;
        }
        switch (msg_id)
        {
        case MSG_STORAGE_SERVICE_STORAGE_CHECK:
            //DBG_PRINT(" s_usbd_pin = 0x%x\r\n",s_usbd_pin);
            if (!s_usbd_pin)
            {
                ap_storage_service_storage_mount();
            }
            break;
        case MSG_STORAGE_SERVICE_USB_IN:
            ap_storage_service_usb_plug_in();
            break;
#if C_AUTO_DEL_FILE == CUSTOM_ON
        case MSG_STORAGE_SERVICE_FREESIZE_CHECK_SWITCH:
            ap_storage_service_freesize_check_switch(storage_service_para[0]);
            break;
        case MSG_STORAGE_SERVICE_FREESIZE_CHECK:
            ap_storage_service_freesize_check_and_del();
            break;
        case MSG_STORAGE_SERVICE_FREE_FILESIZE_CHECK:
            ap_storage_service_free_filesize_check();
            break;

        case MSG_STORAGE_SERVICE_AUTO_DEL_LOCK:
            ap_storage_service_freesize_check_switch(FALSE);
            break;
#endif
        case MSG_STORAGE_SERVICE_VIDEO_FILE_DEL:
            ap_storage_service_file_del(*((INT32U *) storage_service_para));
            break;
        case MSG_STORAGE_SERVICE_FILE_DEL_ALL:
            ap_storage_service_file_delete_all();
            break;

        case MSG_STORAGE_SERVICE_LOCK_ONE:
            ap_storage_service_file_lock_one();
            break;
        case MSG_STORAGE_SERVICE_LOCK_ALL:
            ap_storage_service_file_lock_all();
            break;
        case MSG_STORAGE_SERVICE_UNLOCK_ONE:
            ap_storage_service_file_unlock_one();
            break;
        case MSG_STORAGE_SERVICE_UNLOCK_ALL:
            ap_storage_service_file_unlock_all();
            break;

        case MSG_STORAGE_SERVICE_TIMER_START:			//存储服务
            ap_storage_service_timer_start();
            break;
        case MSG_STORAGE_SERVICE_TIMER_STOP:
		{
			__msg("MSG_STORAGE_SERVICE_TIMER_STOP\n");
            ap_storage_service_timer_stop();
			
            break;
        }
        case MSG_STORAGE_SERVICE_AUD_REQ:
        case MSG_STORAGE_SERVICE_PIC_REQ:
        case MSG_STORAGE_SERVICE_VID_REQ:
			__msg("MSG_STORAGE_SERVICE_VID_REQ\n");
            ap_storage_service_file_open_handle(msg_id);
            break;
#if C_CYCLIC_VIDEO_RECORD == CUSTOM_ON
        case MSG_STORAGE_SERVICE_VID_CYCLIC_REQ:
            ap_storage_service_cyclic_record_file_open_handle(storage_service_para[0]);
            break;
#endif
        case MSG_STORAGE_SERVICE_THUMBNAIL_REQ:
        case MSG_STORAGE_SERVICE_BROWSE_REQ:
            ap_storage_service_play_req(&play_info, *((INT32U *) storage_service_para));
            break;
        case MSG_STORAGE_SERVICE_FORMAT_REQ:
			__msg("MSG_STORAGE_SERVICE_FORMAT_REQ\n");
			app_pripheral_declare(0);
            ap_storage_service_format_req();
			app_pripheral_declare(1);
            break;
        case MSG_FILESRV_FS_READ:
            FileSrvRead((P_TK_FILE_SERVICE_STRUCT)storage_service_para);
            break;

        case MSG_STORAGE_USBD_EXIT:
        case MSG_STORAGE_USBD_PCAM_EXIT:
            device_plug_phase = 0;
            usbd_storage_exit = 1;
            disk_safe_exit(MINI_DVR_STORAGE_TYPE);
            break;

        default:
            break;
        }
    }
}

/*****************************************************************************
 * 函 数 名  : app_pripheral_declare
 * 负 责 人  : Zhibo
 * 创建日期  : 2017年5月3日
 * 函数功能  : 控制马达，LED等外围器件
 * 输入参数  : flag  flag
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void app_pripheral_declare(INT16U flag)
{
	INT32S i = 0;
	
	if(0 == flag)
	{
		__msg("app_pripheral_declare, flag = %d\n", flag);
		for(i = 0; i < 3; i++)
		{
			moto_vibration_on();
			OSTimeDly(25);
			moto_vibration_off();
			OSTimeDly(20);
		}
	}
	else if(1 == flag)
	{
		__msg("app_pripheral_declare, flag = %d\n", flag);
		moto_vibration_on();
		OSTimeDly(128);
		moto_vibration_off();
				
	}
}


